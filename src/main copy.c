#include <stdio.h>
#include <stdlib.h>

#include "renderer.h"

static void error_exit(const char* msg, GLRenderer* renderer) {
    fprintf(stderr, "Error: %s - %s\n", msg, gl_renderer_get_error(renderer));
    gl_renderer_destroy(renderer);
    exit(1);
}

int main(void) {
    // Create default configuration
    GLRendererConfig config = gl_renderer_config_default();
    config.window_title     = "3D Scene Demo";
    config.window_width     = 1024;
    config.window_height    = 768;
    config.vsync_enabled    = true;
    config.resizable        = true;

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
    Vec3 eye    = vec3_create(3.0f, 3.0f, 5.0f);
    Vec3 target = vec3_create(0.0f, 0.0f, 0.0f);
    Vec3 up     = vec3_create(0.0f, 1.0f, 0.0f);
    gl_renderer_set_camera(renderer, eye, target, up);

    // Add a directional light
    Light mainLight
        = {.type      = LIGHT_DIRECTIONAL,
           .direction = vec3_create(-1.0f, -1.0f, -1.0f),
           .color     = vec3_create(1.0f, 1.0f, 1.0f),
           .intensity = 1.0f};
    gl_renderer_add_light(renderer, mainLight);

    // Create materials
    Material planeMaterial = material_create(
        vec3_create(0.2f, 0.2f, 0.2f),  // ambient
        vec3_create(0.5f, 0.5f, 0.5f),  // diffuse
        vec3_create(0.1f, 0.1f, 0.1f),  // specular
        32.0f                           // shininess
    );

    // Create a bright material for the cube
    Material cubeMaterial = material_create(
        vec3_create(0.2f, 0.2f, 0.2f),  // ambient
        vec3_create(0.8f, 0.8f, 0.8f),  // diffuse
        vec3_create(1.0f, 1.0f, 1.0f),  // specular
        32.0f                           // shininess
    );

    float cubeRotation = 0.0f;

    // Main loop
    while (gl_renderer_is_running(renderer)) {
        gl_renderer_process_events(renderer);
        gl_renderer_begin_frame(renderer);

        gl_renderer_draw_cube(
            renderer,
            vec3_create(0.0f, 0.0f, 0.0f),          // position
            1.0f,                                   // size
            vec3_create(0.0f, cubeRotation, 0.0f),  // rotation
            cubeMaterial);

        // Draw rotating cube
        cubeRotation += 0.01f;

        // Draw plane
        gl_renderer_draw_plane(
            renderer,
            vec3_create(0.0f, -1.0f, 0.0f),  // position
            vec3_create(0.0f, 1.0f, 0.0f),   // normal
            10.0f,                           // size
            planeMaterial);

        gl_renderer_end_frame(renderer);
    }

    gl_renderer_destroy(renderer);
    return 0;
}
