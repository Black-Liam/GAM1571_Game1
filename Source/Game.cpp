#include "GamePCH.h"
#include "Game.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "RockObject.h"

Game::Game(fw::Framework* pFramework) : GameCore(pFramework)
{
    m_pFramework = pFramework;

    //m_pShaders[0];
    //m_pMeshes[0];
    //m_pGameObjects[0];

    //1 can I make one in the vector, or do I make it and pass it in?
    //2 where should the new calls be?


}

Game::~Game()
{
    for (int i = 0; i < m_pShaders.size(); i++)
    {
        delete m_pShaders[i];
    }
    for (int i = 0; i < m_pMeshes.size(); i++)
    {
        delete m_pMeshes[i];
    }
    for (int i = 0; i < m_pGameObjects.size(); i++)
    {
        delete m_pGameObjects[i];
    }
}

void Game::Init()
{
    fw::ShaderProgram* m_pShader = new fw::ShaderProgram("Data/Shaders/basic.vert", "Data/Shaders/basic.frag");
    wglSwapInterval(1);

    m_pShaders.push_back(m_pShader);

    //create new meshes & shgaders
    //initialize meshes &sahders
    //create new objects & init them

    Mesh* PlayerMesh = new Mesh();
    Mesh* RockMesh = new Mesh();

    GLenum rpt = GL_TRIANGLE_FAN;
    uint32 rnv = 8;
    VertexFormat ra[] =
    {
    VertexFormat(0.0f,      0.0f,   0x30,   0x30,   0x30,   0xFF),
    VertexFormat(-10.0f,    10.0f,  0x60,   0x60,   0x60,   0xFF),
    VertexFormat(5.0f,      10.0f,  0x60,   0x60,   0x60,   0xFF),
    VertexFormat(15.0f,     0.0f,   0x60,   0x60,   0x60,   0xFF),
    VertexFormat(10.0f,     -10.0f, 0x60,   0x60,   0x60,   0xFF),
    VertexFormat(-5.0f,     -10.0f, 0x60,   0x60,   0x60,   0xFF),
    VertexFormat(-15.0f,    0.0f,   0x60,   0x60,   0x60,   0xFF),
    VertexFormat(-10.0f,    10.0f,  0x60,   0x60,   0x60,   0xFF),
    };
    RockMesh->Init(ra, rnv, rpt);
    GLenum ppt = GL_TRIANGLES;
    VertexFormat pa[] =
    {
    VertexFormat(-5.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-5.0f,     15.0f,  0xff,   0xff,   0x00,   0xFF),
    VertexFormat(5.0f,      15.0f,  0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-5.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(5.0f,      5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(5.0f,      15.0f,  0xff,   0xff,   0x00,   0xFF),

    VertexFormat(5.0f,      -5.0f,  0xff,   0xff,   0x00,   0xFF),
    VertexFormat(5.0f,      5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(10.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(5.0f,      -5.0f,  0xff,   0xff,   0x00,   0xFF),
    VertexFormat(10.0f,     -5.0f,  0xff,   0xff,   0x00,   0xFF),
    VertexFormat(10.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),

    VertexFormat(-10.0f,    -5.0f,  0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-10.0f,    5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-5.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-10.0f,    -5.0f,  0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-5.0f,     -5.0f,  0xff,   0xff,   0x00,   0xFF),
    VertexFormat(-5.0f,     5.0f,   0xff,   0xff,   0x00,   0xFF),

    VertexFormat(-5.0f,     -15.0f, 0x00,   0x00,   0x80,   0xFF),
    VertexFormat(5.0f,      -15.0f, 0x00,   0x00,   0x80,   0xFF),
    VertexFormat(5.0f,      5.0f,   0x00,   0x00,   0x80,   0xFF),
    VertexFormat(-5.0f,     -15.0f, 0x00,   0x00,   0x80,   0xFF),
    VertexFormat(-5.0f,     5.0f,   0x00,   0x00,   0x80,   0xFF),
    VertexFormat(5.0f,      5.0f,   0x00,   0x00,   0x80,   0xFF),
    };
    uint32 pnv = 24;
    PlayerMesh->Init(pa, pnv, ppt);

    m_pMeshes.push_back(PlayerMesh);
    m_pMeshes.push_back(RockMesh);

    GameObject* m_Player = new PlayerObject();
    GameObject* m_Rock1 = new RockObject();
    GameObject* m_Rock2 = new RockObject();
    GameObject* m_Rock3 = new RockObject();
    GameObject* m_Rock4 = new RockObject();
    GameObject* m_Rock5 = new RockObject();

    m_Player->Init(this, m_pMeshes[0], m_pShaders[0], vec2(0.0f, 0.0f));
    m_Rock1->Init(this, m_pMeshes[1], m_pShaders[0], vec2(0.3f, 0.4f));
    m_Rock2->Init(this, m_pMeshes[1], m_pShaders[0], vec2(0.5f, 0.1f));
    m_Rock3->Init(this, m_pMeshes[1], m_pShaders[0], vec2(0.6f, 0.2f));
    m_Rock4->Init(this, m_pMeshes[1], m_pShaders[0], vec2(0.4f, 0.0f));
    m_Rock5->Init(this, m_pMeshes[1], m_pShaders[0], vec2(0.1f, 0.5f));

    m_pGameObjects.push_back(m_Player);
    m_pGameObjects.push_back(m_Rock1);
    m_pGameObjects.push_back(m_Rock2);
    m_pGameObjects.push_back(m_Rock3);
    m_pGameObjects.push_back(m_Rock4);
    m_pGameObjects.push_back(m_Rock5);
}

void Game::Update(float deltaTime)
{
    //loop update objects
    for (int i = 0; i < 6; i++)
    {
        m_pGameObjects[i]->Update(deltaTime, m_pFramework);
    }

}

void Game::Draw()
{
    glClearColor(1.0f, 0.5f, 0.75f, 1.0f); //set clear color to pink
    glClear(GL_COLOR_BUFFER_BIT); //clears screen

    glViewport(0, 0, 600, 600);

    //loop draw objects
    for (int i = 0; i < 6; i++)
    {
        m_pGameObjects[i]->Draw();
    }

    glViewport(475, 25, 100, 100);

    for (int i = 0; i < 6; i++)
    {
        m_pGameObjects[i]->Draw();
    }

    /*  GL_POINTS
        GL_LINES
        GL_LINE_LOOP
        GL_LINE_STRIP
        GL_TRIANGLES
        GL_TRIANGLE_STRIP
        GL_TRIANGLE_FAN
        GL_QUADS (Discontinued)
        GL_QUAD_STRIP (Discontinued)
        GL_POLYGON (Discontinued)
    */
}