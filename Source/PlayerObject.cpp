#include "GamePCH.h"
#include "PlayerObject.h"
#include "GameObject.h"
#include "Mesh.h"
#include "Game.h"
#include "PlayerController.h"

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
    if (m_pGame->m_playCont->dwFlag)
    {
        m_Position.y -= deltaTime * speed;
    }
    if (m_pGame->m_playCont->upFlag)
    {
        m_Position.y += deltaTime * speed;
    }
    if (m_pGame->m_playCont->lfFlag)
    {
        m_Position.x -= deltaTime * speed;
    }
    if (m_pGame->m_playCont->rtFlag)
    {
        m_Position.x += deltaTime * speed;
    }

}

void PlayerObject::Draw()
{
   
}
