#include "renderer/math/matrix.h"
#include "renderer/math/vector.h"
#include <math.h>

Mat4 mat4_identity(void) {
    Mat4 m = {0};
    m.elements[0] = 1.0f;
    m.elements[5] = 1.0f;
    m.elements[10] = 1.0f;
    m.elements[15] = 1.0f;
    return m;
}

Mat4 mat4_perspective(float fov, float aspect, float near, float far) {
    Mat4 m = {0};
    float tanHalfFovy = tanf(fov * 0.5f * M_PI / 180.0f);

    m.elements[0] = 1.0f / (aspect * tanHalfFovy);
    m.elements[5] = 1.0f / tanHalfFovy;
    m.elements[10] = -(far + near) / (far - near);
    m.elements[11] = -1.0f;
    m.elements[14] = -(2.0f * far * near) / (far - near);

    return m;
}

Mat4 mat4_look_at(Vec3 eye, Vec3 target, Vec3 up) {
    Mat4 m = mat4_identity();
    Vec3 z = vec3_subtract(eye, target);
    z = vec3_normalize(z);

    Vec3 x = vec3_cross(up, z);
    x = vec3_normalize(x);

    Vec3 y = vec3_cross(z, x);

    m.elements[0] = x.x;
    m.elements[1] = y.x;
    m.elements[2] = z.x;
    m.elements[4] = x.y;
    m.elements[5] = y.y;
    m.elements[6] = z.y;
    m.elements[8] = x.z;
    m.elements[9] = y.z;
    m.elements[10] = z.z;
    m.elements[12] = -vec3_dot(x, eye);
    m.elements[13] = -vec3_dot(y, eye);
    m.elements[14] = -vec3_dot(z, eye);

    return m;
}

Mat4 mat4_multiply(Mat4 a, Mat4 b) {
    Mat4 result = {0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            float sum = 0.0f;
            for (int k = 0; k < 4; k++) {
                sum += a.elements[k * 4 + i] * b.elements[j * 4 + k];
            }
            result.elements[j * 4 + i] = sum;
        }
    }
    return result;
}

Mat4 mat4_rotation_x(float angle) {
    Mat4 m = mat4_identity();
    float c = cosf(angle);
    float s = sinf(angle);
    m.elements[5] = c;
    m.elements[6] = -s;
    m.elements[9] = s;
    m.elements[10] = c;
    return m;
}

Mat4 mat4_rotation_y(float angle) {
    Mat4 m = mat4_identity();
    float c = cosf(angle);
    float s = sinf(angle);
    m.elements[0] = c;
    m.elements[2] = s;
    m.elements[8] = -s;
    m.elements[10] = c;
    return m;
}

Mat4 mat4_rotation_z(float angle) {
    Mat4 m = mat4_identity();
    float c = cosf(angle);
    float s = sinf(angle);
    m.elements[0] = c;
    m.elements[1] = -s;
    m.elements[4] = s;
    m.elements[5] = c;
    return m;
}

Mat4 mat4_scale(float x, float y, float z) {
    Mat4 m = mat4_identity();
    m.elements[0] = x;
    m.elements[5] = y;
    m.elements[10] = z;
    return m;
}

Mat4 mat4_translation(float x, float y, float z) {
    Mat4 m = mat4_identity();
    m.elements[12] = x;
    m.elements[13] = y;
    m.elements[14] = z;
    return m;
}