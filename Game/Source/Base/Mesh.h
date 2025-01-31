#ifndef __Mesh_H__
#define __Mesh_H__

#include "VertexFormat.h"

class fw::ShaderProgram;
class Camera;

class Mesh
{
protected:
    GLuint m_VBO;
    unsigned int m_NumVerts;
    GLenum m_PrimitiveType;

public:
    Mesh();
    ~Mesh();

    void Init(VertexFormat* pVerts, unsigned int numVerts, GLenum primitiveType);
    void Draw(Camera* pCamera, fw::ShaderProgram* pShader, fw::vec2 pos, GLuint textureID);

    void GenerateTriangle();
    void GenerateCircle();
    void GeneratePlayer();
    void GenerateSquare(float sideLength);
};

#endif //__Mesh_H__
