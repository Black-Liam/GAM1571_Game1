#include "Game.h"

Game::Game(fw::Framework* pFramework) : GameCore(pFramework)
{
    m_VBO = 0;
    m_pShader = nullptr;
    m_pFramework = pFramework;
    m_Player = new GameObject(0);
    m_Other = new GameObject(1);
}

Game::~Game()
{
    delete m_pShader;
    delete m_pFramework;
    delete m_Player;
    delete m_Other;
}

void Game::Init()
{
    m_pShader = new fw::ShaderProgram("Data/Shaders/basic.vert", "Data/Shaders/basic.frag");
    wglSwapInterval(1);

    // Generate a buffer for our vertex attributes.
    glGenBuffers(1, &m_Player->m_VBO);
    // Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_Player->m_VBO);
    VertexFormat plAttribs[] =
    {
    VertexFormat(0.0f,     0.0f,   0x80,   0x80,   0x80,   0xFF),
    VertexFormat(-50.0f,    0.0f,   0x00,   0xBC,   0x8A,   0xFF),
    VertexFormat(0.0f,     50.0f,  0xF0,   0xF7,   0x09,   0xFF),
    VertexFormat(50.0f,    0.0f,   0xEB,   0x34,   0x0A,   0xFF),
    VertexFormat(0.0f,    -50.0f,  0x7E,   0x07,   0x85,   0xFF),
    VertexFormat(-50.0f,    0.0f,   0x00,   0xBC,   0x8A,   0xFF),
    };
    m_Player->numberOfVerts = sizeof(plAttribs)/ sizeof(VertexFormat);
    // Copy our attribute data into the VBO.
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * m_Player->numberOfVerts, plAttribs, GL_STATIC_DRAW); //vertex size * number of vertexes

    //glGenBuffers(1, &m_Other->m_VBO);
    //glBindBuffer(GL_ARRAY_BUFFER, m_Other->m_VBO);
    //VertexFormat otAttribs[] =
    //{
    //VertexFormat(-30.0f,    0.0f,   0x80,   0x80,   0x80,   0xFF),
    //VertexFormat(0.0f,     30.0f,  0x80,   0x80,   0x80,   0xFF),
    //VertexFormat(30.0f,    0.0f,   0x80,   0x80,   0x80,   0xFF),
    //VertexFormat(0.0f,    -30.0f,  0x80,   0x80,   0x80,   0xFF),
    //};
    //m_Other->numberOfVerts = sizeof(otAttribs) / sizeof(VertexFormat);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * m_Other->numberOfVerts, otAttribs, GL_STATIC_DRAW);

}

void Game::Update(float deltaTime)
{
    //m_timer += 0.1f;
    if (m_pFramework->IsKeyDown(VK_UP))
    {
        m_up += speed * deltaTime;
    }
    else if (m_pFramework->IsKeyDown(VK_DOWN))
    {
        m_up -= speed * deltaTime;
    }
    else if (m_pFramework->IsKeyDown(VK_RIGHT))
    {
        m_right += speed * deltaTime;
    }
    else if (m_pFramework->IsKeyDown(VK_LEFT))
    {
        m_right -= speed * deltaTime;
    }

    if (m_pFramework->IsKeyDown(VK_SPACE))
    {
        m_up = 0.0f;
        m_right = 0.0f;
    }

}

void Game::Draw()
{
    glClearColor(1.0f, 0.5f, 0.75f, 1.0f); //set clear color to pink
    glClear(GL_COLOR_BUFFER_BIT); //clears screen

    //Set this VBO to be the currently active one.

    glBindBuffer(GL_ARRAY_BUFFER, m_Player->m_VBO);

    m_Player->Draw(m_pShader);

    //Enable Shader
    glUseProgram(m_pShader->GetProgram());

    //Setup Uniforms
    GLint uXloc = glGetUniformLocation(m_pShader->GetProgram(), "u_XOffset");
    glUniform1f(uXloc, m_right);
    GLint uYloc = glGetUniformLocation(m_pShader->GetProgram(), "u_YOffset");
    glUniform1f(uYloc, m_up);
    GLint uColor = glGetUniformLocation(m_pShader->GetProgram(), "u_Timer");
    glUniform1f(uColor, (cosf(m_timer) + 1) / 2.0f);

    // Draw the primitive.
    glDrawArrays(GL_TRIANGLE_FAN, 0, m_Player->numberOfVerts);
    //glDrawArrays(GL_TRIANGLE_FAN, 0, m_Other->numberOfVerts);

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