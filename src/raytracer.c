#include "raytracer.h"

#include <SDL_cosmo.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 764

typedef struct {
    Vec3 position;
    float yaw;    // Left/right rotation
    float pitch;  // Up/down rotation
    float move_speed;
    float mouse_sensitivity;
} Camera;

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
    SDL_Window* window = SDL_CreateWindow(
        "Raytracer Demo",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED);
    SDL_Texture* texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        WIDTH,
        HEIGHT);

    // Setup scene
    Sphere spheres[]
        = {// Center sphere - red, specular, reflective
           {.center     = {0, 0, 5},
            .radius     = 1,
            .color      = {1, 0, 0},
            .specular   = 500,
            .reflective = 0.3f},
           // Left sphere - blue, less specular
           {.center     = {-2, 0, 4},
            .radius     = 0.7f,
            .color      = {0, 0, 1},
            .specular   = 100,
            .reflective = 0.1f},
           // Right sphere - green, very reflective
           {.center     = {2, 0, 4},
            .radius     = 0.7f,
            .color      = {0, 1, 0},
            .specular   = 300,
            .reflective = 0.5f},
           // Floor sphere - grey, slightly reflective
           {.center     = {0, -501, 5},
            .radius     = 500,
            .color      = {0.5f, 0.5f, 0.5f},
            .specular   = 1000,
            .reflective = 0.1f}};

    Light lights[] = {
        {.position = {-5, 5, 0}, .intensity = 0.4f},
        {.position = {5, 5, 0}, .intensity = 0.4f},
    };

    const int sphere_count
        = sizeof(spheres) / sizeof(spheres[0]);
    const int light_count = sizeof(lights) / sizeof(lights[0]);

    uint32_t* pixels = malloc(WIDTH * HEIGHT * sizeof(uint32_t));
    float aspect     = (float)WIDTH / HEIGHT;
    float fov        = M_PI / 3.0f;  // 60 degrees
    float fov_tan    = tanf(fov / 2.0f);

    int running           = 1;
    float camera_rotation = 0.0f;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Rotate camera around the scene
        camera_rotation += 0.02f;
        Vec3 camera_pos
            = {sinf(camera_rotation) * 3,
               1,
               cosf(camera_rotation) * 3};
        Vec3 camera_target = {0, 0, 5};
        Vec3 camera_dir    = vec3_normalize(
            vec3_sub(camera_target, camera_pos));
        Vec3 camera_right = vec3_normalize(
            vec3(camera_dir.z, 0, -camera_dir.x));
        Vec3 camera_up = vec3_normalize(vec3_sub(
            vec3(0, 1, 0),
            vec3_mul(camera_dir, camera_dir.y)));

// Render scene
#pragma omp parallel for collapse(2)
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                float screen_x
                    = (2.0f * (x + 0.5f) / WIDTH - 1.0f) * aspect
                      * fov_tan;
                float screen_y
                    = (1.0f - 2.0f * (y + 0.5f) / HEIGHT)
                      * fov_tan;

                Vec3 ray_dir = vec3_normalize(vec3_add(
                    vec3_add(
                        vec3_mul(camera_right, screen_x),
                        vec3_mul(camera_up, screen_y)),
                    camera_dir));

                Ray ray    = make_ray(camera_pos, ray_dir);
                Vec3 color = trace_ray(
                    ray,
                    spheres,
                    sphere_count,
                    lights,
                    light_count,
                    3);
                pixels[y * WIDTH + x] = vec3_to_color(color);
            }
        }

        SDL_UpdateTexture(
            texture,
            NULL,
            pixels,
            WIDTH * sizeof(uint32_t));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    free(pixels);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}