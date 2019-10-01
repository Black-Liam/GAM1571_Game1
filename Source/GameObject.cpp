#include "GamePCH.h"
#include "GameObject.h"

GameObject::GameObject()
{
    m_VBO = 0;
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

void GameObject::Draw(fw::ShaderProgram* p_Shader, float right, float up)
{
    glUseProgram(p_Shader->GetProgram());

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    SetAttributes(p_Shader);

    GLint uXloc = glGetUniformLocation(p_Shader->GetProgram(), "u_XOffset");
    glUniform1f(uXloc, right);
    GLint uYloc = glGetUniformLocation(p_Shader->GetProgram(), "u_YOffset");
    glUniform1f(uYloc, up);

    glDrawArrays(GL_TRIANGLES, 0, numberOfVerts);
}

void GameObject::SetAttributes(fw::ShaderProgram* p_Shader)
{
    GLint loc = glGetAttribLocation(p_Shader->GetProgram(), "a_Position");
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 12, (void*)0); //Stride: 2*4byte floats + 4*1byte usigned chars

    GLint cloc = glGetAttribLocation(p_Shader->GetProgram(), "a_Color");
    glEnableVertexAttribArray(cloc);
    glVertexAttribPointer(cloc, 4, GL_UNSIGNED_BYTE, GL_TRUE, 12, (void*)8); //Offset: Skip the 2*4byte floats
}
