#include "renderer/objects/primitive_cache.h"
#include <string.h>

bool primitive_cache_init(PrimitiveCache* cache) {
    if (!cache) return false;
    
    // Initialize to zero
    memset(cache, 0, sizeof(PrimitiveCache));
    cache->initialized = true;
    
    return true;
}

void primitive_cache_destroy(PrimitiveCache* cache) {
    if (!cache || !cache->initialized) return;

    destroy_primitive(&cache->cube);
    destroy_primitive(&cache->plane);
    destroy_primitive(&cache->sphere);
    destroy_primitive(&cache->cylinder);

    cache->initialized = false;
}

Primitive* primitive_cache_get_cube(PrimitiveCache* cache) {
    if (!cache || !cache->initialized) return NULL;
    
    if (cache->cube.vao == 0) {
        cache->cube = create_cube_primitive();
    }
    
    return &cache->cube;
}

Primitive* primitive_cache_get_plane(PrimitiveCache* cache) {
    if (!cache || !cache->initialized) return NULL;
    
    if (cache->plane.vao == 0) {
        cache->plane = create_plane_primitive();
    }
    
    return &cache->plane;
}

Primitive* primitive_cache_get_sphere(PrimitiveCache* cache) {
    if (!cache || !cache->initialized) return NULL;
    
    if (cache->sphere.vao == 0) {
        cache->sphere = create_sphere_primitive();
    }
    
    return &cache->sphere;
}

Primitive* primitive_cache_get_cylinder(PrimitiveCache* cache) {
    if (!cache || !cache->initialized) return NULL;
    
    if (cache->cylinder.vao == 0) {
        cache->cylinder = create_cylinder_primitive();
    }
    
    return &cache->cylinder;
}