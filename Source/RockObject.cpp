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

void RockObject::Init()
{
    GLenum pt = GL_TRIANGLE_FAN;
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
    uint32 nv = 8;
    m_pMesh->Init(Attribs, nv, pt);

    /*VertexFormat Attribs[] =
    {
    VertexFormat(0.0f,     0.0f,   0x30,   0x30,   0x30,   0xFF),
    VertexFormat(-10.0f,    10.0f,   0x60,   0x60,   0x60,   0xFF),
    VertexFormat(5.0f,     10.0f,  0x60,   0x60,   0x60,   0xFF),
    VertexFormat(15.0f,    0.0f,   0x60,   0x60,   0x60,   0xFF),
    VertexFormat(10.0f,    -10.0f,   0x60,   0x60,   0x60,   0xFF),
    VertexFormat(-5.0f,    -10.0f,   0x60,   0x60,   0x60,   0xFF),
    VertexFormat(-15.0f,    0.0f,  0x60,   0x60,   0x60,   0xFF),
    VertexFormat(-10.0f,    10.0f,   0x60,   0x60,   0x60,   0xFF),
    };*/
}

void RockObject::Update(float deltaTime, fw::Framework* p_Frame)
{
}

void RockObject::Draw()
{

}
