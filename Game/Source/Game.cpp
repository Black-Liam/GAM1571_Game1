#include "GamePCH.h"

#include "Game.h"
#include "Base/Mesh.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Camera.h"
#include "GameObjects/Player.h"
#include "GameObjects/PlayerController.h"
#include "Tiles/Tilemap.h"

using namespace fw;

Game::Game(Framework* pFramework)
: GameCore( pFramework )
{
    m_pImGuiManager = nullptr;

    m_pShaderColor = nullptr;
    m_pShaderTexture = nullptr;
    m_pMeshPlayer = nullptr;
    m_pMeshCircle = nullptr;
    m_TextureBall = 0;
    m_pTilemap = nullptr;
    m_pPlayer = nullptr;
    m_pCamera = nullptr;
    m_pBall = nullptr;

    m_pController = new PlayerController();
}

Game::~Game()
{
    delete m_pController;

    delete m_pPlayer;
    delete m_pCamera;
    delete m_pBall;

    glDeleteTextures( 1, &m_TextureBall );

    delete m_pMeshPlayer;
    delete m_pMeshCircle;

    delete m_pTilemap;

    delete m_pShaderColor;
    delete m_pShaderTexture;

    delete m_pImGuiManager;
}

void Game::Init()
{
    m_pImGuiManager = new ImGuiManager();
    m_pImGuiManager->Init();

    // Turn on v-sync.
    wglSwapInterval( 1 );

    // Create our shaders.
    m_pShaderColor = new ShaderProgram( "Data/Shaders/basic.vert", "Data/Shaders/basic.frag" );
    m_pShaderTexture = new ShaderProgram( "Data/Shaders/texture.vert", "Data/Shaders/texture.frag" );

    // Create our meshes.
    m_pMeshPlayer = new Mesh();
    m_pMeshPlayer->GeneratePlayer();

    m_pMeshCircle = new Mesh();
    m_pMeshCircle->GenerateCircle();

    m_pTilemap = new Tilemap("Data/JSON/Layout.json");

    // Load our textures.
    m_TextureBall = LoadTexture( "Data/Textures/SoccerBall.png" );

    // Create our GameObjects.
    m_pPlayer = new Player( this, m_pMeshPlayer, m_pShaderColor, m_TextureBall, vec2( 30, 50 ), 0, m_pController );
    m_pCamera = new Camera( this, vec2( 50, 50 ), vec2( 1/(GetWorldWidth()/2), 1/(GetWorldHeight()/2) ) );
    m_pBall = new Ball( this, m_pMeshCircle, m_pShaderTexture, m_TextureBall, vec2( 50, 50 ) );
}

void Game::OnEvent(Event* pEvent)
{
    m_pController->OnEvent( pEvent );
}

void Game::Update(float deltaTime)
{
    m_pImGuiManager->StartFrame( (float)m_pFramework->GetWindowWidth(), (float)m_pFramework->GetWindowHeight(), deltaTime );

    if( m_pFramework->IsKeyDown( VK_F1 ) )
        wglSwapInterval( 0 );
    if( m_pFramework->IsKeyDown( VK_F2 ) )
        wglSwapInterval( 1 );

    m_pPlayer->Update( deltaTime );
    m_pCamera->Update( deltaTime );
    m_pBall->Update( deltaTime );

    CheckForCollisions();
}

void Game::Draw()
{
    // Setup the values we will clear to, then actually clear the color and depth buffers.
    glClearColor( 0.0f, 0.0f, 0.4f, 0.0f ); // dark blue
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // Draw our game objects.
    m_pPlayer->Draw( m_pCamera );
    m_pBall->Draw( m_pCamera );
    m_pTilemap->Draw(m_pCamera, m_pShaderTexture, vec2(50, 50));

    m_pImGuiManager->EndFrame();
}

void Game::CheckForCollisions()
{
    if( m_pBall->IsColliding( m_pPlayer ) )
    {
        m_pPlayer->OnCollision( m_pBall );
        m_pBall->OnCollision( m_pPlayer );
    }
}
