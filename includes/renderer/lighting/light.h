#ifndef PGFX_RENDERER_LIGHTING_LIGHT_H
#define PGFX_RENDERER_LIGHTING_LIGHT_H

#include "../math/vector.h"

// Light types
typedef enum {
    LIGHT_DIRECTIONAL,
    LIGHT_POINT,
    LIGHT_SPOT
} LightType;

typedef struct {
    LightType type;
    Vec3 position;   // Used for point and spot lights
    Vec3 direction;  // Used for directional and spot lights
    Vec3 color;
    float intensity;
    float range;      // For point/spot lights
    float spotAngle;  // For spot lights
} Light;

// Light creation helpers
Light create_directional_light(Vec3 direction, Vec3 color, float intensity);
Light create_point_light(Vec3 position, Vec3 color, float intensity, float range);
Light create_spot_light(Vec3 position, Vec3 direction, Vec3 color, float intensity, float range, float spotAngle);

#endif // PGFX_RENDERER_LIGHTING_LIGHT_H