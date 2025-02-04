/*
 * simplegfx.h - A simple software rendering graphics library
 *
 * This library provides basic graphics primitives without
 * external dependencies. It uses a software renderer approach
 * similar to early computer graphics systems.
 */

#ifndef SIMPLEGFX_H
#define SIMPLEGFX_H

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Define our color type as 32-bit RGBA
typedef uint32_t Color;

// Basic structure to hold a 2D point
typedef struct {
    int x;
    int y;
} Point;

// Structure for our frame buffer
typedef struct {
    uint32_t* pixels;  // Raw pixel data
    int width;         // Buffer width
    int height;        // Buffer height
    int pitch;         // Bytes per row
} FrameBuffer;

typedef struct {
    float x, y, z;
} Vector3;

typedef struct {
    float x, y;
} Vector2;

// Z-buffer to handle depth properly
typedef struct {
    float* depths;
    int width;
    int height;
} ZBuffer;

// Create Z-buffer
static inline ZBuffer* create_zbuffer(int width, int height) {
    ZBuffer* zbuf = (ZBuffer*)malloc(sizeof(ZBuffer));
    zbuf->width   = width;
    zbuf->height  = height;
    zbuf->depths
        = (float*)malloc(width * height * sizeof(float));
    return zbuf;
}

// Clear Z-buffer
static inline void clear_zbuffer(ZBuffer* zbuf) {
    for (int i = 0; i < zbuf->width * zbuf->height; i++) {
        zbuf->depths[i] = INFINITY;
    }
}

// Free Z-buffer
static inline void destroy_zbuffer(ZBuffer* zbuf) {
    free(zbuf->depths);
    free(zbuf);
}

// 3D to 2D projection
static inline Vector2 project_point(
    Vector3 point,
    float fov,
    float aspect,
    float z_near) {
    float scale        = 1.0f / tanf(fov * 0.75f);
    float projection_x = (point.x * scale) / (point.z * aspect);
    float projection_y = (point.y * scale) / point.z;

    Vector2 screen;
    screen.x = (projection_x + 1.0f) * 0.5f;
    screen.y = (projection_y + 1.0f) * 0.5f;
    return screen;
}

// Compute lighting for a point on sphere
static inline float compute_lighting(
    Vector3 normal,
    Vector3 light_dir) {
    float ambient = 0.2f;  // 20% ambient light
    float diffuse = fmaxf(
        0.0f,
        normal.x * light_dir.x + normal.y * light_dir.y
            + normal.z * light_dir.z);

    return fminf(
        1.0f,
        ambient + diffuse * 0.8f);  // 80% diffuse light
}

// Create RGB color from components
#define RGB(r, g, b)                                    \
    ((Color)(((uint8_t)(r) << 16) | ((uint8_t)(g) << 8) \
             | ((uint8_t)(b))))
#define RGBA(r, g, b, a)                                 \
    ((Color)(((uint8_t)(a) << 24) | ((uint8_t)(r) << 16) \
             | ((uint8_t)(g) << 8) | ((uint8_t)(b))))

// Color component extraction
#define GET_RED(color) ((uint8_t)((color) >> 16))
#define GET_GREEN(color) ((uint8_t)((color) >> 8))
#define GET_BLUE(color) ((uint8_t)(color))
#define GET_ALPHA(color) ((uint8_t)((color) >> 24))

// Common colors
#define COLOR_BLACK RGB(0, 0, 0)
#define COLOR_WHITE RGB(255, 255, 255)
#define COLOR_RED RGB(255, 0, 0)
#define COLOR_GREEN RGB(0, 255, 0)
#define COLOR_BLUE RGB(0, 0, 255)

// Initialize frame buffer
static inline FrameBuffer* gfx_create_buffer(
    int width,
    int height) {
    FrameBuffer* fb = (FrameBuffer*)malloc(sizeof(FrameBuffer));
    if (!fb) return NULL;

    fb->width  = width;
    fb->height = height;
    fb->pitch  = width * sizeof(uint32_t);
    fb->pixels
        = (uint32_t*)calloc(width * height, sizeof(uint32_t));

    if (!fb->pixels) {
        free(fb);
        return NULL;
    }

    return fb;
}

// Clean up frame buffer
static inline void gfx_destroy_buffer(FrameBuffer* fb) {
    if (fb) {
        free(fb->pixels);
        free(fb);
    }
}

// Clear frame buffer to specific color
static inline void gfx_clear(FrameBuffer* fb, Color color) {
    for (int i = 0; i < fb->width * fb->height; i++) {
        fb->pixels[i] = color;
    }
}

// Set pixel at (x,y) to specified color
static inline void
gfx_put_pixel(FrameBuffer* fb, int x, int y, Color color) {
    if (x >= 0 && x < fb->width && y >= 0 && y < fb->height) {
        fb->pixels[y * fb->width + x] = color;
    }
}

// Draw horizontal line
static inline void
gfx_hline(FrameBuffer* fb, int x1, int x2, int y, Color color) {
    if (y < 0 || y >= fb->height) return;
    if (x1 > x2) {
        int t = x1;
        x1    = x2;
        x2    = t;
    }

    x1 = x1 < 0 ? 0 : x1;
    x2 = x2 >= fb->width ? fb->width - 1 : x2;

    for (int x = x1; x <= x2; x++) {
        fb->pixels[y * fb->width + x] = color;
    }
}

// Draw vertical line
static inline void
gfx_vline(FrameBuffer* fb, int x, int y1, int y2, Color color) {
    if (x < 0 || x >= fb->width) return;
    if (y1 > y2) {
        int t = y1;
        y1    = y2;
        y2    = t;
    }

    y1 = y1 < 0 ? 0 : y1;
    y2 = y2 >= fb->height ? fb->height - 1 : y2;

    for (int y = y1; y <= y2; y++) {
        fb->pixels[y * fb->width + x] = color;
    }
}

// Bresenham's line algorithm
static inline void gfx_line(
    FrameBuffer* fb,
    int x1,
    int y1,
    int x2,
    int y2,
    Color color) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        gfx_put_pixel(fb, x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x1 += sx;
        }
        if (e2 <= dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// Draw filled rectangle
static inline void gfx_fill_rect(
    FrameBuffer* fb,
    int x,
    int y,
    int width,
    int height,
    Color color) {
    int x2 = x + width - 1;
    int y2 = y + height - 1;

    // Clip rectangle
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x2 >= fb->width) x2 = fb->width - 1;
    if (y2 >= fb->height) y2 = fb->height - 1;

    // Draw horizontal lines
    for (int cy = y; cy <= y2; cy++) {
        gfx_hline(fb, x, x2, cy, color);
    }
}

// Draw circle using midpoint circle algorithm
static inline void gfx_circle(
    FrameBuffer* fb,
    int xc,
    int yc,
    int radius,
    Color color) {
    int x   = radius;
    int y   = 0;
    int err = 0;

    while (x >= y) {
        gfx_put_pixel(fb, xc + x, yc + y, color);
        gfx_put_pixel(fb, xc + y, yc + x, color);
        gfx_put_pixel(fb, xc - y, yc + x, color);
        gfx_put_pixel(fb, xc - x, yc + y, color);
        gfx_put_pixel(fb, xc - x, yc - y, color);
        gfx_put_pixel(fb, xc - y, yc - x, color);
        gfx_put_pixel(fb, xc + y, yc - x, color);
        gfx_put_pixel(fb, xc + x, yc - y, color);

        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        }
        if (err > 0) {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

// Fill circle using scanline algorithm
static inline void gfx_fill_circle(
    FrameBuffer* fb,
    int xc,
    int yc,
    int radius,
    Color color) {
    int x   = radius;
    int y   = 0;
    int err = 0;

    while (x >= y) {
        gfx_hline(fb, xc - x, xc + x, yc + y, color);
        gfx_hline(fb, xc - x, xc + x, yc - y, color);
        gfx_hline(fb, xc - y, xc + y, yc + x, color);
        gfx_hline(fb, xc - y, xc + y, yc - x, color);

        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        }
        if (err > 0) {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}

// Alpha blending function
static inline Color gfx_blend_colors(Color src, Color dst) {
    uint8_t alpha = GET_ALPHA(src);
    if (alpha == 0) return dst;
    if (alpha == 255) return src;

    uint8_t inv_alpha = 255 - alpha;

    uint8_t sr = GET_RED(src);
    uint8_t sg = GET_GREEN(src);
    uint8_t sb = GET_BLUE(src);

    uint8_t dr = GET_RED(dst);
    uint8_t dg = GET_GREEN(dst);
    uint8_t db = GET_BLUE(dst);

    uint8_t r = (sr * alpha + dr * inv_alpha) >> 8;
    uint8_t g = (sg * alpha + dg * inv_alpha) >> 8;
    uint8_t b = (sb * alpha + db * inv_alpha) >> 8;

    return RGB(r, g, b);
}

// Draw a 3D sphere with proper filling and lighting
static inline void gfx_sphere_3d(
    FrameBuffer* fb,
    Vector3 center,
    float radius,
    float rotation_x,
    float rotation_y,
    Color color,
    float fov,
    float aspect) {
    const int segments = 48;  // Increased resolution
    const float z_near = 0.1f;

    // Create and clear Z-buffer
    ZBuffer* zbuf = create_zbuffer(fb->width, fb->height);
    clear_zbuffer(zbuf);

    // Light direction (normalized)
    Vector3 light_dir
        = {0.577f, 0.577f, 0.577f};  // 45 degree angle light

    // Generate sphere points
    for (int i = 0; i <= segments; i++) {
        float lat = (float)i * M_PI / segments;
        for (int j = 0; j <= segments; j++) {
            float lon = (float)j * 2.0f * M_PI / segments;

            // Calculate point on sphere
            Vector3 normal
                = {sinf(lon) * sinf(lat),
                   cosf(lat),
                   cosf(lon) * sinf(lat)};

            Vector3 point
                = {normal.x * radius,
                   normal.y * radius,
                   normal.z * radius};

            // Apply rotation to point and normal
            float temp_y = point.y;
            point.y      = temp_y * cosf(rotation_x)
                      - point.z * sinf(rotation_x);
            point.z = temp_y * sinf(rotation_x)
                      + point.z * cosf(rotation_x);

            temp_y   = normal.y;
            normal.y = temp_y * cosf(rotation_x)
                       - normal.z * sinf(rotation_x);
            normal.z = temp_y * sinf(rotation_x)
                       + normal.z * cosf(rotation_x);

            float temp_x = point.x;
            point.x      = temp_x * cosf(rotation_y)
                      - point.z * sinf(rotation_y);
            point.z = temp_x * sinf(rotation_y)
                      + point.z * cosf(rotation_y);

            temp_x   = normal.x;
            normal.x = temp_x * cosf(rotation_y)
                       - normal.z * sinf(rotation_y);
            normal.z = temp_x * sinf(rotation_y)
                       + normal.z * cosf(rotation_y);

            // Translate
            point.x += center.x;
            point.y += center.y;
            point.z += center.z;

            // Only process points facing camera
            if (point.z > z_near) {
                // Project to 2D
                Vector2 screen
                    = project_point(point, fov, aspect, z_near);

                // Convert to pixel coordinates
                int px = (int)(screen.x * fb->width);
                int py = (int)(screen.y * fb->height);

                // Check if this point is closer than previous
                // points at this pixel
                if (px >= 0 && px < fb->width && py >= 0
                    && py < fb->height) {
                    int idx = py * fb->width + px;
                    if (point.z < zbuf->depths[idx]) {
                        zbuf->depths[idx] = point.z;

                        // Calculate lighting
                        float light = compute_lighting(
                            normal,
                            light_dir);

                        // Apply lighting to color
                        Color lit_color = RGB(
                            (int)(GET_RED(color) * light),
                            (int)(GET_GREEN(color) * light),
                            (int)(GET_BLUE(color) * light));

                        // Draw point with some thickness for
                        // better filling
                        for (int dy = -1; dy <= 1; dy++) {
                            for (int dx = -1; dx <= 1; dx++) {
                                int draw_x = px + dx;
                                int draw_y = py + dy;
                                if (draw_x >= 0
                                    && draw_x < fb->width
                                    && draw_y >= 0
                                    && draw_y < fb->height) {
                                    gfx_put_pixel(
                                        fb,
                                        draw_x,
                                        draw_y,
                                        lit_color);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    destroy_zbuffer(zbuf);
}

// 3D cube definition
static const Vector3 CUBE_VERTICES[8] = {
    {-1, -1, -1},  // 0: left  bottom back
    {1, -1, -1},   // 1: right bottom back
    {1, 1, -1},    // 2: right top    back
    {-1, 1, -1},   // 3: left  top    back
    {-1, -1, 1},   // 4: left  bottom front
    {1, -1, 1},    // 5: right bottom front
    {1, 1, 1},     // 6: right top    front
    {-1, 1, 1}     // 7: left  top    front
};

// Faces defined by vertex indices (two triangles per face)
static const int CUBE_FACES[12][3] = {
    // Front face
    {4, 5, 6},
    {4, 6, 7},
    // Back face
    {1, 0, 3},
    {1, 3, 2},
    // Right face
    {5, 1, 2},
    {5, 2, 6},
    // Left face
    {0, 4, 7},
    {0, 7, 3},
    // Top face
    {7, 6, 2},
    {7, 2, 3},
    // Bottom face
    {4, 0, 1},
    {4, 1, 5}};

// Face normals for lighting
static const Vector3 FACE_NORMALS[6] = {
    {0, 0, 1},   // Front
    {0, 0, -1},  // Back
    {1, 0, 0},   // Right
    {-1, 0, 0},  // Left
    {0, 1, 0},   // Top
    {0, -1, 0}   // Bottom
};

// Fill a triangle with z-buffer checking and lighting
static inline void fill_triangle(
    FrameBuffer* fb,
    ZBuffer* zbuf,
    Vector2 p1,
    Vector2 p2,
    Vector2 p3,
    float z1,
    float z2,
    float z3,
    Color color,
    float light_intensity) {
    // Find bounding box
    int minX = (int)fminf(fminf(p1.x, p2.x), p3.x);
    int maxX = (int)fmaxf(fmaxf(p1.x, p2.x), p3.x);
    int minY = (int)fminf(fminf(p1.y, p2.y), p3.y);
    int maxY = (int)fmaxf(fmaxf(p1.y, p2.y), p3.y);

    // Clip to screen
    minX = fmaxf(minX, 0);
    maxX = fminf(maxX, fb->width - 1);
    minY = fmaxf(minY, 0);
    maxY = fminf(maxY, fb->height - 1);

    // Triangle setup
    Vector2 v0  = {p2.x - p1.x, p2.y - p1.y};
    Vector2 v1  = {p3.x - p1.x, p3.y - p1.y};
    float d00   = v0.x * v0.x + v0.y * v0.y;
    float d01   = v0.x * v1.x + v0.y * v1.y;
    float d11   = v1.x * v1.x + v1.y * v1.y;
    float denom = d00 * d11 - d01 * d01;

    if (fabsf(denom) < 1e-6) return;  // Degenerate triangle

    // Apply lighting to color
    Color lit_color = RGB(
        (int)(GET_RED(color) * light_intensity),
        (int)(GET_GREEN(color) * light_intensity),
        (int)(GET_BLUE(color) * light_intensity));

    // Rasterize
    for (int y = minY; y <= maxY; y++) {
        for (int x = minX; x <= maxX; x++) {
            Vector2 p = {x - p1.x, y - p1.y};
            float dp0 = p.x * v0.x + p.y * v0.y;
            float dp1 = p.x * v1.x + p.y * v1.y;
            float v   = (d11 * dp0 - d01 * dp1) / denom;
            float w   = (d00 * dp1 - d01 * dp0) / denom;
            float u   = 1.0f - v - w;

            if (u >= 0 && v >= 0 && w >= 0) {
                // Interpolate Z
                float z = u * z1 + v * z2 + w * z3;
                int idx = y * fb->width + x;

                if (z < zbuf->depths[idx]) {
                    zbuf->depths[idx] = z;
                    gfx_put_pixel(fb, x, y, lit_color);
                }
            }
        }
    }
}

// Draw a 3D cube with proper rotation, faces, and lighting
static inline void gfx_cube_3d(
    FrameBuffer* fb,
    Vector3 center,
    float size,
    float rotation_x,
    float rotation_y,
    Color color,
    float fov,
    float aspect) {
    Vector3 vertices[8];
    Vector2 projected[8];
    Vector3 rotated_normals[6];

    // Create Z-buffer
    ZBuffer* zbuf = create_zbuffer(fb->width, fb->height);
    clear_zbuffer(zbuf);

    // Light direction (normalized)
    Vector3 light_dir
        = {0.577f, 0.577f, 0.577f};  // 45 degree angle light

    // Transform vertices
    for (int i = 0; i < 8; i++) {
        // Scale
        vertices[i].x = CUBE_VERTICES[i].x * size;
        vertices[i].y = CUBE_VERTICES[i].y * size;
        vertices[i].z = CUBE_VERTICES[i].z * size;

        // Rotate X
        float temp_y  = vertices[i].y;
        vertices[i].y = temp_y * cosf(rotation_x)
                        - vertices[i].z * sinf(rotation_x);
        vertices[i].z = temp_y * sinf(rotation_x)
                        + vertices[i].z * cosf(rotation_x);

        // Rotate Y
        float temp_x  = vertices[i].x;
        vertices[i].x = temp_x * cosf(rotation_y)
                        - vertices[i].z * sinf(rotation_y);
        vertices[i].z = temp_x * sinf(rotation_y)
                        + vertices[i].z * cosf(rotation_y);

        // Translate
        vertices[i].x += center.x;
        vertices[i].y += center.y;
        vertices[i].z += center.z;

        // Project to 2D
        projected[i]
            = project_point(vertices[i], fov, aspect, 0.1f);
        projected[i].x *= fb->width;
        projected[i].y *= fb->height;
    }

    // Rotate face normals
    for (int i = 0; i < 6; i++) {
        Vector3 normal = FACE_NORMALS[i];

        // Rotate X
        float temp_y = normal.y;
        normal.y     = temp_y * cosf(rotation_x)
                   - normal.z * sinf(rotation_x);
        normal.z = temp_y * sinf(rotation_x)
                   + normal.z * cosf(rotation_x);

        // Rotate Y
        float temp_x = normal.x;
        normal.x     = temp_x * cosf(rotation_y)
                   - normal.z * sinf(rotation_y);
        normal.z = temp_x * sinf(rotation_y)
                   + normal.z * cosf(rotation_y);

        rotated_normals[i] = normal;
    }

    // Draw faces (2 triangles each)
    for (int face = 0; face < 6; face++) {
        // Calculate lighting for this face
        float light
            = compute_lighting(rotated_normals[face], light_dir);
        light = fmaxf(0.2f, light);  // Add ambient light

        // Draw the two triangles that make up this face
        for (int tri = 0; tri < 2; tri++) {
            int idx = face * 2 + tri;
            int v1  = CUBE_FACES[idx][0];
            int v2  = CUBE_FACES[idx][1];
            int v3  = CUBE_FACES[idx][2];

            // Only draw if all points are in front of the camera
            if (vertices[v1].z > 0.1f && vertices[v2].z > 0.1f
                && vertices[v3].z > 0.1f) {
                fill_triangle(
                    fb,
                    zbuf,
                    projected[v1],
                    projected[v2],
                    projected[v3],
                    vertices[v1].z,
                    vertices[v2].z,
                    vertices[v3].z,
                    color,
                    light);
            }
        }
    }

    destroy_zbuffer(zbuf);
}
#endif  // SIMPLEGFX_H