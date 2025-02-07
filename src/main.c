#include <stdio.h>
#include <stdlib.h>
#include "renderer/core/renderer.h"

static void error_exit(const char* msg, GLRenderer* renderer) {
    fprintf(stderr, "Error: %s - %s\n", msg, gl_renderer_get_error(renderer));
    gl_renderer_destroy(renderer);
    exit(1);
}

int main(void) {
    // Create a simple window configuration
    GLRendererConfig config = gl_renderer_config_default();
    config.window_title = "PGFX Window";
    config.window_width = 800;
    config.window_height = 600;

    // Create and initialize renderer
    GLRenderer* renderer = gl_renderer_create(&config);
    if (!renderer) {
        fprintf(stderr, "Failed to create renderer\n");
        return 1;
    }

    // Initialize OpenGL context and resources
    GLRendererError err = gl_renderer_init(renderer, &config);
    if (err != GL_RENDERER_SUCCESS) {
        error_exit("Failed to initialize renderer", renderer);
    }

    // Main loop
    while (gl_renderer_is_running(renderer)) {
        gl_renderer_process_events(renderer);
        gl_renderer_begin_frame(renderer);
        
        // Clear window with dark gray
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        gl_renderer_end_frame(renderer);
    }

    gl_renderer_destroy(renderer);
    return 0;
}