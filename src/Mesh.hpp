#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex{
private:
    glm::vec3 m_position; 

public:
    Vertex(const glm::vec3& position){
        this->m_position = position;
    }

};

class Mesh{

private:

    enum{
        POSITION_VB,
        NUM_BUFFERS
    };

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;

public:
    Mesh(Vertex* verteces, unsigned int numVerteces);

    void Draw();


    ~Mesh();
};