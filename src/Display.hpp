#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <GL/glew.h>

class Display
{
private:
    SDL_Window* m_window;
    SDL_GLContext m_glContext;

public:

    bool running = false;

    Display(int width, int height, const std::string& title);

    void Update();
    void Background(float r, float g, float b, float a = 1.0f);

    ~Display();
};