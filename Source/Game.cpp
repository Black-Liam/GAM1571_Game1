#include "GamePCH.h"
#include "Game.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "RockObject.h"

Game::Game(fw::Framework* pFramework) : GameCore(pFramework)
{
    m_VBO = 0;
    m_pShader = nullptr;
    m_pFramework = pFramework;
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

    m_Player->Init();
    m_Rock1->Init();
    m_Rock2->Init();
    m_Rock3->Init();
    m_Rock4->Init();
    m_Rock5->Init();
}

void Game::Update(float deltaTime)
{
    m_Player->Update(deltaTime, m_pFramework);

}

void Game::Draw()
{
    glClearColor(1.0f, 0.5f, 0.75f, 1.0f); //set clear color to pink
    glClear(GL_COLOR_BUFFER_BIT); //clears screen

    glViewport(0, 0, 600, 600);

    m_Player->Draw(m_pShader, 0, 0);

    m_Rock1->Draw(m_pShader, -0.5f, -0.6f);
    m_Rock2->Draw(m_pShader, -0.7f, 0.6f);
    m_Rock3->Draw(m_pShader, 0.4f, -0.3f);
    m_Rock4->Draw(m_pShader, 0.6f,0.8f );
    m_Rock5->Draw(m_pShader, 0.85f, -0.7f);

    glViewport(475, 25, 100, 100);

    m_Player->Draw(m_pShader, 0, 0);

    m_Rock1->Draw(m_pShader, -0.5f, -0.6f);
    m_Rock2->Draw(m_pShader, -0.7f, 0.6f);
    m_Rock3->Draw(m_pShader, 0.4f, -0.3f);
    m_Rock4->Draw(m_pShader, 0.6f, 0.8f);
    m_Rock5->Draw(m_pShader, 0.85f, -0.7f);

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