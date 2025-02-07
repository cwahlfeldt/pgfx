#ifndef PGFX_RENDERER_SHADERS_SHADER_LIBRARY_H
#define PGFX_RENDERER_SHADERS_SHADER_LIBRARY_H

#include "shader.h"

// Common shader types
typedef enum {
    SHADER_TYPE_DEFAULT_3D,    // Basic 3D shader with lighting
    SHADER_TYPE_UNLIT,         // Simple shader without lighting
    SHADER_TYPE_SKYBOX,        // For rendering skyboxes
    SHADER_TYPE_DEBUG,         // For debug visualization
    SHADER_TYPE_COUNT          // Keep track of shader count
} ShaderType;

typedef struct {
    Shader shaders[SHADER_TYPE_COUNT];
    bool initialized;
} ShaderLibrary;

// Initialize and cleanup
bool shader_library_init(ShaderLibrary* library);
void shader_library_destroy(ShaderLibrary* library);

// Get shaders
Shader* shader_library_get(ShaderLibrary* library, ShaderType type);

// Utility functions
const char* shader_type_to_string(ShaderType type);

#endif // PGFX_RENDERER_SHADERS_SHADER_LIBRARY_H