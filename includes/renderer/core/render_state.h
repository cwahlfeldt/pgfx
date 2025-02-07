#ifndef PGFX_RENDERER_CORE_RENDER_STATE_H
#define PGFX_RENDERER_CORE_RENDER_STATE_H

#include <GL/gl3w.h>
#include <stdbool.h>

typedef enum {
    BLEND_MODE_NONE,
    BLEND_MODE_ALPHA,
    BLEND_MODE_ADDITIVE,
    BLEND_MODE_MULTIPLY
} BlendMode;

typedef enum {
    DEPTH_MODE_NONE,
    DEPTH_MODE_READ,
    DEPTH_MODE_WRITE,
    DEPTH_MODE_READ_WRITE
} DepthMode;

typedef enum {
    CULL_MODE_NONE,
    CULL_MODE_BACK,
    CULL_MODE_FRONT
} CullMode;

typedef struct {
    BlendMode blend_mode;
    DepthMode depth_mode;
    CullMode cull_mode;
    bool wireframe;
} RenderState;

// Create default render state
RenderState render_state_create_default(void);

// Apply render state
void render_state_apply(const RenderState* state);

// State modification functions
void render_state_set_blend_mode(RenderState* state, BlendMode mode);
void render_state_set_depth_mode(RenderState* state, DepthMode mode);
void render_state_set_cull_mode(RenderState* state, CullMode mode);
void render_state_set_wireframe(RenderState* state, bool enabled);

#endif // PGFX_RENDERER_CORE_RENDER_STATE_H