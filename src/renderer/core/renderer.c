#include "renderer/core/renderer.h"

#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "renderer/lighting/light.h"
#include "renderer/materials/material.h"
#include "renderer/objects/primitive_cache.h"
#include "renderer/shaders/shader_library.h"

// Internal renderer structure
struct GLRenderer {
    SDL_Window* window;
    SDL_GLContext gl_context;
    const char* glsl_version;
    bool running;
    char error_message[256];

    // Core components
    RenderState render_state;
    ShaderLibrary shader_library;
    PrimitiveCache primitive_cache;

    // 3D rendering state
    Mat4 projection;
    Mat4 view;
    Vec3 camera_position;

    // Lighting
    Light lights[8];  // Support up to 8 lights
    int light_count;
};

// Internal functions
static bool init_sdl(GLRenderer* renderer, const GLRendererConfig* config) {
    // Initialize SDL Cosmo
    printf("Initializing SDL Cosmo...\n");
    if (SDL_CosmoInit() != 0) {
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "SDL Cosmo Init failed: %s",
            SDL_CosmoGetError());
        SDL_DestroyWindow(renderer->window);
        SDL_Quit();
        return false;
    }
    printf("SDL Cosmo Init succeeded\n");
    printf("Calling SDL_Init(SDL_INIT_VIDEO)...\n");
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        const char* error = SDL_GetError();
        printf("SDL_Init failed with error: %s\n", error);
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "SDL Init failed: %s",
            error);
        return false;
    }
    printf("SDL_Init succeeded\n");

    renderer->glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_PROFILE_MASK,
        SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    printf("Creating window...\n");
    Uint32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    if (config && config->resizable) {
        window_flags |= SDL_WINDOW_RESIZABLE;
    }

    const char* title = config ? config->window_title : "PGFX Window";
    int width         = config ? config->window_width : 800;
    int height        = config ? config->window_height : 600;

    renderer->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        window_flags);

    if (!renderer->window) {
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "Failed to create window: %s",
            SDL_GetError());
        return false;
    }

    // Create OpenGL context
    printf("Creating OpenGL context...\n");
    renderer->gl_context = SDL_GL_CreateContext(renderer->window);
    if (!renderer->gl_context) {
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "Failed to create OpenGL context: %s",
            SDL_GetError());
        return false;
    }
    printf("OpenGL context created\n");

    // Enable VSync if requested
    SDL_GL_SetSwapInterval(config->vsync_enabled ? 1 : 0);

    return true;
}

static bool init_gl3w(GLRenderer* renderer) {
    printf("Initializing GL3W...\n");
    GL3W_init();
    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    printf("OpenGL Version: %d.%d\n", major, minor);
    return true;
}

// Public API implementation
GLRenderer* gl_renderer_create(const GLRendererConfig* config) {
    printf("Creating renderer...\n");
    GLRenderer* renderer = calloc(1, sizeof(GLRenderer));
    if (!renderer) {
        printf("Failed to allocate renderer memory!\n");
        return NULL;
    }

    renderer->running = true;

    // Initialize render state with defaults
    printf("Creating default render state...\n");
    renderer->render_state = render_state_create_default();
    printf("Default render state created.\n");

    return renderer;
}

GLRendererError gl_renderer_init(
    GLRenderer* renderer,
    const GLRendererConfig* config) {
    printf("Initializing renderer...\n");
    if (!renderer) {
        printf("Renderer pointer is NULL!\n");
        return GL_RENDERER_ERROR_MEMORY;
    }

    // Initialize SDL and create window
    printf("Initializing SDL...\n");
    if (!init_sdl(renderer, config)) {
        printf("SDL initialization failed: %s\n", renderer->error_message);
        return GL_RENDERER_ERROR_SDL_INIT;
    }
    printf("SDL initialized successfully.\n");

    // Initialize GL3W
    printf("Initializing GL3W...\n");
    if (!init_gl3w(renderer)) {
        printf("GL3W initialization failed\n");
        SDL_GL_DeleteContext(renderer->gl_context);
        SDL_DestroyWindow(renderer->window);
        SDL_Quit();
        return GL_RENDERER_ERROR_GL3W_INIT;
    }
    printf("GL3W initialized successfully.\n");

    // Initialize shader library
    printf("Initializing shader library...\n");
    if (!shader_library_init(&renderer->shader_library)) {
        printf("Shader library initialization failed!\n");
        SDL_GL_DeleteContext(renderer->gl_context);
        SDL_DestroyWindow(renderer->window);
        SDL_Quit();
        return GL_RENDERER_ERROR_SHADER_COMPILATION;
    }
    printf("Shader library initialized successfully.\n");

    // Initialize primitive cache
    printf("Initializing primitive cache...\n");
    if (!primitive_cache_init(&renderer->primitive_cache)) {
        printf("Primitive cache initialization failed!\n");
        shader_library_destroy(&renderer->shader_library);
        SDL_GL_DeleteContext(renderer->gl_context);
        SDL_DestroyWindow(renderer->window);
        SDL_Quit();
        return GL_RENDERER_ERROR_MEMORY;
    }
    printf("Primitive cache initialized successfully.\n");

    return GL_RENDERER_SUCCESS;
}

void gl_renderer_begin_frame(GLRenderer* renderer) {
    if (!renderer) return;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    render_state_apply(&renderer->render_state);
}

void gl_renderer_end_frame(GLRenderer* renderer) {
    if (!renderer) return;
    SDL_GL_SwapWindow(renderer->window);
}

bool gl_renderer_is_running(GLRenderer* renderer) {
    return renderer && renderer->running;
}

void gl_renderer_process_events(GLRenderer* renderer) {
    if (!renderer) return;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                renderer->running = false;
                break;
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    glViewport(0, 0, event.window.data1, event.window.data2);
                }
                break;
        }
    }
}

void gl_renderer_set_3d_projection(
    GLRenderer* renderer,
    float fov,
    float near,
    float far) {
    if (!renderer) return;

    int width, height;
    SDL_GetWindowSize(renderer->window, &width, &height);
    float aspect = (float)width / (float)height;

    renderer->projection = mat4_perspective(fov, aspect, near, far);
}

void gl_renderer_set_camera(
    GLRenderer* renderer,
    Vec3 eye,
    Vec3 target,
    Vec3 up) {
    if (!renderer) return;

    renderer->camera_position = eye;
    renderer->view            = mat4_look_at(eye, target, up);
}

int gl_renderer_add_light(GLRenderer* renderer, Light light) {
    if (!renderer || renderer->light_count >= 8) return -1;

    renderer->lights[renderer->light_count] = light;
    return renderer->light_count++;
}

void gl_renderer_draw_cube(
    GLRenderer* renderer,
    Vec3 position,
    float size,
    Vec3 rotation,
    Material material) {
    if (!renderer) return;

    Shader* shader
        = shader_library_get(&renderer->shader_library, SHADER_TYPE_DEFAULT_3D);
    if (!shader) return;

    shader_use(shader);

    // Create model matrix
    Mat4 model = mat4_identity();

    // Apply transformations
    Mat4 scale = mat4_scale(size, size, size);
    Mat4 rotX  = mat4_rotation_x(rotation.x);
    Mat4 rotY  = mat4_rotation_y(rotation.y);
    Mat4 rotZ  = mat4_rotation_z(rotation.z);
    Mat4 trans = mat4_translation(position.x, position.y, position.z);

    // Combine transformations
    model = mat4_multiply(
        trans,
        mat4_multiply(rotY, mat4_multiply(rotX, mat4_multiply(rotZ, scale))));

    // Set uniforms
    shader_set_mat4(shader, "model", model.elements);
    shader_set_mat4(shader, "view", renderer->view.elements);
    shader_set_mat4(shader, "projection", renderer->projection.elements);

    shader_set_vec3(
        shader,
        "material.ambient",
        material.ambient.x,
        material.ambient.y,
        material.ambient.z);
    shader_set_vec3(
        shader,
        "material.diffuse",
        material.diffuse.x,
        material.diffuse.y,
        material.diffuse.z);
    shader_set_vec3(
        shader,
        "material.specular",
        material.specular.x,
        material.specular.y,
        material.specular.z);
    shader_set_float(shader, "material.shininess", material.shininess);

    shader_set_vec3(
        shader,
        "viewPos",
        renderer->camera_position.x,
        renderer->camera_position.y,
        renderer->camera_position.z);

    // Set lights
    shader_set_int(shader, "lightCount", renderer->light_count);
    for (int i = 0; i < renderer->light_count; i++) {
        char buf[64];
        snprintf(buf, sizeof(buf), "lights[%d].type", i);
        shader_set_int(shader, buf, renderer->lights[i].type);

        snprintf(buf, sizeof(buf), "lights[%d].position", i);
        shader_set_vec3(
            shader,
            buf,
            renderer->lights[i].position.x,
            renderer->lights[i].position.y,
            renderer->lights[i].position.z);

        snprintf(buf, sizeof(buf), "lights[%d].direction", i);
        shader_set_vec3(
            shader,
            buf,
            renderer->lights[i].direction.x,
            renderer->lights[i].direction.y,
            renderer->lights[i].direction.z);

        snprintf(buf, sizeof(buf), "lights[%d].color", i);
        shader_set_vec3(
            shader,
            buf,
            renderer->lights[i].color.x,
            renderer->lights[i].color.y,
            renderer->lights[i].color.z);

        snprintf(buf, sizeof(buf), "lights[%d].intensity", i);
        shader_set_float(shader, buf, renderer->lights[i].intensity);
    }

    // Get and draw cube
    Primitive* cube = primitive_cache_get_cube(&renderer->primitive_cache);
    if (cube) {
        printf(
            "Drawing cube with vao: %u, index_count: %u\n",
            cube->vao,
            cube->index_count);
        draw_primitive(cube);
    } else {
        printf("Failed to get cube primitive!\n");
    }
}

void gl_renderer_draw_plane(
    GLRenderer* renderer,
    Vec3 position,
    Vec3 normal,
    float size,
    Material material) {
    if (!renderer) return;

    Shader* shader
        = shader_library_get(&renderer->shader_library, SHADER_TYPE_DEFAULT_3D);
    if (!shader) return;

    shader_use(shader);

    // Create model matrix
    Mat4 model = mat4_identity();

    // Create rotation to align with normal
    Vec3 up = {0.0f, 1.0f, 0.0f};
    normal  = vec3_normalize(normal);

    // Calculate rotation from up vector to normal
    float cos_angle    = vec3_dot(up, normal);
    Vec3 rotation_axis = vec3_cross(up, normal);

    // Apply transformations
    Mat4 scale = mat4_scale(size, 1.0f, size);
    Mat4 rot   = mat4_identity();

    if (vec3_dot(rotation_axis, rotation_axis)
        > 0.0001f) {  // Check if rotation needed
        float angle   = acosf(cos_angle);
        rotation_axis = vec3_normalize(rotation_axis);
        rot           = mat4_rotation_y(angle);  // Simplified rotation for now
    }

    Mat4 trans = mat4_translation(position.x, position.y, position.z);

    // Combine transformations
    model = mat4_multiply(trans, mat4_multiply(rot, scale));

    // Set uniforms (same as cube drawing)
    shader_set_mat4(shader, "model", model.elements);
    shader_set_mat4(shader, "view", renderer->view.elements);
    shader_set_mat4(shader, "projection", renderer->projection.elements);

    shader_set_vec3(
        shader,
        "material.ambient",
        material.ambient.x,
        material.ambient.y,
        material.ambient.z);
    shader_set_vec3(
        shader,
        "material.diffuse",
        material.diffuse.x,
        material.diffuse.y,
        material.diffuse.z);
    shader_set_vec3(
        shader,
        "material.specular",
        material.specular.x,
        material.specular.y,
        material.specular.z);
    shader_set_float(shader, "material.shininess", material.shininess);

    shader_set_vec3(
        shader,
        "viewPos",
        renderer->camera_position.x,
        renderer->camera_position.y,
        renderer->camera_position.z);

    // Set lights
    shader_set_int(shader, "lightCount", renderer->light_count);
    for (int i = 0; i < renderer->light_count; i++) {
        char buf[64];
        snprintf(buf, sizeof(buf), "lights[%d].type", i);
        shader_set_int(shader, buf, renderer->lights[i].type);

        snprintf(buf, sizeof(buf), "lights[%d].position", i);
        shader_set_vec3(
            shader,
            buf,
            renderer->lights[i].position.x,
            renderer->lights[i].position.y,
            renderer->lights[i].position.z);

        snprintf(buf, sizeof(buf), "lights[%d].direction", i);
        shader_set_vec3(
            shader,
            buf,
            renderer->lights[i].direction.x,
            renderer->lights[i].direction.y,
            renderer->lights[i].direction.z);

        snprintf(buf, sizeof(buf), "lights[%d].color", i);
        shader_set_vec3(
            shader,
            buf,
            renderer->lights[i].color.x,
            renderer->lights[i].color.y,
            renderer->lights[i].color.z);

        snprintf(buf, sizeof(buf), "lights[%d].intensity", i);
        shader_set_float(shader, buf, renderer->lights[i].intensity);
    }

    // Get and draw plane
    Primitive* plane = primitive_cache_get_plane(&renderer->primitive_cache);
    if (plane) {
        printf(
            "Drawing plane with vao: %u, index_count: %u\n",
            plane->vao,
            plane->index_count);
        draw_primitive(plane);
    } else {
        printf("Failed to get plane primitive!\n");
    }
}

const char* gl_renderer_get_error(const GLRenderer* renderer) {
    return renderer ? renderer->error_message : "Invalid renderer instance";
}

void gl_renderer_destroy(GLRenderer* renderer) {
    if (!renderer) return;

    // Cleanup components in reverse order of initialization
    primitive_cache_destroy(&renderer->primitive_cache);
    shader_library_destroy(&renderer->shader_library);

    if (renderer->gl_context) {
        SDL_GL_DeleteContext(renderer->gl_context);
    }
    if (renderer->window) {
        SDL_DestroyWindow(renderer->window);
    }
    SDL_Quit();
    free(renderer);
}
