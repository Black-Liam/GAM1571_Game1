#include "GamePCH.h"
#include "Game.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "RockObject.h"

Game::Game(fw::Framework* pFramework) : GameCore(pFramework)
{
    m_pShader = nullptr;
    m_pFramework = pFramework;

    //m_pShaders[0];
    //m_pMeshes[0];
    //m_pGameObjects[0];

    //1 can I make one in the vector, or do I make it and pass it in?
    //2 where should the new calls be?

    m_Player = new PlayerObject();
    m_Rock1 = new RockObject();
    m_Rock2 = new RockObject();
    m_Rock3 = new RockObject();
    m_Rock4 = new RockObject();
    m_Rock5 = new RockObject();
}

Game::~Game()
{
    delete m_pShader;
    delete m_pFramework;
    delete m_Player;
    delete m_Rock1;
    delete m_Rock2;
    delete m_Rock3;
    delete m_Rock4;
    delete m_Rock5;
}

void Game::Init()
{
    m_pShader = new fw::ShaderProgram("Data/Shaders/basic.vert", "Data/Shaders/basic.frag");
    wglSwapInterval(1);

    //create new meshes & shgaders
    //initialize meshes &sahders
    //create new objects & init them
    //
    

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