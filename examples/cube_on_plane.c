#include "renderer/core/renderer.h"
#include "renderer/lighting/light.h"
#include "renderer/materials/material.h"
#include "renderer/math/vector.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void error_exit(const char* msg, GLRenderer* renderer) {
    fprintf(stderr, "Error: %s - %s\n", msg, gl_renderer_get_error(renderer));
    gl_renderer_destroy(renderer);
    exit(1);
}

int main(void) {
    // Create default configuration
    GLRendererConfig config = gl_renderer_config_default();
    config.window_title = "Cube on Plane Demo";
    config.window_width = 1024;
    config.window_height = 764;
    config.vsync_enabled = true;
    config.resizable = true;

    // Create and initialize renderer
    GLRenderer* renderer = gl_renderer_create(&config);
    if (!renderer) {
        fprintf(stderr, "Failed to create renderer\n");
        return 1;
    }

    GLRendererError err = gl_renderer_init(renderer, &config);
    if (err != GL_RENDERER_SUCCESS) {
        error_exit("Failed to initialize renderer", renderer);
    }

    // Setup 3D rendering
    gl_renderer_set_3d_projection(renderer, 45.0f, 0.1f, 100.0f);

    // Setup camera
    Vec3 eye = vec3_create(5.0f, 4.0f, 5.0f);  // Position for good shadow view
    Vec3 target = vec3_create(0.0f, 0.0f, 0.0f);
    Vec3 up = vec3_create(0.0f, 1.0f, 0.0f);
    gl_renderer_set_camera(renderer, eye, target, up);

    // Add spotlight from above
    Light spot_light = create_spot_light(
        vec3_create(3.0f, 5.0f, 3.0f),     // position - above and to the side
        vec3_create(-0.5f, -1.0f, -0.5f),  // direction - pointing at cube
        vec3_create(1.0f, 0.95f, 0.8f),    // warm white color
        1.2f,                              // higher intensity for better shadows
        15.0f,                             // range
        45.0f                              // spot angle in degrees
    );
    gl_renderer_add_light(renderer, spot_light);

    // Add dim ambient light
    Light ambient_light = create_directional_light(
        vec3_create(0.0f, -1.0f, 0.0f),    // direction - from above
        vec3_create(0.2f, 0.2f, 0.3f),     // slight blue tint for ambient
        0.3f                               // low intensity for ambient
    );
    gl_renderer_add_light(renderer, ambient_light);

    // Light gray plane material with good shadow reception
    Material plane_material = material_create(
        vec3_create(0.1f, 0.1f, 0.1f),  // low ambient to show shadows better
        vec3_create(0.9f, 0.9f, 0.9f),  // bright diffuse to show shadows
        vec3_create(0.1f, 0.1f, 0.1f),  // low specular to not distract
        16.0f                           // medium shininess
    );

    // Create a blue material for the cube
    Material cube_material = material_create(
        vec3_create(0.1f, 0.1f, 0.2f),  // slight blue ambient
        vec3_create(0.2f, 0.3f, 0.8f),  // blue diffuse
        vec3_create(0.8f, 0.8f, 1.0f),  // white-blue specular
        64.0f                           // high shininess for sharp highlights
    );

    float cube_rotation = 0.0f;

    // Main loop
    while (gl_renderer_is_running(renderer)) {
        gl_renderer_process_events(renderer);
        gl_renderer_begin_frame(renderer);

        // Draw rotating cube
        cube_rotation += 0.02f;
        gl_renderer_draw_cube(
            renderer,
            vec3_create(0.0f, 0.0f, 0.0f),              // position
            2.0f,                                       // size
            vec3_create(0.0f, cube_rotation, 0.0f),     // rotation
            cube_material
        );

        // Draw ground plane
        gl_renderer_draw_plane(
            renderer,
            vec3_create(0.0f, -1.0f, 0.0f),  // position
            vec3_create(0.0f, 1.0f, 0.0f),   // normal
            10.0f,                           // size
            plane_material
        );

        gl_renderer_end_frame(renderer);
    }

    gl_renderer_destroy(renderer);
    return 0;
}