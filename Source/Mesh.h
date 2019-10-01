#pragma once

class Mesh
{
private:
    GLuint m_VBO;
    GLenum m_primType;
    int numberOfVerts;
public:
    void Draw();
};