#pragma once
#include "GameObject.h"


class GoalObject : public GameObject
{

public:
    GoalObject();
    ~GoalObject();
    void Init(const Game* g, Mesh* m, fw::ShaderProgram* sp, vec2 pos);
    virtual void Update(float deltaTime, fw::Framework* p_Frame) override;
    void Draw();
};