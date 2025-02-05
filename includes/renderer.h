#ifndef GL_RENDERER_H
#define GL_RENDERER_H

#include <GL/gl3w.h>
#include <SDL_cosmo.h>
#include <stdbool.h>

// Opaque pointer to hide implementation details
typedef struct GLRenderer GLRenderer;

// Configuration structure for initialization
typedef struct {
    const char* window_title;
    int window_width;
    int window_height;
    bool vsync_enabled;
    bool resizable;
} GLRendererConfig;

// 3D Math structures
typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    float x, y, z, w;
} Vec4;

typedef struct {
    float elements[16];  // Column-major 4x4 matrix
} Mat4;

// Light types
typedef enum {
    LIGHT_DIRECTIONAL,
    LIGHT_POINT,
    LIGHT_SPOT
} LightType;

typedef struct {
    LightType type;
    Vec3 position;   // Used for point and spot lights
    Vec3 direction;  // Used for directional and spot lights
    Vec3 color;
    float intensity;
    float range;      // For point/spot lights
    float spotAngle;  // For spot lights
} Light;

// Material properties
typedef struct {
    Vec3 ambient;
    Vec3 diffuse;
    Vec3 specular;
    float shininess;
} Material;

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

// Color structure for convenience
typedef struct {
    float r, g, b, a;
} GLRendererColor;

// Public API functions

/**
 * @brief Create a new GL renderer instance
 * @param config Pointer to configuration structure
 * @return Pointer to GLRenderer instance or NULL on failure
 */
GLRenderer* gl_renderer_create(const GLRendererConfig* config);

/**
 * @brief Initialize the renderer
 * @param renderer Pointer to renderer instance
 * @return Error code
 */
GLRendererError gl_renderer_init(
    GLRenderer* renderer,
    const GLRendererConfig* config);

/**
 * @brief Set the background clear color
 * @param renderer Pointer to renderer instance
 * @param color Color to set
 */
void gl_renderer_set_clear_color(
    GLRenderer* renderer,
    GLRendererColor color);

/**
 * @brief Begin a new frame
 * @param renderer Pointer to renderer instance
 */
void gl_renderer_begin_frame(GLRenderer* renderer);

/**
 * @brief End the current frame and swap buffers
 * @param renderer Pointer to renderer instance
 */
void gl_renderer_end_frame(GLRenderer* renderer);

/**
 * @brief Check if the renderer should continue running
 * @param renderer Pointer to renderer instance
 * @return true if running, false if should quit
 */
bool gl_renderer_is_running(GLRenderer* renderer);

/**
 * @brief Process SDL events
 * @param renderer Pointer to renderer instance
 */
void gl_renderer_process_events(GLRenderer* renderer);

/**
 * @brief Get the last error message
 * @param renderer Pointer to renderer instance
 * @return Const char pointer to error message
 */
const char* gl_renderer_get_error(const GLRenderer* renderer);

/**
 * @brief Clean up and destroy the renderer
 * @param renderer Pointer to renderer instance
 */
void gl_renderer_destroy(GLRenderer* renderer);

// Rendering primitives

/**
 * @brief Draw a rotating triangle
 * @param renderer Pointer to renderer instance
 * @param x Center X position (-1.0 to 1.0)
 * @param y Center Y position (-1.0 to 1.0)
 * @param size Size of the triangle (0.0 to 2.0)
 * @param rotation_speed Rotation speed in radians per frame
 */
void gl_renderer_draw_rotating_triangle(
    GLRenderer* renderer,
    float x,
    float y,
    float size,
    float rotation_speed);

// Utility functions for color creation
static inline GLRendererColor
gl_renderer_color_create(float r, float g, float b, float a) {
    return (GLRendererColor){r, g, b, a};
}

static inline GLRendererColor gl_renderer_color_rgb(
    unsigned char r,
    unsigned char g,
    unsigned char b) {
    return (GLRendererColor){r / 255.0f,
                             g / 255.0f,
                             b / 255.0f,
                             1.0f};
}

// Default configuration
static inline GLRendererConfig gl_renderer_config_default(void) {
    return (GLRendererConfig){.window_title  = "GL Renderer",
                              .window_width  = 800,
                              .window_height = 600,
                              .vsync_enabled = true,
                              .resizable     = true};
}

/**
 * @brief Initialize 3D rendering with perspective projection
 * @param renderer Pointer to renderer instance
 * @param fov Field of view in degrees
 * @param near Near clip plane
 * @param far Far clip plane
 */
void gl_renderer_set_3d_projection(
    GLRenderer* renderer,
    float fov,
    float near,
    float far);

/**
 * @brief Set the camera position and look target
 * @param renderer Pointer to renderer instance
 * @param eye Camera position
 * @param target Look target
 * @param up Up vector (usually {0,1,0})
 */
void gl_renderer_set_camera(
    GLRenderer* renderer,
    Vec3 eye,
    Vec3 target,
    Vec3 up);

/**
 * @brief Add a light to the scene
 * @param renderer Pointer to renderer instance
 * @param light Light configuration
 * @return Light index or -1 on error
 */
int gl_renderer_add_light(GLRenderer* renderer, Light light);

/**
 * @brief Draw a plane at the specified position
 * @param renderer Pointer to renderer instance
 * @param position Center position
 * @param normal Normal vector
 * @param size Size of the plane
 * @param material Material properties
 */
void gl_renderer_draw_plane(
    GLRenderer* renderer,
    Vec3 position,
    Vec3 normal,
    float size,
    Material material);

/**
 * @brief Draw a cube at the specified position
 * @param renderer Pointer to renderer instance
 * @param position Center position
 * @param size Size of the cube
 * @param rotation Rotation angles in radians (x,y,z)
 * @param material Material properties
 */
void gl_renderer_draw_cube(
    GLRenderer* renderer,
    Vec3 position,
    float size,
    Vec3 rotation,
    Material material);

// Utility functions
static inline Vec3 vec3_create(float x, float y, float z) {
    return (Vec3){x, y, z};
}

static inline Material material_create(
    Vec3 ambient,
    Vec3 diffuse,
    Vec3 specular,
    float shininess) {
    return (Material){ambient, diffuse, specular, shininess};
}

#endif /* GL_RENDERER_H */