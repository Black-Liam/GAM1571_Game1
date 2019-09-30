#pragma once
#include "../Libraries/Framework/Source/FrameworkPCH.h"

typedef unsigned char uint8;

struct VertexFormat
{
    float x, y;
    uint8 r, g, b, a;

    VertexFormat(float X, float Y, uint8 R, uint8 G, uint8 B, uint8 A)
        :x(X), y(Y), r(R), g(G), b(B), a(A) {}
};

class GameObject
{
public:
    GameObject();
    ~GameObject();
    void Init();
    void Update(float deltaTime);
    void Draw(fw::ShaderProgram* p_Shader, float right, float up);
    void SetAttributes(fw::ShaderProgram* p_Shader);
    int numberOfVerts = 0;
    float m_right = 0.0f;
    float m_up = 0.0f;
    GLuint m_VBO;
};