#pragma once
#include "GameObject.h"

class RockObject : public GameObject
{

public:
    RockObject();
    ~RockObject();
    void Init(const Game* g, Mesh* m, fw::ShaderProgram* sp, vec2 pos);
    virtual void Update(float deltaTime, fw::Framework* p_Frame) override;
    void Draw();
};