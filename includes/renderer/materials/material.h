#ifndef PGFX_RENDERER_MATERIALS_MATERIAL_H
#define PGFX_RENDERER_MATERIALS_MATERIAL_H

#include "../math/vector.h"

typedef struct {
    Vec3 ambient;
    Vec3 diffuse;
    Vec3 specular;
    float shininess;
} Material;

static inline Material material_create(Vec3 ambient, Vec3 diffuse, Vec3 specular, float shininess) {
    return (Material){ambient, diffuse, specular, shininess};
}

#endif // PGFX_RENDERER_MATERIALS_MATERIAL_H