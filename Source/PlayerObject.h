#pragma once
#include "GameObject.h"


class PlayerObject : public GameObject
{
private:
    Game* m_pGame;
    Mesh* m_pMesh;
    fw::ShaderProgram* m_pShader;
    vec2 m_Position;
public:
    PlayerObject();
    ~PlayerObject();
    void Init();
    virtual void Update(float deltaTime, fw::Framework* p_Frame) override;
    void Draw();
    float speed = 1.0f;
    GLuint m_VBO;
};