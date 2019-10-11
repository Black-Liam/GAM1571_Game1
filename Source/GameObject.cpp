#include "GamePCH.h"
#include "GameObject.h"
#include "Mesh.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Init(const Game* g, Mesh* m, fw::ShaderProgram* sp, vec2 pos)
{
    m_pGame = g;
    m_pShader = sp;
    m_pMesh = m;
    m_Position = pos;
}


void GameObject::Draw()
{
    m_pMesh->Draw(m_pShader, m_Position);
}


