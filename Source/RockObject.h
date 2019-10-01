#pragma once
#include "../Libraries/Framework/Source/FrameworkPCH.h"
#include "GameObject.h"

class RockObject : public GameObject
{
public:
    RockObject();
    ~RockObject();
    void Init();
    void Update(float deltaTime);
    void Draw(fw::ShaderProgram* p_Shader, float right, float up);
    void SetAttributes(fw::ShaderProgram* p_Shader);
    int numberOfVerts = 0;
    float m_right = 0.0f;
    float m_up = 0.0f;
    GLuint m_VBO;
};