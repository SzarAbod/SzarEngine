#include <application.hpp>
#include <log.hpp>

#include <SDL3/SDL.h>

constexpr int WINDOW_WIDTH = 800;
constexpr int WINDOW_HEIGHT = 600;

namespace szar {
    /**
     * @brief Constructs the Application and initializes the logging subsystem.
     *
     * Initializes the logging subsystem used by the application so logging is available
     * for the application's lifetime.
     */
    Application::Application() 
    {
        szar::Log::Init();

    }
    
    /**
 * @brief Default destructor for Application.
 *
 * Performs no special cleanup; relies on member destructors and RAII to release resources.
 */
Application::~Application() {}
    
    /**
     * @brief Starts the application's main loop, creates the window and renderer, and renders a centered white rectangle.
     *
     * Initializes the SDL video subsystem, creates a resizable window and renderer, then runs the event/render loop until a quit event or Escape key press ends execution. Each frame the screen is cleared to black and a 100x100 white rectangle is drawn centered in the window. On exit, the renderer and window are destroyed and SDL is shut down.
     */
    void Application::Run() {
        // Initialize SDL
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
            return;
        }

        // Create window
        SDL_Window* window = SDL_CreateWindow(
            "SDL3 Application",
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_RESIZABLE
        );

        if (!window) {
            SDL_Log("Failed to create window: %s", SDL_GetError());
            SDL_Quit();
            return;
        }
        // Create renderer
        SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

        if (!renderer) {
            SDL_Log("Failed to create renderer: %s", SDL_GetError());
            SDL_DestroyWindow(window);
            SDL_Quit();
            return;
        }

        // Main loop
        bool running = true;
        SDL_Event event;

        while (running) {
            // Handle events
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    if (event.key.key == SDLK_ESCAPE) {
                        running = false;
                    }
                    break;
                }
            }

            // Clear screen
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            // Draw something (e.g., a white rectangle)
            SDL_FRect rect = {
                WINDOW_WIDTH / 2.0f - 50,
                WINDOW_HEIGHT / 2.0f - 50,
                100,
                100
            };
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect);

            // Present
            SDL_RenderPresent(renderer);
        }

        // Cleanup
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}