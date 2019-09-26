#pragma once
#include "../Libraries/Framework/Source/FrameworkPCH.h"

typedef unsigned char uint8;

struct VertexFormat
{
    float x, y;
    uint8 r, g, b, a;

    VertexFormat(float X, float Y, uint8 R, uint8 G, uint8 B, uint8 A)
        :x(X),y(Y),r(R),g(G),b(B),a(A){}
};

class Game :
    public fw::GameCore
{
protected:
    GLuint m_VBO;
    fw::ShaderProgram* m_pShader;
    fw::Framework* m_pFramework;
public:
    Game(fw::Framework* pFramework);
    ~Game();
    void Init() override;
    void Update(float deltaTime) override;
    void Draw() override;
    float m_timer = 0.0f;
    float m_right = 0.0f;
    float m_up = 0.0f;
    double sec = 0;
    double prevSec = 0;
    float speed = 1.0f;
    
};
