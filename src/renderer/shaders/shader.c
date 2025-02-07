#include "renderer/shaders/shader.h"
#include <stdio.h>
#include <stdlib.h>

static GLuint compile_shader(const char* source, GLenum type) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char info_log[512];
        glGetShaderInfoLog(shader, sizeof(info_log), NULL, info_log);
        fprintf(stderr, "Shader compilation error: %s\n", info_log);
        glDeleteShader(shader);
        return 0;
    }
    printf("Shader compilation successful.\n");

    return shader;
}

Shader shader_create_from_source(const char* vertex_source, const char* fragment_source) {
    Shader shader = {0};
    
    GLuint vertex_shader = compile_shader(vertex_source, GL_VERTEX_SHADER);
    if (!vertex_shader) {
        return shader;
    }

    GLuint fragment_shader = compile_shader(fragment_source, GL_FRAGMENT_SHADER);
    if (!fragment_shader) {
        glDeleteShader(vertex_shader);
        return shader;
    }

    shader.program = glCreateProgram();
    glAttachShader(shader.program, vertex_shader);
    glAttachShader(shader.program, fragment_shader);
    glLinkProgram(shader.program);

    GLint success;
    glGetProgramiv(shader.program, GL_LINK_STATUS, &success);
    if (!success) {
        char info_log[512];
        glGetProgramInfoLog(shader.program, sizeof(info_log), NULL, info_log);
        fprintf(stderr, "Shader program linking error: %s\n", info_log);
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
        glDeleteProgram(shader.program);
        shader.program = 0;
        return shader;
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    
    shader.initialized = true;
    return shader;
}

void shader_destroy(Shader* shader) {
    if (!shader || !shader->initialized) return;
    
    if (shader->program) {
        glDeleteProgram(shader->program);
        shader->program = 0;
    }
    
    shader->initialized = false;
}

void shader_use(const Shader* shader) {
    if (!shader || !shader->initialized) return;
    glUseProgram(shader->program);
}

bool shader_is_valid(const Shader* shader) {
    return shader && shader->initialized && shader->program != 0;
}

void shader_set_int(const Shader* shader, const char* name, int value) {
    if (!shader_is_valid(shader)) return;
    glUniform1i(glGetUniformLocation(shader->program, name), value);
}

void shader_set_float(const Shader* shader, const char* name, float value) {
    if (!shader_is_valid(shader)) return;
    glUniform1f(glGetUniformLocation(shader->program, name), value);
}

void shader_set_vec2(const Shader* shader, const char* name, float x, float y) {
    if (!shader_is_valid(shader)) return;
    glUniform2f(glGetUniformLocation(shader->program, name), x, y);
}

void shader_set_vec3(const Shader* shader, const char* name, float x, float y, float z) {
    if (!shader_is_valid(shader)) return;
    glUniform3f(glGetUniformLocation(shader->program, name), x, y, z);
}

void shader_set_vec4(const Shader* shader, const char* name, float x, float y, float z, float w) {
    if (!shader_is_valid(shader)) return;
    glUniform4f(glGetUniformLocation(shader->program, name), x, y, z, w);
}

void shader_set_mat4(const Shader* shader, const char* name, const float* matrix) {
    if (!shader_is_valid(shader)) return;
    glUniformMatrix4fv(glGetUniformLocation(shader->program, name), 1, GL_FALSE, matrix);
}