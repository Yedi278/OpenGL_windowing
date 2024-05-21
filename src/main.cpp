#include "Display.hpp"
#include "Shader.hpp"
#include "Mesh.hpp"
#include <GL/glew.h>
#include <iostream>

int main(void)
{
    Display display(800, 600, "Basic OpenGL Window");

    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    
    Vertex verteces[] = {Vertex(glm::vec3(-0.5, -0.5,   0)),
                         Vertex(glm::vec3(0,    0.5, 0)),
                         Vertex(glm::vec3(0.5,  -0.5, 0))};

    Mesh mesh(verteces, sizeof(verteces)/sizeof(verteces[0]));
    Shader shader("./res/basicShader");

    while(display.running)
    {   
        display.Background(0.f, 0.2f, 0.2f);
        shader.Bind();
        mesh.Draw();
        display.Update();

    }

    return 0;
}