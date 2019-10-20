#include "GamePCH.h"
#include "GoalObject.h"

GoalObject::GoalObject()
{
}

GoalObject::~GoalObject()
{
}

void GoalObject::Init(const Game* g, Mesh* m, fw::ShaderProgram* sp, vec2 pos)
{
    m_pGame = g;
    m_pShader = sp;
    m_pMesh = m;
    m_Position = pos;
}

void GoalObject::Update(float deltaTime, fw::Framework* p_Frame)
{
}

void GoalObject::Draw()
{
}
