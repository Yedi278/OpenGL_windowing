#include "Display.hpp"
#include <iostream>

Display::Display(int width, int height, const std::string& title)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL failed to initialize.\n" << SDL_GetError() << std::endl;
        return;
    }else{
        std::cout << "SDL initialized successfully.\n";
    }

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    if (m_window == nullptr)
    {
        std::cerr << "SDL failed to create window.\n" << SDL_GetError() << std::endl;
        return;
    }

    m_glContext = SDL_GL_CreateContext(m_window);
    if (m_glContext == nullptr)
    { 
        std::cerr << "SDL failed to create renderer.\n" << SDL_GetError() << std::endl;
        return;
    }


    GLenum status = glewInit();
    if (status != GLEW_OK)
    {
        std::cerr << "GLEW failed to initialize.\n" << glewGetErrorString(status) << std::endl;
        return;
    }

    running = true;
}

Display::~Display()
{
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Display::Update()
{
    SDL_GL_SwapWindow(m_window);

    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            running = false;
        }
    }
}

void Display::Background(float r, float g, float b, float a){

    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
    
}