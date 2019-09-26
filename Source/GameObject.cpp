#include "GameObject.h"

GameObject::GameObject(GLuint VBO)
{
    m_VBO = VBO;
}

GameObject::~GameObject()
{
}

void GameObject::Init()
{
}

void GameObject::Update(float deltaTime)
{
}

void GameObject::Draw(fw::ShaderProgram* p_Shader)
{
    GLint loc = glGetAttribLocation(p_Shader->GetProgram(), "a_Position");
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 12, (void*)0); //Stride: 2*4byte floats + 4*1byte usigned chars

    GLint cloc = glGetAttribLocation(p_Shader->GetProgram(), "a_Color");
    glEnableVertexAttribArray(cloc);
    glVertexAttribPointer(cloc, 4, GL_UNSIGNED_BYTE, GL_TRUE, 12, (void*)8); //Offset: Skip the 2*4byte floats
}
