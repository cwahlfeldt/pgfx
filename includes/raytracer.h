#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <float.h>
#include <math.h>
#include <stdint.h>

typedef struct {
    float x, y, z;
} Vec3;

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

// Vector operations
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

// Ray operations
static inline Ray make_ray(Vec3 origin, Vec3 direction) {
    return (Ray){origin, vec3_normalize(direction)};
}

// Returns distance along ray to intersection, or -1 if no hit
static inline float sphere_intersect(Sphere sphere, Ray ray) {
    Vec3 oc = vec3_sub(ray.origin, sphere.center);
    float a = vec3_dot(ray.direction, ray.direction);
    float b = 2.0f * vec3_dot(oc, ray.direction);
    float c = vec3_dot(oc, oc) - sphere.radius * sphere.radius;
    float discriminant = b * b - 4 * a * c;

    if (discriminant < 0) return -1;

    float t1 = (-b - sqrtf(discriminant)) / (2.0f * a);
    float t2 = (-b + sqrtf(discriminant)) / (2.0f * a);

    if (t1 > 0.001f) return t1;
    if (t2 > 0.001f) return t2;
    return -1;
}

// Compute lighting at a point
static inline float compute_lighting(
    Vec3 point,
    Vec3 normal,
    Vec3 view,
    float specular,
    Light* lights,
    int light_count,
    Sphere* spheres,
    int sphere_count) {
    float intensity = 0.0f;
    float ambient   = 0.2f;
    intensity += ambient;

    for (int i = 0; i < light_count; i++) {
        Vec3 light_dir = vec3_sub(lights[i].position, point);
        float light_distance = vec3_length(light_dir);
        light_dir            = vec3_normalize(light_dir);

        // Shadow check
        Ray shadow_ray = make_ray(point, light_dir);
        int in_shadow  = 0;

        for (int j = 0; j < sphere_count; j++) {
            float t = sphere_intersect(spheres[j], shadow_ray);
            if (t > 0.001f && t < light_distance) {
                in_shadow = 1;
                break;
            }
        }

        if (!in_shadow) {
            // Diffuse
            float n_dot_l = vec3_dot(normal, light_dir);
            if (n_dot_l > 0) {
                intensity += lights[i].intensity * n_dot_l;
            }

            // Specular
            if (specular > 0) {
                Vec3 reflect_dir = vec3_sub(
                    vec3_mul(normal, 2.0f * n_dot_l),
                    light_dir);
                float r_dot_v = vec3_dot(reflect_dir, view);
                if (r_dot_v > 0) {
                    intensity += lights[i].intensity
                                 * powf(r_dot_v, specular);
                }
            }
        }
    }

    return intensity;
}

// Trace a ray through the scene
static inline Vec3 trace_ray(
    Ray ray,
    Sphere* spheres,
    int sphere_count,
    Light* lights,
    int light_count,
    int depth) {
    if (depth <= 0) return vec3(0, 0, 0);

    float closest_t    = FLT_MAX;
    int closest_sphere = -1;

    // Find closest intersection
    for (int i = 0; i < sphere_count; i++) {
        float t = sphere_intersect(spheres[i], ray);
        if (t > 0.001f && t < closest_t) {
            closest_t      = t;
            closest_sphere = i;
        }
    }

    if (closest_sphere == -1) return vec3(0, 0, 0);

    // Compute intersection point and normal
    Vec3 point = vec3_add(
        ray.origin,
        vec3_mul(ray.direction, closest_t));
    Vec3 normal = vec3_normalize(
        vec3_sub(point, spheres[closest_sphere].center));

    // Compute lighting
    float intensity = compute_lighting(
        point,
        normal,
        vec3_mul(ray.direction, -1.0f),
        spheres[closest_sphere].specular,
        lights,
        light_count,
        spheres,
        sphere_count);

    Vec3 color
        = vec3_mul(spheres[closest_sphere].color, intensity);

    // Compute reflection
    if (spheres[closest_sphere].reflective > 0 && depth > 0) {
        float r_dot_n    = vec3_dot(ray.direction, normal);
        Vec3 reflect_dir = vec3_sub(
            ray.direction,
            vec3_mul(normal, 2.0f * r_dot_n));
        Ray reflect_ray    = make_ray(point, reflect_dir);
        Vec3 reflect_color = trace_ray(
            reflect_ray,
            spheres,
            sphere_count,
            lights,
            light_count,
            depth - 1);
        color = vec3_add(
            vec3_mul(
                color,
                1.0f - spheres[closest_sphere].reflective),
            vec3_mul(
                reflect_color,
                spheres[closest_sphere].reflective));
    }

    return color;
}

// Convert color components to uint32_t ARGB
static inline uint32_t vec3_to_color(Vec3 v) {
    int r = fminf(fmaxf(v.x * 255, 0), 255);
    int g = fminf(fmaxf(v.y * 255, 0), 255);
    int b = fminf(fmaxf(v.z * 255, 0), 255);
    return (0xFF << 24) | (r << 16) | (g << 8) | b;
}

#endif  // RAYTRACER_H