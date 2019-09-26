#include "Game.h"

Game::Game(fw::Framework* pFramework) : GameCore(pFramework)
{
    m_VBO = 0;
    m_pShader = nullptr;
    m_pFramework = pFramework;
}

Game::~Game()
{
    delete m_pShader;
    delete m_pFramework;
}

void Game::Init()
{
    m_pShader = new fw::ShaderProgram("Data/Shaders/basic.vert", "Data/Shaders/basic.frag");

    // Generate a buffer for our vertex attributes.
    glGenBuffers(1, &m_VBO);
    // m_VBO is a GLuint.
    // Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    // Define our triangle as 3 positions.
    wglSwapInterval(1);
    VertexFormat attribs[] =
    {
    VertexFormat(0.0f,     0.0f,   0x80,   0x80,   0x80,   0xFF),
    VertexFormat(-50.0f,    0.0f,   0x00,   0xBC,   0x8A,   0xFF),
    VertexFormat(0.0f,     50.0f,  0xF0,   0xF7,   0x09,   0xFF),
    VertexFormat(50.0f,    0.0f,   0xEB,   0x34,   0x0A,   0xFF),
    VertexFormat(0.0f,    -50.0f,  0x7E,   0x07,   0x85,   0xFF),
    VertexFormat(-50.0f,    0.0f,   0x00,   0xBC,   0x8A,   0xFF),
    };
    // Copy our attribute data into the VBO.
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * 6, attribs, GL_STATIC_DRAW); //vertex size * number of vertexes
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
    int numberOfVerts = 6;
    glClearColor(1.0f, 0.5f, 0.75f, 1.0f); //set clear color to pink
    glClear(GL_COLOR_BUFFER_BIT); //clears screen

    //Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    // Get the attribute variable’s location from the shader.
    GLint loc = glGetAttribLocation(m_pShader->GetProgram(), "a_Position");
    glEnableVertexAttribArray(loc);
    // Describe the attributes in the VBO to OpenGL.
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 12, (void*)0); //Stride: 2*4byte floats + 4*1byte usigned chars

    GLint cloc = glGetAttribLocation(m_pShader->GetProgram(), "a_Color");
    glEnableVertexAttribArray(cloc);
    // Describe the attributes in the VBO to OpenGL.
    glVertexAttribPointer(cloc, 4, GL_UNSIGNED_BYTE, GL_TRUE, 12, (void*)8); //Offset: Skip the 2*4byte floats

    //glPointSize(10);
    //glLineWidth(5);

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
    glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVerts);

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