#include "GamePCH.h"
#include "PlayerObject.h"
#include "GameObject.h"

PlayerObject::PlayerObject()
{
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::Init()
{
    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    VertexFormat Attribs[] =
    {
    VertexFormat(-5.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-5.0f,     15.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(5.0f,     15.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-5.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(5.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(5.0f,     15.0f,   0xff,   0xff,   0x00,   0xFF),

    VertexFormat(5.0f,     -5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(5.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(10.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(5.0f,     -5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(10.0f,     -5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(10.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),

    VertexFormat(-10.0f,     -5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-10.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-5.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-10.0f,     -5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-5.0f,     -5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-5.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),

    VertexFormat(-5.0f,     -15.0f,   0x00,   0xbc,   0x8a,   0xFF),
    VertexFormat(5.0f,     -15.0f,   0xf0,   0xf7,   0x09,   0xFF),
    VertexFormat(5.0f,     5.0f,   0xeb,   0x34,   0x0a,   0xFF),
    VertexFormat(-5.0f,     -15.0f,   0x00,   0xbc,   0x8a,   0xFF),
    VertexFormat(-5.0f,     5.0f,   0x7e,   0x07,   0x85,   0xFF),
    VertexFormat(5.0f,     5.0f,   0xeb,   0x34,   0x0a,   0xFF),

    };
    numberOfVerts = sizeof(Attribs) / sizeof(VertexFormat);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * numberOfVerts, Attribs, GL_STATIC_DRAW);
    
}

void PlayerObject::Update(float deltaTime, fw::Framework* p_Frame)
{
    if (p_Frame->IsKeyDown(VK_UP)&& p_Frame->IsKeyDown(VK_LEFT))
    {
        m_up += deltaTime * speed * (float)sqrt(0.5);
        m_right -= deltaTime * speed * (float)sqrt(0.5);
    }
    else if (p_Frame->IsKeyDown(VK_UP) && p_Frame->IsKeyDown(VK_RIGHT))
    {
        m_up += deltaTime * speed * (float)sqrt(0.5);
        m_right += deltaTime * speed * (float)sqrt(0.5);
    }
    else if(p_Frame->IsKeyDown(VK_DOWN) && p_Frame->IsKeyDown(VK_LEFT))
    {
        m_up -= deltaTime * speed * (float)sqrt(0.5);
        m_right -= deltaTime * speed * (float)sqrt(0.5);
    }
    else if(p_Frame->IsKeyDown(VK_DOWN) && p_Frame->IsKeyDown(VK_RIGHT))
    {
        m_up -= deltaTime * speed * (float)sqrt(0.5);
        m_right += deltaTime * speed * (float)sqrt(0.5);
    }
    else if (p_Frame->IsKeyDown(VK_UP))
    {
        m_up += deltaTime * speed;
    }
    else if(p_Frame->IsKeyDown(VK_DOWN))
    {
        m_up -= deltaTime * speed;
    }
    else if(p_Frame->IsKeyDown(VK_LEFT))
    {
        m_right -= deltaTime * speed;
    }
    else if(p_Frame->IsKeyDown(VK_RIGHT))
    {
        m_right += deltaTime * speed;
    }

    if (p_Frame->IsKeyDown(VK_SPACE))
    {
        m_up = 0.0f;
        m_right = 0.0f;
    }

}

void PlayerObject::Draw(fw::ShaderProgram* p_Shader, float right, float up)
{
    glUseProgram(p_Shader->GetProgram());

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    SetAttributes(p_Shader);

    GLint uXloc = glGetUniformLocation(p_Shader->GetProgram(), "u_XOffset");
    glUniform1f(uXloc, m_right);
    GLint uYloc = glGetUniformLocation(p_Shader->GetProgram(), "u_YOffset");
    glUniform1f(uYloc, m_up);

    glDrawArrays(GL_TRIANGLES, 0, numberOfVerts);
}

void PlayerObject::SetAttributes(fw::ShaderProgram* p_Shader)
{
    GameObject::SetAttributes(p_Shader);
}
