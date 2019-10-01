#pragma once
#include "../Libraries/Framework/Source/FrameworkPCH.h"
#include "GameObject.h"


class PlayerObject : public GameObject
{
public:
    PlayerObject();
    ~PlayerObject();
    void Init();
    void Update(float deltaTime, fw::Framework* p_Frame);
    void Draw(fw::ShaderProgram* p_Shader, float right, float up);
    void SetAttributes(fw::ShaderProgram* p_Shader);
    int numberOfVerts = 0;
    float m_right = 0.0f;
    float m_up = 0.0f;
    float speed = 1.0f;
    GLuint m_VBO;
};