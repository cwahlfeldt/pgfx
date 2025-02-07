#ifndef PGFX_RENDERER_OBJECTS_PRIMITIVE_CACHE_H
#define PGFX_RENDERER_OBJECTS_PRIMITIVE_CACHE_H

#include <stdbool.h>
#include "primitives.h"

typedef struct {
    Primitive cube;
    Primitive plane;
    Primitive sphere;
    Primitive cylinder;
    bool initialized;
} PrimitiveCache;

bool primitive_cache_init(PrimitiveCache* cache);
void primitive_cache_destroy(PrimitiveCache* cache);

// Get primitives (creates if not exists)
Primitive* primitive_cache_get_cube(PrimitiveCache* cache);
Primitive* primitive_cache_get_plane(PrimitiveCache* cache);
Primitive* primitive_cache_get_sphere(PrimitiveCache* cache);
Primitive* primitive_cache_get_cylinder(PrimitiveCache* cache);

#endif // PGFX_RENDERER_OBJECTS_PRIMITIVE_CACHE_H