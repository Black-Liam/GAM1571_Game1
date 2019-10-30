#pragma once

typedef unsigned int uint32;
typedef unsigned char uint8;


struct VertexFormat
{
    float x, y;
    uint8 r, g, b, a;

    VertexFormat(float X, float Y, uint8 R, uint8 G, uint8 B, uint8 A)
        :x(X), y(Y), r(R), g(G), b(B), a(A) {}
};

class CameraObject;

class Mesh
{
private:
    GLuint m_VBO;
    GLenum m_primType;
    uint32 numberOfVerts;
public:
    void Init(VertexFormat* vf, uint32 nv, GLenum pt);
    void Draw(fw::ShaderProgram*, vec2 pos, CameraObject* c);
};