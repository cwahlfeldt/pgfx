#ifndef PGFX_RENDERER_CORE_RENDERER_H
#define PGFX_RENDERER_CORE_RENDERER_H

#include <GL/gl3w.h>
#include <SDL_cosmo.h>
#include <stdbool.h>

#include "../math/vector.h"
#include "../math/matrix.h"
#include "../lighting/light.h"
#include "../materials/material.h"
#include "../objects/primitives.h"
#include "../shaders/shader_library.h"
#include "render_state.h"

// Configuration structure for initialization
typedef struct {
    const char* window_title;
    int window_width;
    int window_height;
    bool vsync_enabled;
    bool resizable;
} GLRendererConfig;

// Error codes
typedef enum {
    GL_RENDERER_SUCCESS = 0,
    GL_RENDERER_ERROR_SDL_INIT,
    GL_RENDERER_ERROR_WINDOW_CREATION,
    GL_RENDERER_ERROR_GL_CONTEXT,
    GL_RENDERER_ERROR_GL3W_INIT,
    GL_RENDERER_ERROR_SHADER_COMPILATION,
    GL_RENDERER_ERROR_SHADER_LINKING,
    GL_RENDERER_ERROR_MEMORY
} GLRendererError;

// Forward declare the renderer struct 
typedef struct GLRenderer GLRenderer;

// Creation/destruction
GLRenderer* gl_renderer_create(const GLRendererConfig* config);
GLRendererError gl_renderer_init(GLRenderer* renderer, const GLRendererConfig* config);
void gl_renderer_destroy(GLRenderer* renderer);

// Frame management
void gl_renderer_begin_frame(GLRenderer* renderer);
void gl_renderer_end_frame(GLRenderer* renderer);
bool gl_renderer_is_running(GLRenderer* renderer);
void gl_renderer_process_events(GLRenderer* renderer);

// 3D Rendering
void gl_renderer_set_3d_projection(GLRenderer* renderer, float fov, float near, float far);
void gl_renderer_set_camera(GLRenderer* renderer, Vec3 eye, Vec3 target, Vec3 up);

// Lighting
int gl_renderer_add_light(GLRenderer* renderer, Light light);

// Drawing
void gl_renderer_draw_cube(GLRenderer* renderer, Vec3 position, float size, Vec3 rotation, Material material);
void gl_renderer_draw_plane(GLRenderer* renderer, Vec3 position, Vec3 normal, float size, Material material);

// Get the last error message
const char* gl_renderer_get_error(const GLRenderer* renderer);

// Utility functions
static inline GLRendererConfig gl_renderer_config_default(void) {
    return (GLRendererConfig){
        .window_title = "GL Renderer",
        .window_width = 800,
        .window_height = 600,
        .vsync_enabled = true,
        .resizable = true
    };
}

#endif // PGFX_RENDERER_CORE_RENDERER_H