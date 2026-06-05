#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

int main(int argc, char* args[]) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create a window
    SDL_Window* window = SDL_CreateWindow(
        "OpenGL & Triangle",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_OPENGL
    );

    // Create an OpenGL context
    SDL_GLContext context = SDL_GL_CreateContext(window);

    int isrunning = 1;
    SDL_Event event;

    // Main loop
    while (isrunning) {
        // Event handling
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                isrunning = 0;
            }
        }

        // Rendering
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Clear color to black
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
        // Changed color to blue (R, G, B)
        glColor3f(0.0, 0.0, 1.0);

        // Define vertices of the triangle
        glVertex2f(0.0f, 0.5f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);

        glEnd();

        // Swap buffers to display the rendered image
        SDL_GL_SwapWindow(window);
    }

    // Cleanup
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
