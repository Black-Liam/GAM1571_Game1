#pragma once
#include "../Libraries/Framework/Source/FrameworkPCH.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "RockObject.h"

class Game :
    public fw::GameCore
{
protected:
    GLuint m_VBO;
    fw::ShaderProgram* m_pShader;
    fw::Framework* m_pFramework;
    PlayerObject* m_Player;
    RockObject* m_Rock1; 
    RockObject* m_Rock2;
    RockObject* m_Rock3;
    RockObject* m_Rock4;
    RockObject* m_Rock5;
public:
    Game(fw::Framework* pFramework);
    ~Game();
    void Init() override;
    void Update(float deltaTime) override;
    void Draw() override;
    float m_right = 0.0f;
    float m_up = 0.0f;
    float speed = 1.0f;

    
    
};
