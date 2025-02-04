#include <SDL_cosmo.h>
#include <stdio.h>

#include "simplegfx.h"

#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 764

int main() {
    if (SDL_CosmoInit() != 0) {
        printf("Error: %s\n", SDL_CosmoGetError());
        return 1;
    }

    // Setup SDL
    if (SDL_Init(
            SDL_INIT_VIDEO | SDL_INIT_TIMER
            | SDL_INIT_GAMECONTROLLER)
        != 0) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window     = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture   = NULL;
    FrameBuffer* fb        = NULL;

    window = SDL_CreateWindow(
        "3D Cube Demo",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED);
    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        WINDOW_WIDTH,
        WINDOW_HEIGHT);

    fb = gfx_create_buffer(WINDOW_WIDTH, WINDOW_HEIGHT);

    float rotation_x = 0.0f;
    float rotation_y = 0.0f;
    int mouse_down   = 0;
    int prev_x = 0, prev_y = 0;

    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        mouse_down = 1;
                        prev_x     = event.button.x;
                        prev_y     = event.button.y;
                    }
                    break;

                case SDL_MOUSEBUTTONUP:
                    if (event.button.button == SDL_BUTTON_LEFT) {
                        mouse_down = 0;
                    }
                    break;

                case SDL_MOUSEMOTION:
                    if (mouse_down) {
                        int dx = event.motion.x - prev_x;
                        int dy = event.motion.y - prev_y;

                        rotation_y += dx * 0.01f;
                        rotation_x += dy * 0.01f;

                        prev_x = event.motion.x;
                        prev_y = event.motion.y;
                    }
                    break;
            }
        }

        // Clear and draw rotating 3D cube
        gfx_clear(fb, COLOR_BLACK);

        Vector3 center = {0.0f, 0.0f, 4.0f};  // Moved back a bit
        float size     = 1.0f;
        float fov      = M_PI / 4.0f;  // 45 degrees
        float aspect   = (float)WINDOW_WIDTH / WINDOW_HEIGHT;

        gfx_cube_3d(
            fb,
            center,
            size,
            rotation_x,
            rotation_y,
            COLOR_BLUE,
            fov,
            aspect);

        // Update texture with our frame buffer
        SDL_UpdateTexture(texture, NULL, fb->pixels, fb->pitch);

        // Render
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    gfx_destroy_buffer(fb);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
