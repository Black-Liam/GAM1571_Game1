#pragma once
#include "GameObject.h"


class PlayerObject : public GameObject
{

public:
    PlayerObject();
    ~PlayerObject();
    void Init(const Game* g, Mesh* m, fw::ShaderProgram* sp, vec2 pos);
    virtual void Update(float deltaTime, fw::Framework* p_Frame) override;
    void Draw();
    float speed = 1.0f;
};