#include "renderer/shaders/shader_library.h"
#include <stdio.h>
#include <string.h>

// Default 3D shader with lighting
static const char* default_3d_vertex_source = 
    "#version 130\n"
    "in vec3 position;\n"
    "in vec3 normal;\n"
    "out vec3 fragPos;\n"
    "out vec3 fragNormal;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main() {\n"
    "    fragPos = vec3(model * vec4(position, 1.0));\n"
    "    fragNormal = mat3(model) * normal;\n"
    "    gl_Position = projection * view * model * vec4(position, 1.0);\n"
    "}\n";

static const char* default_3d_fragment_source =
    "#version 130\n"
    "in vec3 fragPos;\n"
    "in vec3 fragNormal;\n"
    "out vec4 outColor;\n"
    "struct Light {\n"
    "    int type;\n"
    "    vec3 position;\n"
    "    vec3 direction;\n"
    "    vec3 color;\n"
    "    float intensity;\n"
    "    float range;\n"
    "    float spotAngle;\n"
    "};\n"
    "struct Material {\n"
    "    vec3 ambient;\n"
    "    vec3 diffuse;\n"
    "    vec3 specular;\n"
    "    float shininess;\n"
    "};\n"
    "uniform Light lights[8];\n"
    "uniform int lightCount;\n"
    "uniform Material material;\n"
    "uniform vec3 viewPos;\n"
    "void main() {\n"
    "    vec3 norm = normalize(fragNormal);\n"
    "    vec3 result = vec3(0.0);\n"
    "    \n"
    "    for(int i = 0; i < lightCount; i++) {\n"
    "        vec3 lightDir;\n"
    "        float attenuation = 1.0;\n"
    "        \n"
    "        if(lights[i].type == 0) {\n"
    "            lightDir = normalize(-lights[i].direction);\n"
    "        } else {\n"
    "            lightDir = normalize(lights[i].position - fragPos);\n"
    "            float distance = length(lights[i].position - fragPos);\n"
    "            attenuation = 1.0 / (1.0 + 0.09 * distance + 0.032 * distance * distance);\n"
    "        }\n"
    "        \n"
    "        float diff = max(dot(norm, lightDir), 0.0);\n"
    "        vec3 diffuse = lights[i].color * (diff * material.diffuse);\n"
    "        \n"
    "        vec3 viewDir = normalize(viewPos - fragPos);\n"
    "        vec3 reflectDir = reflect(-lightDir, norm);\n"
    "        float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);\n"
    "        vec3 specular = lights[i].color * (spec * material.specular);\n"
    "        \n"
    "        vec3 ambient = lights[i].color * material.ambient;\n"
    "        \n"
    "        result += (ambient + diffuse + specular) * lights[i].intensity * attenuation;\n"
    "    }\n"
    "    \n"
    "    outColor = vec4(result, 1.0);\n"
    "}\n";

// Unlit shader (no lighting calculations)
static const char* unlit_vertex_source =
    "#version 130\n"
    "in vec3 position;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main() {\n"
    "    gl_Position = projection * view * model * vec4(position, 1.0);\n"
    "}\n";

static const char* unlit_fragment_source =
    "#version 130\n"
    "uniform vec4 color;\n"
    "out vec4 outColor;\n"
    "void main() {\n"
    "    outColor = color;\n"
    "}\n";

// Debug visualization shader
static const char* debug_vertex_source =
    "#version 130\n"
    "in vec3 position;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main() {\n"
    "    gl_Position = projection * view * model * vec4(position, 1.0);\n"
    "}\n";

static const char* debug_fragment_source =
    "#version 130\n"
    "uniform vec4 debugColor;\n"
    "out vec4 outColor;\n"
    "void main() {\n"
    "    outColor = debugColor;\n"
    "}\n";

bool shader_library_init(ShaderLibrary* library) {
    if (!library) return false;
    
    library->initialized = false;

    // Create default 3D shader
    library->shaders[SHADER_TYPE_DEFAULT_3D] = 
        shader_create_from_source(default_3d_vertex_source, default_3d_fragment_source);
    if (!shader_is_valid(&library->shaders[SHADER_TYPE_DEFAULT_3D])) {
        return false;
    }

    // Create unlit shader
    library->shaders[SHADER_TYPE_UNLIT] = 
        shader_create_from_source(unlit_vertex_source, unlit_fragment_source);
    if (!shader_is_valid(&library->shaders[SHADER_TYPE_UNLIT])) {
        shader_destroy(&library->shaders[SHADER_TYPE_DEFAULT_3D]);
        return false;
    }

    // Create debug shader
    library->shaders[SHADER_TYPE_DEBUG] = 
        shader_create_from_source(debug_vertex_source, debug_fragment_source);
    if (!shader_is_valid(&library->shaders[SHADER_TYPE_DEBUG])) {
        shader_destroy(&library->shaders[SHADER_TYPE_DEFAULT_3D]);
        shader_destroy(&library->shaders[SHADER_TYPE_UNLIT]);
        return false;
    }

    library->initialized = true;
    return true;
}

void shader_library_destroy(ShaderLibrary* library) {
    if (!library || !library->initialized) return;

    for (int i = 0; i < SHADER_TYPE_COUNT; i++) {
        shader_destroy(&library->shaders[i]);
    }

    library->initialized = false;
}

Shader* shader_library_get(ShaderLibrary* library, ShaderType type) {
    if (!library || !library->initialized || type >= SHADER_TYPE_COUNT) {
        return NULL;
    }
    
    return &library->shaders[type];
}

const char* shader_type_to_string(ShaderType type) {
    switch (type) {
        case SHADER_TYPE_DEFAULT_3D: return "Default 3D";
        case SHADER_TYPE_UNLIT: return "Unlit";
        case SHADER_TYPE_SKYBOX: return "Skybox";
        case SHADER_TYPE_DEBUG: return "Debug";
        default: return "Unknown";
    }
}