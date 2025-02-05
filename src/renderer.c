#include "renderer.h"

#include <SDL_cosmo.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Internal renderer structure
// Updated renderer structure with 3D support
struct GLRenderer {
    SDL_Window* window;
    SDL_GLContext gl_context;
    const char* glsl_version;
    bool running;
    GLRendererColor clear_color;
    char error_message[256];

    // 3D rendering state
    Mat4 projection;
    Mat4 view;
    Vec3 camera_position;

    // Shader programs
    GLuint basic_3d_program;

    // Mesh data
    GLuint cube_vao;
    GLuint cube_vbo;
    GLuint plane_vao;
    GLuint plane_vbo;

    // Lighting
    Light lights[8];  // Support up to 8 lights
    int light_count;

    float rotation_angle;

    // OpenGL resources
    GLuint shader_program;
    GLuint vao;
    GLuint vbo;
};

// Shader sources
static const char* vertex_shader_source
    = "#version 130\n"
      "in vec3 position;\n"
      "in vec3 color;\n"
      "out vec3 fragColor;\n"
      "uniform mat4 transform;\n"
      "void main() {\n"
      "    fragColor = color;\n"
      "    gl_Position = transform * vec4(position, 1.0);\n"
      "}\n";

static const char* fragment_shader_source
    = "#version 130\n"
      "in vec3 fragColor;\n"
      "out vec4 outColor;\n"
      "void main() {\n"
      "    outColor = vec4(fragColor, 1.0);\n"
      "}\n";

// Update vertex shader source in renderer.c
static const char* vertex_3d_shader_source
    = "#version 130\n"
      "in vec3 position;\n"
      "in vec3 normal;\n"
      "out vec3 fragPos;\n"
      "out vec3 fragNormal;\n"
      "uniform mat4 model;\n"
      "uniform mat4 view;\n"
      "uniform mat4 projection;\n"
      "void main() {\n"
      "    fragPos = vec3(model * vec4(position, 1.0));\n"
      "    // Simplified normal transformation - works for "
      "basic rotations and uniform scaling\n"
      "    fragNormal = mat3(model) * normal;\n"
      "    gl_Position = projection * view * model * "
      "vec4(position, 1.0);\n"
      "}\n";

static const char* fragment_3d_shader_source
    = "#version 130\n"
      "in vec3 fragPos;\n"
      "in vec3 fragNormal;\n"
      "out vec4 outColor;\n"
      "struct Light {\n"
      "    int type;\n"
      "    vec3 position;\n"
      "    vec3 direction;\n"
      "    vec3 color;\n"
      "    float intensity;\n"
      "    float range;\n"
      "    float spotAngle;\n"
      "};\n"
      "struct Material {\n"
      "    vec3 ambient;\n"
      "    vec3 diffuse;\n"
      "    vec3 specular;\n"
      "    float shininess;\n"
      "};\n"
      "uniform Light lights[8];\n"
      "uniform int lightCount;\n"
      "uniform Material material;\n"
      "uniform vec3 viewPos;\n"
      "void main() {\n"
      "    vec3 norm = normalize(fragNormal);\n"
      "    vec3 result = vec3(0.0);\n"
      "    \n"
      "    for(int i = 0; i < lightCount; i++) {\n"
      "        vec3 lightDir;\n"
      "        float attenuation = 1.0;\n"
      "        \n"
      "        if(lights[i].type == 0) {\n"  // Directional light
      "            lightDir = normalize(-lights[i].direction);\n"
      "        } else {\n"  // Point/spot light
      "            lightDir = normalize(lights[i].position - "
      "fragPos);\n"
      "            float distance = length(lights[i].position - "
      "fragPos);\n"
      "            attenuation = 1.0 / (1.0 + 0.09 * distance + "
      "0.032 * distance * distance);\n"
      "        }\n"
      "        \n"
      "        // Diffuse\n"
      "        float diff = max(dot(norm, lightDir), 0.0);\n"
      "        vec3 diffuse = lights[i].color * (diff * "
      "material.diffuse);\n"
      "        \n"
      "        // Specular\n"
      "        vec3 viewDir = normalize(viewPos - fragPos);\n"
      "        vec3 reflectDir = reflect(-lightDir, norm);\n"
      "        float spec = pow(max(dot(viewDir, reflectDir), "
      "0.0), material.shininess);\n"
      "        vec3 specular = lights[i].color * (spec * "
      "material.specular);\n"
      "        \n"
      "        // Ambient\n"
      "        vec3 ambient = lights[i].color * "
      "material.ambient;\n"
      "        \n"
      "        result += (ambient + diffuse + specular) * "
      "lights[i].intensity * attenuation;\n"
      "    }\n"
      "    \n"
      "    outColor = vec4(result, 1.0);\n"
      "}\n";

// Internal functions
static bool init_sdl(
    GLRenderer* renderer,
    const GLRendererConfig* config) {
    if (SDL_CosmoInit() != 0) {
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "SDL Cosmo Init failed: %s",
            SDL_CosmoGetError());
        return false;
    }
    if (SDL_Init(
            SDL_INIT_VIDEO | SDL_INIT_TIMER
            | SDL_INIT_GAMECONTROLLER)
        != 0) {
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "SDL Init failed: %s",
            SDL_GetError());
        return false;
    }

    // Set OpenGL version and context
#if __APPLE__
    renderer->glsl_version = "#version 150";
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_FLAGS,
        SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_PROFILE_MASK,
        SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
    renderer->glsl_version = "#version 130";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_PROFILE_MASK,
        SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

    // Configure OpenGL attributes
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // Create window
    Uint32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN;
    if (config->resizable) {
        window_flags |= SDL_WINDOW_RESIZABLE;
    }

    renderer->window = SDL_CreateWindow(
        config->window_title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        config->window_width,
        config->window_height,
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
    renderer->gl_context
        = SDL_GL_CreateContext(renderer->window);
    if (!renderer->gl_context) {
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "Failed to create OpenGL context: %s",
            SDL_GetError());
        return false;
    }

    // Enable VSync if requested
    SDL_GL_SetSwapInterval(config->vsync_enabled ? 1 : 0);

    return true;
}

static bool init_gl3w(GLRenderer* renderer) {
    GL3W_init();
    return true;
}

static bool init_shaders(GLRenderer* renderer) {
    // Create vertex shader
    GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(
        vertex_shader,
        1,
        &vertex_shader_source,
        NULL);
    glCompileShader(vertex_shader);

    // Check vertex shader compilation
    GLint success;
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar info_log[512];
        glGetShaderInfoLog(
            vertex_shader,
            sizeof(info_log),
            NULL,
            info_log);
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "Vertex shader compilation failed: %s",
            info_log);
        return false;
    }

    // Create fragment shader
    GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(
        fragment_shader,
        1,
        &fragment_shader_source,
        NULL);
    glCompileShader(fragment_shader);

    // Check fragment shader compilation
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar info_log[512];
        glGetShaderInfoLog(
            fragment_shader,
            sizeof(info_log),
            NULL,
            info_log);
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "Fragment shader compilation failed: %s",
            info_log);
        return false;
    }

    // Create shader program
    renderer->shader_program = glCreateProgram();
    glAttachShader(renderer->shader_program, vertex_shader);
    glAttachShader(renderer->shader_program, fragment_shader);
    glLinkProgram(renderer->shader_program);

    // Check program linking
    glGetProgramiv(
        renderer->shader_program,
        GL_LINK_STATUS,
        &success);
    if (!success) {
        GLchar info_log[512];
        glGetProgramInfoLog(
            renderer->shader_program,
            sizeof(info_log),
            NULL,
            info_log);
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "Shader program linking failed: %s",
            info_log);
        return false;
    }

    // Clean up shaders
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    return true;
}

// Public API implementation
GLRenderer* gl_renderer_create(const GLRendererConfig* config) {
    GLRenderer* renderer = calloc(1, sizeof(GLRenderer));
    if (!renderer) {
        return NULL;
    }

    renderer->running        = true;
    renderer->clear_color    = gl_renderer_color_rgb(51, 76, 76);
    renderer->rotation_angle = 0.0f;

    return renderer;
}

void gl_renderer_set_clear_color(
    GLRenderer* renderer,
    GLRendererColor color) {
    if (renderer) {
        renderer->clear_color = color;
    }
}

void gl_renderer_begin_frame(GLRenderer* renderer) {
    if (!renderer) return;

    glClearColor(
        renderer->clear_color.r,
        renderer->clear_color.g,
        renderer->clear_color.b,
        renderer->clear_color.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
                if (event.window.event
                    == SDL_WINDOWEVENT_RESIZED) {
                    glViewport(
                        0,
                        0,
                        event.window.data1,
                        event.window.data2);
                }
                break;
        }
    }
}

const char* gl_renderer_get_error(const GLRenderer* renderer) {
    return renderer ? renderer->error_message
                    : "Invalid renderer instance";
}

// Helper function to create rotation matrix
static void create_rotation_matrix(float angle, float* matrix) {
    float s = sinf(angle);
    float c = cosf(angle);

    // Row-major rotation matrix
    matrix[0]  = c;
    matrix[4]  = -s;
    matrix[8]  = 0.0f;
    matrix[12] = 0.0f;
    matrix[1]  = s;
    matrix[5]  = c;
    matrix[9]  = 0.0f;
    matrix[13] = 0.0f;
    matrix[2]  = 0.0f;
    matrix[6]  = 0.0f;
    matrix[10] = 1.0f;
    matrix[14] = 0.0f;
    matrix[3]  = 0.0f;
    matrix[7]  = 0.0f;
    matrix[11] = 0.0f;
    matrix[15] = 1.0f;
}

// Helper function to initialize triangle geometry
static bool init_triangle_geometry(GLRenderer* renderer) {
    if (renderer->vao != 0) {
        return true;  // Already initialized
    }

    // Vertex data for triangle
    float vertices[] = {
        // Position (XY)    // Color (RGB)
        -0.5f,
        -0.5f,
        0.0f,
        1.0f,
        0.0f,
        0.0f,  // Bottom left - Red
        0.5f,
        -0.5f,
        0.0f,
        0.0f,
        1.0f,
        0.0f,  // Bottom right - Green
        0.0f,
        0.5f,
        0.0f,
        0.0f,
        0.0f,
        1.0f  // Top - Blue
    };

    // Create and bind VAO
    glGenVertexArrays(1, &renderer->vao);
    glBindVertexArray(renderer->vao);

    // Create and bind VBO
    glGenBuffers(1, &renderer->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, renderer->vbo);
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vertices),
        vertices,
        GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(float),
        (void*)0);
    glEnableVertexAttribArray(0);

    // Color attribute
    glVertexAttribPointer(
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(float),
        (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    return true;
}

void gl_renderer_draw_rotating_triangle(
    GLRenderer* renderer,
    float x,
    float y,
    float size,
    float rotation_speed) {
    if (!renderer) return;

    // Initialize triangle geometry if needed
    if (!init_triangle_geometry(renderer)) {
        return;
    }

    // Use shader program
    glUseProgram(renderer->shader_program);

    // Update rotation
    renderer->rotation_angle += rotation_speed;
    if (renderer->rotation_angle > 2 * M_PI) {
        renderer->rotation_angle -= 2 * M_PI;
    }

    // Create transformation matrix
    float transform[16];
    create_rotation_matrix(renderer->rotation_angle, transform);

    // Apply translation and scaling
    transform[12] = x;  // Translation X
    transform[13] = y;  // Translation Y

    // Scale the matrix
    for (int i = 0; i < 3; i++) {
        transform[i * 4 + 0] *= size;
        transform[i * 4 + 1] *= size;
        transform[i * 4 + 2] *= size;
    }

    // Set transformation uniform
    GLint transform_loc = glGetUniformLocation(
        renderer->shader_program,
        "transform");
    glUniformMatrix4fv(transform_loc, 1, GL_FALSE, transform);

    // Draw the triangle
    glBindVertexArray(renderer->vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

// Optional: Add window management functions

int gl_renderer_get_window_width(const GLRenderer* renderer) {
    if (!renderer || !renderer->window) return 0;
    int width;
    SDL_GetWindowSize(renderer->window, &width, NULL);
    return width;
}

int gl_renderer_get_window_height(const GLRenderer* renderer) {
    if (!renderer || !renderer->window) return 0;
    int height;
    SDL_GetWindowSize(renderer->window, NULL, &height);
    return height;
}

void gl_renderer_set_window_title(
    GLRenderer* renderer,
    const char* title) {
    if (renderer && renderer->window && title) {
        SDL_SetWindowTitle(renderer->window, title);
    }
}

void gl_renderer_set_fullscreen(
    GLRenderer* renderer,
    bool fullscreen) {
    if (!renderer || !renderer->window) return;
    SDL_SetWindowFullscreen(
        renderer->window,
        fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
}

void gl_renderer_destroy(GLRenderer* renderer) {
    if (renderer) {
        if (renderer->shader_program) {
            glDeleteProgram(renderer->shader_program);
        }
        if (renderer->vao) {
            glDeleteVertexArrays(1, &renderer->vao);
        }
        if (renderer->vbo) {
            glDeleteBuffers(1, &renderer->vbo);
        }
        if (renderer->gl_context) {
            SDL_GL_DeleteContext(renderer->gl_context);
        }
        if (renderer->window) {
            SDL_DestroyWindow(renderer->window);
        }
        SDL_Quit();
        free(renderer);
    }
}

// Matrix operations
static Mat4 mat4_identity(void) {
    Mat4 m         = {0};
    m.elements[0]  = 1.0f;
    m.elements[5]  = 1.0f;
    m.elements[10] = 1.0f;
    m.elements[15] = 1.0f;
    return m;
}

static Mat4 mat4_perspective(
    float fov,
    float aspect,
    float near,
    float far) {
    Mat4 m            = {0};
    float tanHalfFovy = tanf(fov * 0.5f * M_PI / 180.0f);

    m.elements[0]  = 1.0f / (aspect * tanHalfFovy);
    m.elements[5]  = 1.0f / tanHalfFovy;
    m.elements[10] = -(far + near) / (far - near);
    m.elements[11] = -1.0f;
    m.elements[14] = -(2.0f * far * near) / (far - near);

    return m;
}

static Mat4 mat4_look_at(Vec3 eye, Vec3 target, Vec3 up) {
    Mat4 m = mat4_identity();

    Vec3 z
        = {eye.x - target.x, eye.y - target.y, eye.z - target.z};
    // Normalize z
    float len = sqrtf(z.x * z.x + z.y * z.y + z.z * z.z);
    z.x /= len;
    z.y /= len;
    z.z /= len;

    Vec3 x
        = {up.y * z.z - up.z * z.y,
           up.z * z.x - up.x * z.z,
           up.x * z.y - up.y * z.x};
    // Normalize x
    len = sqrtf(x.x * x.x + x.y * x.y + x.z * x.z);
    x.x /= len;
    x.y /= len;
    x.z /= len;

    Vec3 y
        = {z.y * x.z - z.z * x.y,
           z.z * x.x - z.x * x.z,
           z.x * x.y - z.y * x.x};

    m.elements[0]  = x.x;
    m.elements[1]  = y.x;
    m.elements[2]  = z.x;
    m.elements[4]  = x.y;
    m.elements[5]  = y.y;
    m.elements[6]  = z.y;
    m.elements[8]  = x.z;
    m.elements[9]  = y.z;
    m.elements[10] = z.z;
    m.elements[12] = -x.x * eye.x - x.y * eye.y - x.z * eye.z;
    m.elements[13] = -y.x * eye.x - y.y * eye.y - y.z * eye.z;
    m.elements[14] = -z.x * eye.x - z.y * eye.y - z.z * eye.z;

    return m;
}

// Vector operations
static float dot_product(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static Vec3 cross_product(Vec3 a, Vec3 b) {
    return (Vec3){a.y * b.z - a.z * b.y,
                  a.z * b.x - a.x * b.z,
                  a.x * b.y - a.y * b.x};
}

static Vec3 vec3_normalize(Vec3 v) {
    float len = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    if (len < 0.0001f) return v;
    return (Vec3){v.x / len, v.y / len, v.z / len};
}

// Matrix operations
static Mat4 mat4_multiply(Mat4 a, Mat4 b) {
    Mat4 result = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            float sum = 0.0f;
            for (int k = 0; k < 4; k++) {
                sum += a.elements[k * 4 + i]
                       * b.elements[j * 4 + k];
            }
            result.elements[j * 4 + i] = sum;
        }
    }
    return result;
}

static Mat4 mat4_rotation_x(float angle) {
    Mat4 m         = mat4_identity();
    float c        = cosf(angle);
    float s        = sinf(angle);
    m.elements[5]  = c;
    m.elements[6]  = -s;
    m.elements[9]  = s;
    m.elements[10] = c;
    return m;
}

static Mat4 mat4_rotation_y(float angle) {
    Mat4 m         = mat4_identity();
    float c        = cosf(angle);
    float s        = sinf(angle);
    m.elements[0]  = c;
    m.elements[2]  = s;
    m.elements[8]  = -s;
    m.elements[10] = c;
    return m;
}

static Mat4 mat4_rotation_z(float angle) {
    Mat4 m        = mat4_identity();
    float c       = cosf(angle);
    float s       = sinf(angle);
    m.elements[0] = c;
    m.elements[1] = -s;
    m.elements[4] = s;
    m.elements[5] = c;
    return m;
}

static Mat4 mat4_rotation_axis(Vec3 axis, float angle) {
    Mat4 m  = mat4_identity();
    axis    = vec3_normalize(axis);
    float c = cosf(angle);
    float s = sinf(angle);
    float t = 1.0f - c;

    m.elements[0] = t * axis.x * axis.x + c;
    m.elements[1] = t * axis.x * axis.y - s * axis.z;
    m.elements[2] = t * axis.x * axis.z + s * axis.y;

    m.elements[4] = t * axis.x * axis.y + s * axis.z;
    m.elements[5] = t * axis.y * axis.y + c;
    m.elements[6] = t * axis.y * axis.z - s * axis.x;

    m.elements[8]  = t * axis.x * axis.z - s * axis.y;
    m.elements[9]  = t * axis.y * axis.z + s * axis.x;
    m.elements[10] = t * axis.z * axis.z + c;

    return m;
}

// Utility function to create a scale matrix
static Mat4 mat4_scale(float x, float y, float z) {
    Mat4 m         = mat4_identity();
    m.elements[0]  = x;
    m.elements[5]  = y;
    m.elements[10] = z;
    return m;
}

// Utility function to create a translation matrix
static Mat4 mat4_translation(float x, float y, float z) {
    Mat4 m         = mat4_identity();
    m.elements[12] = x;
    m.elements[13] = y;
    m.elements[14] = z;
    return m;
}

// Initialize 3D rendering
void gl_renderer_set_3d_projection(
    GLRenderer* renderer,
    float fov,
    float near,
    float far) {
    if (!renderer) return;

    int width, height;
    SDL_GetWindowSize(renderer->window, &width, &height);
    float aspect = (float)width / (float)height;

    renderer->projection
        = mat4_perspective(fov, aspect, near, far);
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

// Create mesh data
static void init_cube_mesh(GLRenderer* renderer) {
    // Cube vertices with normals
    float vertices[] = {
        // positions          // normals
        -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  -1.0f, 0.5f,  -0.5f,
        -0.5f, 0.0f,  0.0f,  -1.0f, 0.5f,  0.5f,  -0.5f, 0.0f,
        0.0f,  -1.0f, -0.5f, 0.5f,  -0.5f, 0.0f,  0.0f,  -1.0f,
        // ... (add remaining cube vertices)
    };

    glGenVertexArrays(1, &renderer->cube_vao);
    glGenBuffers(1, &renderer->cube_vbo);

    glBindVertexArray(renderer->cube_vao);
    glBindBuffer(GL_ARRAY_BUFFER, renderer->cube_vbo);
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vertices),
        vertices,
        GL_STATIC_DRAW);

    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(float),
        (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        1,
        3,
        GL_FLOAT,
        GL_FALSE,
        6 * sizeof(float),
        (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

// Implementation of the public API functions
int gl_renderer_add_light(GLRenderer* renderer, Light light) {
    if (!renderer || renderer->light_count >= 8) return -1;

    renderer->lights[renderer->light_count] = light;
    return renderer->light_count++;
}

// Add to init_shaders function
static bool init_gl_shaders(GLRenderer* renderer) {
    // Create and compile 3D vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(
        vertexShader,
        1,
        &vertex_3d_shader_source,
        NULL);
    glCompileShader(vertexShader);

    // Check vertex shader compilation
    GLint success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar infoLog[512];
        glGetShaderInfoLog(
            vertexShader,
            sizeof(infoLog),
            NULL,
            infoLog);
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "Vertex shader compilation failed: %s",
            infoLog);
        return false;
    }

    // Create and compile fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(
        fragmentShader,
        1,
        &fragment_3d_shader_source,
        NULL);
    glCompileShader(fragmentShader);

    // Check fragment shader compilation
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar infoLog[512];
        glGetShaderInfoLog(
            fragmentShader,
            sizeof(infoLog),
            NULL,
            infoLog);
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "Fragment shader compilation failed: %s",
            infoLog);
        return false;
    }

    // Create shader program
    renderer->basic_3d_program = glCreateProgram();
    glAttachShader(renderer->basic_3d_program, vertexShader);
    glAttachShader(renderer->basic_3d_program, fragmentShader);
    glLinkProgram(renderer->basic_3d_program);

    // Check program linking
    glGetProgramiv(
        renderer->basic_3d_program,
        GL_LINK_STATUS,
        &success);
    if (!success) {
        GLchar infoLog[512];
        glGetProgramInfoLog(
            renderer->basic_3d_program,
            sizeof(infoLog),
            NULL,
            infoLog);
        snprintf(
            renderer->error_message,
            sizeof(renderer->error_message),
            "Shader program linking failed: %s",
            infoLog);
        return false;
    }

    // Clean up shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    return true;
}

void gl_renderer_draw_cube(
    GLRenderer* renderer,
    Vec3 position,
    float size,
    Vec3 rotation,
    Material material) {
    if (!renderer) return;

    // Use the 3D shader program
    glUseProgram(renderer->basic_3d_program);

    // Create model matrix (position and scale)
    Mat4 model = mat4_identity();

    // Apply transformations in order: scale, rotate, translate
    // Scale
    for (int i = 0; i < 3; i++) {
        model.elements[i * 4 + i] *= size;
    }

    // Rotate (simple rotation for now, could be improved with
    // quaternions)
    Mat4 rotX = mat4_rotation_x(rotation.x);
    Mat4 rotY = mat4_rotation_y(rotation.y);
    Mat4 rotZ = mat4_rotation_z(rotation.z);
    model     = mat4_multiply(
        model,
        mat4_multiply(rotX, mat4_multiply(rotY, rotZ)));

    // Translate
    model.elements[12] = position.x;
    model.elements[13] = position.y;
    model.elements[14] = position.z;

    // Set uniforms
    glUniformMatrix4fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "model"),
        1,
        GL_FALSE,
        model.elements);
    glUniformMatrix4fv(
        glGetUniformLocation(renderer->basic_3d_program, "view"),
        1,
        GL_FALSE,
        renderer->view.elements);
    glUniformMatrix4fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "projection"),
        1,
        GL_FALSE,
        renderer->projection.elements);

    // Set material properties
    glUniform3fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "material.ambient"),
        1,
        (float*)&material.ambient);
    glUniform3fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "material.diffuse"),
        1,
        (float*)&material.diffuse);
    glUniform3fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "material.specular"),
        1,
        (float*)&material.specular);
    glUniform1f(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "material.shininess"),
        material.shininess);

    // Set lights
    glUniform1i(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "lightCount"),
        renderer->light_count);
    for (int i = 0; i < renderer->light_count; i++) {
        char buf[64];
        snprintf(buf, sizeof(buf), "lights[%d].type", i);
        glUniform1i(
            glGetUniformLocation(
                renderer->basic_3d_program,
                buf),
            renderer->lights[i].type);

        snprintf(buf, sizeof(buf), "lights[%d].position", i);
        glUniform3fv(
            glGetUniformLocation(
                renderer->basic_3d_program,
                buf),
            1,
            (float*)&renderer->lights[i].position);

        snprintf(buf, sizeof(buf), "lights[%d].direction", i);
        glUniform3fv(
            glGetUniformLocation(
                renderer->basic_3d_program,
                buf),
            1,
            (float*)&renderer->lights[i].direction);

        snprintf(buf, sizeof(buf), "lights[%d].color", i);
        glUniform3fv(
            glGetUniformLocation(
                renderer->basic_3d_program,
                buf),
            1,
            (float*)&renderer->lights[i].color);

        snprintf(buf, sizeof(buf), "lights[%d].intensity", i);
        glUniform1f(
            glGetUniformLocation(
                renderer->basic_3d_program,
                buf),
            renderer->lights[i].intensity);
    }

    // Set camera position for specular calculation
    glUniform3fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "viewPos"),
        1,
        (float*)&renderer->camera_position);

    // Draw the cube
    glBindVertexArray(renderer->cube_vao);
    glDrawArrays(
        GL_TRIANGLES,
        0,
        36);  // 6 faces * 2 triangles * 3 vertices
}

void gl_renderer_draw_plane(
    GLRenderer* renderer,
    Vec3 position,
    Vec3 normal,
    float size,
    Material material) {
    if (!renderer) return;

    // Use the 3D shader program
    glUseProgram(renderer->basic_3d_program);

    // Create plane vertices if not already created
    if (!renderer->plane_vao) {
        float vertices[] = {
            // Position          Normal
            -1.0f, 0.0f, -1.0f, 0.0f, 1.0f,  0.0f, 1.0f,  0.0f,
            -1.0f, 0.0f, 1.0f,  0.0f, 1.0f,  0.0f, 1.0f,  0.0f,
            1.0f,  0.0f, -1.0f, 0.0f, -1.0f, 0.0f, 1.0f,  0.0f,
            1.0f,  0.0f, 1.0f,  0.0f, 1.0f,  0.0f, -1.0f, 0.0f,
            1.0f,  0.0f, 1.0f,  0.0f};

        glGenVertexArrays(1, &renderer->plane_vao);
        glGenBuffers(1, &renderer->plane_vbo);

        glBindVertexArray(renderer->plane_vao);
        glBindBuffer(GL_ARRAY_BUFFER, renderer->plane_vbo);
        glBufferData(
            GL_ARRAY_BUFFER,
            sizeof(vertices),
            vertices,
            GL_STATIC_DRAW);

        glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            6 * sizeof(float),
            (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(
            1,
            3,
            GL_FLOAT,
            GL_FALSE,
            6 * sizeof(float),
            (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    // Create model matrix
    Mat4 model = mat4_identity();

    // Scale
    for (int i = 0; i < 3; i++) {
        model.elements[i * 4 + i] *= size;
    }

    // Rotate to align with normal (you might want to improve
    // this)
    Vec3 up     = {0.0f, 1.0f, 0.0f};
    float angle = acosf(dot_product(up, normal));
    if (angle > 0.001f) {
        Vec3 axis     = cross_product(up, normal);
        Mat4 rotation = mat4_rotation_axis(axis, angle);
        model         = mat4_multiply(model, rotation);
    }

    // Translate
    model.elements[12] = position.x;
    model.elements[13] = position.y;
    model.elements[14] = position.z;

    // Set uniforms
    glUniformMatrix4fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "model"),
        1,
        GL_FALSE,
        model.elements);
    glUniformMatrix4fv(
        glGetUniformLocation(renderer->basic_3d_program, "view"),
        1,
        GL_FALSE,
        renderer->view.elements);
    glUniformMatrix4fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "projection"),
        1,
        GL_FALSE,
        renderer->projection.elements);

    // Set material properties
    glUniform3fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "material.ambient"),
        1,
        (float*)&material.ambient);
    glUniform3fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "material.diffuse"),
        1,
        (float*)&material.diffuse);
    glUniform3fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "material.specular"),
        1,
        (float*)&material.specular);
    glUniform1f(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "material.shininess"),
        material.shininess);

    // Set lights
    glUniform1i(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "lightCount"),
        renderer->light_count);
    for (int i = 0; i < renderer->light_count; i++) {
        char buf[64];
        snprintf(buf, sizeof(buf), "lights[%d].type", i);
        glUniform1i(
            glGetUniformLocation(
                renderer->basic_3d_program,
                buf),
            renderer->lights[i].type);

        snprintf(buf, sizeof(buf), "lights[%d].position", i);
        glUniform3fv(
            glGetUniformLocation(
                renderer->basic_3d_program,
                buf),
            1,
            (float*)&renderer->lights[i].position);

        snprintf(buf, sizeof(buf), "lights[%d].direction", i);
        glUniform3fv(
            glGetUniformLocation(
                renderer->basic_3d_program,
                buf),
            1,
            (float*)&renderer->lights[i].direction);

        snprintf(buf, sizeof(buf), "lights[%d].color", i);
        glUniform3fv(
            glGetUniformLocation(
                renderer->basic_3d_program,
                buf),
            1,
            (float*)&renderer->lights[i].color);

        snprintf(buf, sizeof(buf), "lights[%d].intensity", i);
        glUniform1f(
            glGetUniformLocation(
                renderer->basic_3d_program,
                buf),
            renderer->lights[i].intensity);
    }

    // Set camera position for specular calculation
    glUniform3fv(
        glGetUniformLocation(
            renderer->basic_3d_program,
            "viewPos"),
        1,
        (float*)&renderer->camera_position);

    // Draw the plane
    glBindVertexArray(renderer->plane_vao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

GLRendererError gl_renderer_init(
    GLRenderer* renderer,
    const GLRendererConfig* config) {
    if (!renderer) {
        return GL_RENDERER_ERROR_MEMORY;
    }

    // Initialize SDL and create window
    if (!init_sdl(renderer, config)) {
        return GL_RENDERER_ERROR_SDL_INIT;
    }

    // Initialize GL3W
    if (!init_gl3w(renderer)) {
        return GL_RENDERER_ERROR_GL3W_INIT;
    }

    // Initialize shaders and OpenGL resources
    if (!init_shaders(renderer)) {
        return GL_RENDERER_ERROR_SHADER_COMPILATION;
    }

    // Initialize shaders and OpenGL resources
    if (!init_gl_shaders(renderer)) {
        return GL_RENDERER_ERROR_SHADER_COMPILATION;
    }

    return GL_RENDERER_SUCCESS;
}