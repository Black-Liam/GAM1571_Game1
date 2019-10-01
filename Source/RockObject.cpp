#include "RockObject.h"
#include "GameObject.h"


RockObject::RockObject()
{
}

RockObject::~RockObject()
{
}

void RockObject::Init()
{
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    VertexFormat Attribs[] =
    {
    VertexFormat(0.0f,     0.0f,   0x30,   0x30,   0x30,   0xFF),
    VertexFormat(-10.0f,    10.0f,   0x60,   0x60,   0x60,   0xFF),
    VertexFormat(5.0f,     10.0f,  0x60,   0x60,   0x60,   0xFF),
    VertexFormat(15.0f,    0.0f,   0x60,   0x60,   0x60,   0xFF),
    VertexFormat(10.0f,    -10.0f,   0x60,   0x60,   0x60,   0xFF),
    VertexFormat(-5.0f,    -10.0f,   0x60,   0x60,   0x60,   0xFF),
    VertexFormat(-15.0f,    0.0f,  0x60,   0x60,   0x60,   0xFF),
    VertexFormat(-10.0f,    10.0f,   0x60,   0x60,   0x60,   0xFF),
    };
    numberOfVerts = sizeof(Attribs) / sizeof(VertexFormat);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * numberOfVerts, Attribs, GL_STATIC_DRAW);
}

void RockObject::Draw(fw::ShaderProgram* p_Shader, float right, float up)
{
    glUseProgram(p_Shader->GetProgram());

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    SetAttributes(p_Shader);

    GLint uXloc = glGetUniformLocation(p_Shader->GetProgram(), "u_XOffset");
    glUniform1f(uXloc, right);
    GLint uYloc = glGetUniformLocation(p_Shader->GetProgram(), "u_YOffset");
    glUniform1f(uYloc, up);

    glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVerts);
}

void RockObject::SetAttributes(fw::ShaderProgram* p_Shader)
{
    GameObject::SetAttributes(p_Shader);
}
