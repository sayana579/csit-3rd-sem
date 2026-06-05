#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <stdio.h>

// Updated draw function to handle coordinates and RGB color
void draw(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    // DIFFERENT VALUES: Larger HD window and updated title
    SDL_Window *window = SDL_CreateWindow(
        "Painter's Algorithm ",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280, 720, 
        SDL_WINDOW_OPENGL);

    SDL_GLContext context = SDL_GL_CreateContext(window);

    // DIFFERENT VALUE: Deep Navy background color
    glClearColor(0.05f, 0.1f, 0.2f, 1.0f);

    // Setup 2D projection (orthographic)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1280, 720, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);

    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = 0;
        }

        glClear(GL_COLOR_BUFFER_BIT);

        /* 
           PAINTER'S ALGORITHM: 
           Draw shapes from back to front.
        */
        
        // 1. Furthest object (Red Square)
        draw(400, 200, 300, 300, 0.8f, 0.1f, 0.1f);

        // 2. Middle object (Green Square) - overlaps Red
        draw(500, 300, 300, 300, 0.1f, 0.8f, 0.1f);

        // 3. Closest object (Blue Square) - overlaps Green and Red
        draw(600, 400, 300, 300, 0.1f, 0.1f, 0.8f);

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
