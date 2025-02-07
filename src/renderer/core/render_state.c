#include "renderer/core/render_state.h"
#include <stdio.h>

RenderState render_state_create_default(void) {
    return (RenderState){
        .blend_mode = BLEND_MODE_ALPHA,
        .depth_mode = DEPTH_MODE_READ_WRITE,
        .cull_mode = CULL_MODE_BACK,
        .wireframe = false
    };
}

static void apply_blend_mode(BlendMode mode) {
    switch (mode) {
        case BLEND_MODE_NONE:
            glDisable(GL_BLEND);
            break;
        case BLEND_MODE_ALPHA:
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            break;
        case BLEND_MODE_ADDITIVE:
            glEnable(GL_BLEND);
            glBlendFunc(GL_ONE, GL_ONE);
            break;
        case BLEND_MODE_MULTIPLY:
            glEnable(GL_BLEND);
            glBlendFunc(GL_DST_COLOR, GL_ZERO);
            break;
    }
}

static void apply_depth_mode(DepthMode mode) {
    switch (mode) {
        case DEPTH_MODE_NONE:
            glDisable(GL_DEPTH_TEST);
            glDepthMask(GL_FALSE);
            break;
        case DEPTH_MODE_READ:
            glEnable(GL_DEPTH_TEST);
            glDepthMask(GL_FALSE);
            break;
        case DEPTH_MODE_WRITE:
            glDisable(GL_DEPTH_TEST);
            glDepthMask(GL_TRUE);
            break;
        case DEPTH_MODE_READ_WRITE:
            glEnable(GL_DEPTH_TEST);
            glDepthMask(GL_TRUE);
            break;
    }
}

static void apply_cull_mode(CullMode mode) {
    switch (mode) {
        case CULL_MODE_NONE:
            glDisable(GL_CULL_FACE);
            break;
        case CULL_MODE_BACK:
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            break;
        case CULL_MODE_FRONT:
            glEnable(GL_CULL_FACE);
            glCullFace(GL_FRONT);
            break;
    }
}

void render_state_apply(const RenderState* state) {
    if (!state) return;

    apply_blend_mode(state->blend_mode);
    apply_depth_mode(state->depth_mode);
    apply_cull_mode(state->cull_mode);
    
    glPolygonMode(GL_FRONT_AND_BACK, state->wireframe ? GL_LINE : GL_FILL);

    // Enable depth test by default for 3D rendering
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    
    printf("Applying render state:\n");
    printf("  Blend mode: %d\n", state->blend_mode);
    printf("  Depth mode: %d\n", state->depth_mode);
    printf("  Cull mode: %d\n", state->cull_mode);
    printf("  Wireframe: %d\n", state->wireframe);
}

void render_state_set_blend_mode(RenderState* state, BlendMode mode) {
    if (!state) return;
    state->blend_mode = mode;
}

void render_state_set_depth_mode(RenderState* state, DepthMode mode) {
    if (!state) return;
    state->depth_mode = mode;
}

void render_state_set_cull_mode(RenderState* state, CullMode mode) {
    if (!state) return;
    state->cull_mode = mode;
}

void render_state_set_wireframe(RenderState* state, bool enabled) {
    if (!state) return;
    state->wireframe = enabled;
}