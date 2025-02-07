#ifndef PGFX_RENDERER_MATH_MATRIX_H
#define PGFX_RENDERER_MATH_MATRIX_H

#include "vector.h"

typedef struct {
    float elements[16];  // Column-major 4x4 matrix
} Mat4;

// Matrix creation
Mat4 mat4_identity(void);
Mat4 mat4_perspective(float fov, float aspect, float near, float far);
Mat4 mat4_look_at(Vec3 eye, Vec3 target, Vec3 up);

// Matrix operations
Mat4 mat4_multiply(Mat4 a, Mat4 b);
Mat4 mat4_rotation_x(float angle);
Mat4 mat4_rotation_y(float angle);
Mat4 mat4_rotation_z(float angle);
Mat4 mat4_scale(float x, float y, float z);
Mat4 mat4_translation(float x, float y, float z);

#endif // PGFX_RENDERER_MATH_MATRIX_H