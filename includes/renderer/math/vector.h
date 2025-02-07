#ifndef PGFX_RENDERER_MATH_VECTOR_H
#define PGFX_RENDERER_MATH_VECTOR_H

typedef struct {
    float x, y, z;
} Vec3;

typedef struct {
    float x, y, z, w;
} Vec4;

// Utility functions
static inline Vec3 vec3_create(float x, float y, float z) {
    return (Vec3){x, y, z};
}

static inline Vec4 vec4_create(float x, float y, float z, float w) {
    return (Vec4){x, y, z, w};
}

// Vector operations
Vec3 vec3_add(Vec3 a, Vec3 b);
Vec3 vec3_subtract(Vec3 a, Vec3 b);
Vec3 vec3_multiply(Vec3 v, float scalar);
float vec3_dot(Vec3 a, Vec3 b);
Vec3 vec3_cross(Vec3 a, Vec3 b);
Vec3 vec3_normalize(Vec3 v);

#endif // PGFX_RENDERER_MATH_VECTOR_H