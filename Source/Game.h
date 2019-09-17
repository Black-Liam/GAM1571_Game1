#pragma once
#include "../Libraries/Framework/Source/FrameworkPCH.h"

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
    void Update() override;
    void Draw() override;
    float m_timer = 0.0f;
    float m_up = 0.0f;
    
    
};
