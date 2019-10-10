#include "GamePCH.h"
#include "PlayerObject.h"
#include "GameObject.h"
#include "Mesh.h"

PlayerObject::PlayerObject()
{
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::Init()
{
    GLenum pt = GL_TRIANGLES;
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

    VertexFormat(-5.0f,     -15.0f,   0x00,   0x00,   0x80,   0xFF),
    VertexFormat(5.0f,     -15.0f,   0x00,   0x00,   0x80,   0xFF),
    VertexFormat(5.0f,     5.0f,   0x00,   0x00,   0x80,   0xFF),
    VertexFormat(-5.0f,     -15.0f,   0x00,   0x00,   0x80,   0xFF),
    VertexFormat(-5.0f,     5.0f,   0x00,   0x00,   0x80,   0xFF),
    VertexFormat(5.0f,     5.0f,   0x00,   0x00,   0x80,   0xFF),
    };
    uint32 nv = 24;
    m_pMesh->Init(Attribs, nv, pt);
    
}

void PlayerObject::Update(float deltaTime, fw::Framework* p_Frame)
{
    if (p_Frame->IsKeyDown(VK_UP)&& p_Frame->IsKeyDown(VK_LEFT))
    {
        m_Position.y += deltaTime * speed * sqrtf(0.5f);
        m_Position.x -= deltaTime * speed * sqrtf(0.5f);
    }
    else if (p_Frame->IsKeyDown(VK_UP) && p_Frame->IsKeyDown(VK_RIGHT))
    {
        m_Position.y += deltaTime * speed * sqrtf(0.5f);
        m_Position.x += deltaTime * speed * sqrtf(0.5f);
    }
    else if (p_Frame->IsKeyDown(VK_DOWN)&& p_Frame->IsKeyDown(VK_RIGHT))
    {
        m_Position.x += deltaTime * speed * sqrtf(0.5f);
        m_Position.y -= deltaTime * speed * sqrtf(0.5f);
    }
    else if (p_Frame->IsKeyDown(VK_DOWN) && p_Frame->IsKeyDown(VK_LEFT))
    {
        m_Position.x -= deltaTime * speed * sqrtf(0.5f);
        m_Position.y -= deltaTime * speed * sqrtf(0.5f);
    }
    else if (p_Frame->IsKeyDown(VK_UP))
    {
        m_Position.y += deltaTime * speed;
    }
    else if(p_Frame->IsKeyDown(VK_DOWN))
    {
        m_Position.y -= deltaTime * speed;
    }
    else if(p_Frame->IsKeyDown(VK_LEFT))
    {
        m_Position.x -= deltaTime * speed;
    }
    else if(p_Frame->IsKeyDown(VK_RIGHT))
    {
        m_Position.x += deltaTime * speed;
    }
    if (p_Frame->IsKeyDown(VK_SPACE))
    {
        m_Position.y = 0.0f;
        m_Position.x = 0.0f;
    }

}

void PlayerObject::Draw()
{
   
}
