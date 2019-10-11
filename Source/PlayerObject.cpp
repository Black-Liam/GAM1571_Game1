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

void PlayerObject::Init(const Game* g, Mesh* m, fw::ShaderProgram* sp, vec2 pos)
{
    m_pGame = g;
    m_pShader = sp;
    m_pMesh = m;
    m_Position = pos;
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
