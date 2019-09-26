#pragma once
#include "../Libraries/Framework/Source/FrameworkPCH.h"


class GameObject
{
public:
    GameObject(GLuint VBO);
    ~GameObject();
    void Init();
    void Update(float deltaTime);
    void Draw(fw::ShaderProgram* p_Shader);

    int numberOfVerts = 0;
    GLuint m_VBO;
};