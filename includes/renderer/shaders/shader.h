#ifndef PGFX_RENDERER_SHADERS_SHADER_H
#define PGFX_RENDERER_SHADERS_SHADER_H

#include <GL/gl3w.h>
#include <stdbool.h>

typedef struct {
    GLuint program;
    bool initialized;
} Shader;

// Creation and destruction
Shader shader_create_from_source(const char* vertex_source, const char* fragment_source);
void shader_destroy(Shader* shader);

// Usage
void shader_use(const Shader* shader);
bool shader_is_valid(const Shader* shader);

// Uniform setters
void shader_set_int(const Shader* shader, const char* name, int value);
void shader_set_float(const Shader* shader, const char* name, float value);
void shader_set_vec2(const Shader* shader, const char* name, float x, float y);
void shader_set_vec3(const Shader* shader, const char* name, float x, float y, float z);
void shader_set_vec4(const Shader* shader, const char* name, float x, float y, float z, float w);
void shader_set_mat4(const Shader* shader, const char* name, const float* matrix);

#endif // PGFX_RENDERER_SHADERS_SHADER_H