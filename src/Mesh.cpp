#include "Mesh.hpp"

Mesh::Mesh(Vertex* verteces, unsigned int numVerteces){

    m_drawCount = numVerteces;

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVerteces * sizeof(verteces[0]), verteces, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

void Mesh::Draw(){
    glBindVertexArray(m_vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);

    glBindVertexArray(0);

}

Mesh::~Mesh(){
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}