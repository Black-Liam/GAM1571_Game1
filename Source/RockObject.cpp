#include "GamePCH.h"
#include "RockObject.h"
#include "GameObject.h"
#include "Mesh.h"

RockObject::RockObject()
{
}

RockObject::~RockObject()
{
}

void RockObject::Init(const Game* g, Mesh* m, fw::ShaderProgram* sp, vec2 pos)
{
    m_pGame = g;
    m_pShader = sp;
    m_pMesh = m;
    m_Position = pos;
}

void RockObject::Update(float deltaTime, fw::Framework* p_Frame)
{
}

void RockObject::Draw()
{

}
