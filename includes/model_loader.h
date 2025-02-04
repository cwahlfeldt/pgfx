#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"

static inline float parse_float(const char* str) {
    return strtof(str, NULL);
}

static inline Mesh* load_obj(
    const char* filename,
    Vec3 color,
    float specular,
    float reflective) {
    FILE* file = fopen(filename, "r");
    if (!file) return NULL;

    Mesh* mesh         = malloc(sizeof(Mesh));
    mesh->vertices     = NULL;
    mesh->normals      = NULL;
    mesh->indices      = NULL;
    mesh->vertex_count = 0;
    mesh->index_count  = 0;
    mesh->color        = color;
    mesh->specular     = specular;
    mesh->reflective   = reflective;

    // First pass: count vertices and faces
    char line[256];
    int v_count = 0, f_count = 0;
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == 'v' && line[1] == ' ') v_count++;
        if (line[0] == 'f' && line[1] == ' ') f_count++;
    }

    mesh->vertices = malloc(v_count * sizeof(Vec3));
    mesh->normals  = malloc(v_count * sizeof(Vec3));
    mesh->indices  = malloc(f_count * 3 * sizeof(int));

    // Second pass: read data
    rewind(file);
    int v_idx = 0, f_idx = 0;
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == 'v' && line[1] == ' ') {
            float x, y, z;
            sscanf(line, "v %f %f %f", &x, &y, &z);
            mesh->vertices[v_idx] = (Vec3){x, y, z};
            v_idx++;
        } else if (line[0] == 'f' && line[1] == ' ') {
            int a, b, c;
            sscanf(line, "f %d %d %d", &a, &b, &c);
            mesh->indices[f_idx * 3]     = a - 1;
            mesh->indices[f_idx * 3 + 1] = b - 1;
            mesh->indices[f_idx * 3 + 2] = c - 1;
            f_idx++;
        }
    }

    mesh->vertex_count = v_count;
    mesh->index_count  = f_count * 3;

    // Calculate normals
    for (int i = 0; i < mesh->vertex_count; i++) {
        mesh->normals[i] = (Vec3){0, 0, 0};
    }

    for (int i = 0; i < mesh->index_count; i += 3) {
        Vec3 v0 = mesh->vertices[mesh->indices[i]];
        Vec3 v1 = mesh->vertices[mesh->indices[i + 1]];
        Vec3 v2 = mesh->vertices[mesh->indices[i + 2]];

        Vec3 e1 = vec3_sub(v1, v0);
        Vec3 e2 = vec3_sub(v2, v0);
        Vec3 normal
            = vec3_normalize((Vec3){e1.y * e2.z - e1.z * e2.y,
                                    e1.z * e2.x - e1.x * e2.z,
                                    e1.x * e2.y - e1.y * e2.x});

        mesh->normals[mesh->indices[i]]
            = vec3_add(mesh->normals[mesh->indices[i]], normal);
        mesh->normals[mesh->indices[i + 1]] = vec3_add(
            mesh->normals[mesh->indices[i + 1]],
            normal);
        mesh->normals[mesh->indices[i + 2]] = vec3_add(
            mesh->normals[mesh->indices[i + 2]],
            normal);
    }

    for (int i = 0; i < mesh->vertex_count; i++) {
        mesh->normals[i] = vec3_normalize(mesh->normals[i]);
    }

    fclose(file);
    return mesh;
}

// Ray-triangle intersection
static inline float
triangle_intersect(Vec3 v0, Vec3 v1, Vec3 v2, Ray ray) {
    Vec3 e1 = vec3_sub(v1, v0);
    Vec3 e2 = vec3_sub(v2, v0);
    Vec3 h  = (Vec3){
        ray.direction.y * e2.z - ray.direction.z * e2.y,
        ray.direction.z * e2.x - ray.direction.x * e2.z,
        ray.direction.x * e2.y - ray.direction.y * e2.x};
    float a = vec3_dot(e1, h);

    if (a > -0.0001f && a < 0.0001f) return -1;

    float f = 1.0f / a;
    Vec3 s  = vec3_sub(ray.origin, v0);
    float u = f * vec3_dot(s, h);

    if (u < 0 || u > 1) return -1;

    Vec3 q  = (Vec3){s.y * e1.z - s.z * e1.y,
                     s.z * e1.x - s.x * e1.z,
                     s.x * e1.y - s.y * e1.x};
    float v = f * vec3_dot(ray.direction, q);

    if (v < 0 || u + v > 1) return -1;

    float t = f * vec3_dot(e2, q);
    return t > 0.0001f ? t : -1;
}

// Mesh intersection test
static inline float
mesh_intersect(Mesh* mesh, Ray ray, Vec3* normal) {
    float closest_t = INFINITY;
    int closest_tri = -1;

    for (int i = 0; i < mesh->index_count; i += 3) {
        Vec3 v0 = mesh->vertices[mesh->indices[i]];
        Vec3 v1 = mesh->vertices[mesh->indices[i + 1]];
        Vec3 v2 = mesh->vertices[mesh->indices[i + 2]];

        float t = triangle_intersect(v0, v1, v2, ray);
        if (t > 0 && t < closest_t) {
            closest_t   = t;
            closest_tri = i;
        }
    }

    if (closest_tri >= 0) {
        *normal = mesh->normals[mesh->indices[closest_tri]];
        return closest_t;
    }

    return -1;
}

#endif  // MODEL_LOADER_H