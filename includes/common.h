#ifndef COMMON_H
#define COMMON_H

#include <math.h>

typedef struct {
    float x, y, z;
} Vec3;

static inline Vec3 vec3(float x, float y, float z) {
    return (Vec3){x, y, z};
}

static inline Vec3 vec3_add(Vec3 a, Vec3 b) {
    return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

static inline Vec3 vec3_sub(Vec3 a, Vec3 b) {
    return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

static inline Vec3 vec3_mul(Vec3 v, float s) {
    return vec3(v.x * s, v.y * s, v.z * s);
}

static inline float vec3_dot(Vec3 a, Vec3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline float vec3_length(Vec3 v) {
    return sqrtf(vec3_dot(v, v));
}

static inline Vec3 vec3_normalize(Vec3 v) {
    float len = vec3_length(v);
    return vec3(v.x / len, v.y / len, v.z / len);
}

typedef struct {
    Vec3 origin;
    Vec3 direction;
} Ray;

typedef struct {
    Vec3 center;
    float radius;
    Vec3 color;
    float specular;
    float reflective;
} Sphere;

typedef struct {
    Vec3 position;
    float intensity;
} Light;

typedef struct {
    Vec3* vertices;
    Vec3* normals;
    int* indices;
    int vertex_count;
    int index_count;
    Vec3 color;
    float specular;
    float reflective;
} Mesh;

#endif