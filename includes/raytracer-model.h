#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <math.h>
#include <stdint.h>

#include "common.h"
#include "model_loader.h"

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
// Combine all intersection tests
static inline float scene_intersect(
    Ray ray,
    Sphere* spheres,
    int sphere_count,
    Mesh** meshes,
    int mesh_count,
    Vec3* hit_normal,
    Vec3* hit_color,
    float* hit_specular,
    float* hit_reflective) {
    float closest_t = INFINITY;
    *hit_normal     = (Vec3){0, 0, 0};

    // Test spheres
    for (int i = 0; i < sphere_count; i++) {
        float t = sphere_intersect(spheres[i], ray);
        if (t > 0.001f && t < closest_t) {
            closest_t      = t;
            Vec3 hit_point = vec3_add(
                ray.origin,
                vec3_mul(ray.direction, t));
            *hit_normal = vec3_normalize(
                vec3_sub(hit_point, spheres[i].center));
            *hit_color      = spheres[i].color;
            *hit_specular   = spheres[i].specular;
            *hit_reflective = spheres[i].reflective;
        }
    }

    // Test meshes
    for (int i = 0; i < mesh_count; i++) {
        Vec3 mesh_normal;
        float t = mesh_intersect(meshes[i], ray, &mesh_normal);
        if (t > 0.001f && t < closest_t) {
            closest_t       = t;
            *hit_normal     = mesh_normal;
            *hit_color      = meshes[i]->color;
            *hit_specular   = meshes[i]->specular;
            *hit_reflective = meshes[i]->reflective;
        }
    }

    return closest_t < INFINITY ? closest_t : -1;
}

// Updated trace_ray function
static inline Vec3 trace_ray(
    Ray ray,
    Sphere* spheres,
    int sphere_count,
    Mesh** meshes,
    int mesh_count,
    Light* lights,
    int light_count,
    int depth) {
    if (depth <= 0) return vec3(0, 0, 0);

    Vec3 hit_normal, hit_color;
    float hit_specular, hit_reflective;

    float closest_t = scene_intersect(
        ray,
        spheres,
        sphere_count,
        meshes,
        mesh_count,
        &hit_normal,
        &hit_color,
        &hit_specular,
        &hit_reflective);

    if (closest_t < 0) return vec3(0, 0, 0);

    Vec3 hit_point = vec3_add(
        ray.origin,
        vec3_mul(ray.direction, closest_t));

    float intensity = compute_lighting(
        hit_point,
        hit_normal,
        vec3_mul(ray.direction, -1.0f),
        hit_specular,
        lights,
        light_count,
        spheres,
        sphere_count);

    Vec3 color = vec3_mul(hit_color, intensity);

    if (hit_reflective > 0 && depth > 0) {
        float r_dot_n    = vec3_dot(ray.direction, hit_normal);
        Vec3 reflect_dir = vec3_sub(
            ray.direction,
            vec3_mul(hit_normal, 2.0f * r_dot_n));
        Ray reflect_ray    = make_ray(hit_point, reflect_dir);
        Vec3 reflect_color = trace_ray(
            reflect_ray,
            spheres,
            sphere_count,
            meshes,
            mesh_count,
            lights,
            light_count,
            depth - 1);
        color = vec3_add(
            vec3_mul(color, 1.0f - hit_reflective),
            vec3_mul(reflect_color, hit_reflective));
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