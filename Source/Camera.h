#pragma once
#include "GameObject.h"


class CameraObject : public GameObject
{

public:
    CameraObject();
    ~CameraObject();
    void CamInit(const Game* g, fw::ShaderProgram* sp, vec2 pos);
    virtual void Update(float deltaTime, fw::Framework* p_Frame) override;
    void Draw();
    GameObject* Focus;
};
/*
Focus GameObject*
Update


*/
