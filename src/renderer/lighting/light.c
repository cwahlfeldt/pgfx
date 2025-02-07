#include "renderer/lighting/light.h"
#include "renderer/math/vector.h"

Light create_directional_light(Vec3 direction, Vec3 color, float intensity) {
    return (Light){
        .type = LIGHT_DIRECTIONAL,
        .direction = vec3_normalize(direction),
        .color = color,
        .intensity = intensity,
        .range = 0.0f,  // Not used for directional lights
        .spotAngle = 0.0f  // Not used for directional lights
    };
}

Light create_point_light(Vec3 position, Vec3 color, float intensity, float range) {
    return (Light){
        .type = LIGHT_POINT,
        .position = position,
        .color = color,
        .intensity = intensity,
        .range = range,
        .spotAngle = 0.0f  // Not used for point lights
    };
}

Light create_spot_light(Vec3 position, Vec3 direction, Vec3 color, float intensity, float range, float spotAngle) {
    return (Light){
        .type = LIGHT_SPOT,
        .position = position,
        .direction = vec3_normalize(direction),
        .color = color,
        .intensity = intensity,
        .range = range,
        .spotAngle = spotAngle
    };
}