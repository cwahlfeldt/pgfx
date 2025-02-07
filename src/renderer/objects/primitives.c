#include "renderer/objects/primitives.h"
#include <stdlib.h>
#include <math.h>

// Utility functions for primitive creation
static void create_cube_vertices(float** vertices, int* vertex_count) {
    static float cube_vertices[] = {
        // Front face
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f, // Normal
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        // Back face
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        // Right face
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        // Left face
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,

        // Top face
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,

        // Bottom face
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
    };

    *vertices = cube_vertices;
    *vertex_count = 36;  // 6 faces * 2 triangles * 3 vertices
}

static void create_plane_vertices(float** vertices, int* vertex_count) {
    static float plane_vertices[] = {
        // Position           Normal
        -0.5f, 0.0f, -0.5f,  0.0f, 1.0f, 0.0f,
         0.5f, 0.0f, -0.5f,  0.0f, 1.0f, 0.0f,
         0.5f, 0.0f,  0.5f,  0.0f, 1.0f, 0.0f,
        -0.5f, 0.0f, -0.5f,  0.0f, 1.0f, 0.0f,
         0.5f, 0.0f,  0.5f,  0.0f, 1.0f, 0.0f,
        -0.5f, 0.0f,  0.5f,  0.0f, 1.0f, 0.0f
    };

    *vertices = plane_vertices;
    *vertex_count = 6;  // 2 triangles * 3 vertices
}

static Primitive create_primitive_from_vertices(float* vertices, int vertex_count) {
    Primitive primitive = {0};

    glGenVertexArrays(1, &primitive.vao);
    glGenBuffers(1, &primitive.vbo);

    glBindVertexArray(primitive.vao);
    glBindBuffer(GL_ARRAY_BUFFER, primitive.vbo);
    glBufferData(GL_ARRAY_BUFFER, vertex_count * 6 * sizeof(float), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    primitive.index_count = vertex_count;
    return primitive;
}

Primitive create_cube_primitive(void) {
    float* vertices;
    int vertex_count;
    create_cube_vertices(&vertices, &vertex_count);
    return create_primitive_from_vertices(vertices, vertex_count);
}

Primitive create_plane_primitive(void) {
    float* vertices;
    int vertex_count;
    create_plane_vertices(&vertices, &vertex_count);
    return create_primitive_from_vertices(vertices, vertex_count);
}

void destroy_primitive(Primitive* primitive) {
    if (!primitive) return;

    if (primitive->vao) {
        glDeleteVertexArrays(1, &primitive->vao);
    }
    if (primitive->vbo) {
        glDeleteBuffers(1, &primitive->vbo);
    }
    if (primitive->ebo) {
        glDeleteBuffers(1, &primitive->ebo);
    }

    primitive->vao = 0;
    primitive->vbo = 0;
    primitive->ebo = 0;
    primitive->index_count = 0;
}

void draw_primitive(const Primitive* primitive) {
    if (!primitive || !primitive->vao) return;

    glBindVertexArray(primitive->vao);
    if (primitive->ebo) {
        glDrawElements(GL_TRIANGLES, primitive->index_count, GL_UNSIGNED_INT, 0);
    } else {
        glDrawArrays(GL_TRIANGLES, 0, primitive->index_count);
    }
}

// For now, return simpler primitives for sphere and cylinder
Primitive create_sphere_primitive(void) {
    return create_cube_primitive();  // Temporary - should be replaced with actual sphere geometry
}

Primitive create_cylinder_primitive(void) {
    return create_cube_primitive();  // Temporary - should be replaced with actual cylinder geometry
}