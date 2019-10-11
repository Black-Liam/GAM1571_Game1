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
    for (int i = 0; i > 1; i++)
    {
        delete m_pShaders[i];
    }
    for (int i = 0; i > 2; i++)
    {
        delete m_pMeshes[i];
    }
    for (int i = 0; i > 6; i++)
    {
        delete m_pGameObjects[i];
    }
    delete m_pFramework;
}

void Game::Init()
{
    fw::ShaderProgram* m_pShader = new fw::ShaderProgram("Data/Shaders/basic.vert", "Data/Shaders/basic.frag");
    wglSwapInterval(1);

    m_pShaders[0] = m_pShader;

    //create new meshes & shgaders
    //initialize meshes &sahders
    //create new objects & init them
    
    Mesh* PlayerMesh = new Mesh();
    Mesh* RockMesh = new Mesh();

    GLenum rpt = GL_TRIANGLE_FAN;
    uint32 rnv = 8;
    VertexFormat ra[] =
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
    RockMesh->Init(ra, rnv, rpt);
    GLenum ppt = GL_TRIANGLES;
    VertexFormat pa[] =
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
    uint32 pnv = 24;
    PlayerMesh->Init(pa, pnv, ppt);

    m_pMeshes[0] = PlayerMesh;
    m_pMeshes[1] = RockMesh;

    GameObject* m_Player = new PlayerObject(this,m_pMeshes[0], m_pShaders[0],vec2(0.0f, 0.0f));
    GameObject* m_Rock1 = new RockObject(this, m_pMeshes[0], m_pShaders[0], vec2(3.0f, 4.0f));
    GameObject* m_Rock2 = new RockObject(this, m_pMeshes[0], m_pShaders[0], vec2(5.0f, 1.0f));
    GameObject* m_Rock3 = new RockObject(this, m_pMeshes[0], m_pShaders[0], vec2(6.0f, 2.0f));
    GameObject* m_Rock4 = new RockObject(this, m_pMeshes[0], m_pShaders[0], vec2(4.0f, 0.0f));
    GameObject* m_Rock5 = new RockObject(this, m_pMeshes[0], m_pShaders[0], vec2(1.0f, 5.0f));


    m_Player->Init();
    m_Rock1->Init();
    m_Rock2->Init();
    m_Rock3->Init();
    m_Rock4->Init();
    m_Rock5->Init();
}

void Game::Update(float deltaTime)
{
    //loop update objects

    m_Player->Update(deltaTime, m_pFramework);

}

void Game::Draw()
{
    glClearColor(1.0f, 0.5f, 0.75f, 1.0f); //set clear color to pink
    glClear(GL_COLOR_BUFFER_BIT); //clears screen

    glViewport(0, 0, 600, 600);

    //loop draw objects
    m_Player->Draw();

    m_Rock1->Draw();
    m_Rock2->Draw();
    m_Rock3->Draw();
    m_Rock4->Draw();
    m_Rock5->Draw();

    glViewport(475, 25, 100, 100);

    m_Player->Draw();

    m_Rock1->Draw();
    m_Rock2->Draw();
    m_Rock3->Draw();
    m_Rock4->Draw();
    m_Rock5->Draw();

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