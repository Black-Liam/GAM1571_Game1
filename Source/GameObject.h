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
    GameObject(int VBO);
    ~GameObject();
    void Init();
    void Update(float deltaTime);
    void Draw();

    int numberOfVerts = 0;
    GLuint m_VBO;
};