#include "GamePCH.h"
#include "Game.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "RockObject.h"
#include "GoalObject.h"
#include "Camera.h"
Game::Game(fw::Framework* pFramework) : GameCore(pFramework)
{
    m_pFramework = pFramework;



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
    Mesh* GoalMesh = new Mesh();

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

    GLenum gpt = GL_TRIANGLE_FAN;
    VertexFormat ga[] =
    {
    VertexFormat(0.0f,     0.0f,   0x80,   0x00,   0x00,   0xFF),
    VertexFormat(12.0f,     -12.0f,   0x00,   0x00,   0x00,   0xFF),
    VertexFormat(-12.0f,     -12.0f,   0x00,   0x00,   0x00,   0xFF),
    VertexFormat(-12.0f,     4.0f,   0xff,   0x00,   0x00,   0xFF),
    VertexFormat(-10.0f,     10.0f,   0xff,   0x00,   0x00,   0xFF),
    VertexFormat(-6.0f,     14.0f,   0xff,   0x00,   0x00,   0xFF),
    VertexFormat(0.0f,     16.0f,   0xff,   0x00,   0x00,   0xFF),
    VertexFormat(6.0f,     14.0f,   0xff,   0x00,   0x00,   0xFF),
    VertexFormat(10.0f,     10.0f,   0xff,   0x00,   0x00,   0xFF),
    VertexFormat(12.0f,     4.0f,   0xff,   0x00,   0x00,   0xFF),
    VertexFormat(12.0f,     -12.0f,   0x00,   0x00,   0x00,   0xFF),
    };
    uint32 gnv = 11;
    GoalMesh->Init(ga, gnv, gpt);

    m_pMeshes.push_back(PlayerMesh);
    m_pMeshes.push_back(RockMesh);
    m_pMeshes.push_back(GoalMesh);

    GameObject* m_Player = new PlayerObject();
    GameObject* m_Rock1 = new RockObject();
    GameObject* m_Rock2 = new RockObject();
    GameObject* m_Rock3 = new RockObject();
    GameObject* m_Rock4 = new RockObject();
    GameObject* m_Rock5 = new RockObject();
    GameObject* m_Goal = new GoalObject();
    //GameObject* m_Camera = new CameraObject();

    srand((unsigned int)fw::GetSystemTime());

    float randCords[10];
    for (int i = 0; i < 10; i++)
    {
        randCords[i] = (float)((rand() % 100) / 100.0f);
        if (rand() % 2 == 1)
        {
            randCords[i] *= -1.0f;
        }
    }

    m_Player->Init(this, m_pMeshes[0], m_pShaders[0], vec2(-0.9f, 0.9f));
    m_Rock1->Init(this, m_pMeshes[1], m_pShaders[0], vec2(randCords[0], randCords[1]));
    m_Rock2->Init(this, m_pMeshes[1], m_pShaders[0], vec2(randCords[2], randCords[3]));
    m_Rock3->Init(this, m_pMeshes[1], m_pShaders[0], vec2(randCords[4], randCords[5]));
    m_Rock4->Init(this, m_pMeshes[1], m_pShaders[0], vec2(randCords[6], randCords[7]));
    m_Rock5->Init(this, m_pMeshes[1], m_pShaders[0], vec2(randCords[8], randCords[9]));
    m_Goal->Init(this, m_pMeshes[2], m_pShaders[0], vec2(0.9f, -0.9f));
    //m_Camera->CamInit(this, m_pShaders[0], vec2(0.0f, 0.0f));

    m_pGameObjects.push_back(m_Player);
    m_pGameObjects.push_back(m_Rock1);
    m_pGameObjects.push_back(m_Rock2);
    m_pGameObjects.push_back(m_Rock3);
    m_pGameObjects.push_back(m_Rock4);
    m_pGameObjects.push_back(m_Rock5);
    m_pGameObjects.push_back(m_Goal);
    //m_pGameObjects.push_back(m_Camera);
}

void Game::Update(float deltaTime)
{
    //loop update objects
    for (int i = 0; i < 7; i++)
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
    for (int i = 0; i < 7; i++)
    {
        m_pGameObjects[i]->Draw();
    }

    glViewport(475, 25, 100, 100);

    for (int i = 0; i < 7; i++)
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