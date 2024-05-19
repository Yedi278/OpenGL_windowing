#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <GL/glew.h>

class Shader{


public:
    Shader(const std::string& fileName);

    void Bind();

    ~Shader();

private:
    static const unsigned int NUM_SHADERS = 2;
    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];  
};