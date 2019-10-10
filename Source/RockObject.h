#pragma once
#include "GameObject.h"

class RockObject : public GameObject
{
private:
    Game* m_pGame;
    Mesh* m_pMesh;
    fw::ShaderProgram* m_pShader;
    vec2 m_Position;
public:
    RockObject();
    ~RockObject();
    void Init();
    virtual void Update(float deltaTime, fw::Framework* p_Frame) override;
    void Draw();
};