#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#include <emscripten/console.h>
#endif

// Define SDL window and renderer
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

// Default screen width and height
Uint32 SCREEN_WIDTH = 1920;
Uint32 SCREEN_HEIGHT = 960;

// Handle screen resize
void resize_window(int width, int height) {
    // Set the global width and height variables
    SCREEN_WIDTH = width;
    SCREEN_HEIGHT = height;
    SDL_SetWindowSize(window, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Create a puffer to be printed
    char buffer[50];
    sprintf(buffer, "Resized to Width: %d, Height: %d\n", SCREEN_WIDTH, SCREEN_HEIGHT);
    // print based on the environment
    #ifdef __EMSCRIPTEN__
    emscripten_console_log(buffer);
    #else
    printf("%s", buffer);
    #endif
}

// Handle events from SDL2
void event_handler() {
    // SDL Event to be handled
    SDL_Event event;

    // Handle Event by comparing type
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            // Handle emscripten quit behavior
            #ifdef __EMSCRIPTEN__
            emscripten_cancel_main_loop();
            #else
            // Handle native quit behavior
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            #endif
            // Common quit behavior
            SDL_Quit();
            exit(0);
        // Handle SDL Window Resized
        } else if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) {
            resize_window(event.window.data1, event.window.data2);
        }
    }
}

// Create Main Update Loop
static void update(void) {
    // crate timestamps for handling framerate (static last_time persists out of scope)
    static Uint32 last_time = SDL_GetTicks();
    Uint32 current_time = SDL_GetTicks();
    float elapsed_time = (current_time - last_time) / 1000.0f;
    last_time = current_time;

    // Handle SDL Events
    event_handler();

    // Clear the renderer with background color
    SDL_SetRenderDrawColor(renderer, 40, 42, 54, 255);
    SDL_RenderClear(renderer);

    // Present the renderer
    SDL_RenderPresent(renderer);
}

// Main Program entrypoint
int main(int argc, char** argv) {
    // Initialize SDL in video mode
    SDL_Init(SDL_INIT_VIDEO);
    // Create SDL Window
    window = SDL_CreateWindow(
        "Falling Sand",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        SDL_WINDOW_RESIZABLE
    );
    // Create SDL Renderer
    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    // SDL JS Configuration with Emscripten
    #ifdef TEST_SDL_LOCK_OPTS
    EM_ASM({SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFront = false;});
    #endif
    // Set last time before entering the main loop
    static Uint32 last_time = SDL_GetTicks();
    // Run update function with emscripten (using browsers refresh rate)
    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(update, 0, 1);
    #else
    // Run native update loop
    while (1) { update(); }
    #endif
    // returns success
    return 0;
}
