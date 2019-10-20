#include "GamePCH.h"
#include "Camera.h"

CameraObject::CameraObject()
{
}

CameraObject::~CameraObject()
{
}

void CameraObject::CamInit(const Game* g, fw::ShaderProgram* sp, vec2 pos)
{
    m_pGame = g;
    m_pShader = sp;
    m_pMesh = nullptr;
    m_Position = pos;
}

void CameraObject::Update(float deltaTime, fw::Framework* p_Frame)
{
    m_Position = Focus->m_Position;
}

void CameraObject::Draw()
{
}
