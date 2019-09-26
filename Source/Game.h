#pragma once
#include "../Libraries/Framework/Source/FrameworkPCH.h"
#include "GameObject.h"
typedef unsigned char uint8;

struct VertexFormat;

class Game :
    public fw::GameCore
{
protected:
    GLuint m_VBO;
    fw::ShaderProgram* m_pShader;
    fw::Framework* m_pFramework;
    GameObject* m_Player;
    GameObject* m_Other;
public:
    Game(fw::Framework* pFramework);
    ~Game();
    void Init() override;
    void Update(float deltaTime) override;
    void Draw() override;
    float m_timer = 0.0f;
    float m_right = 0.0f;
    float m_up = 0.0f;
    float speed = 1.0f;

    
    
};
