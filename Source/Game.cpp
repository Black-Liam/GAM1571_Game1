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
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    // Define our triangle as 3 positions.
    float attribs[] =  
    { 
        -20.0,   0.0, 
        0.0,    40.0, 
        20.0,    0.0,
        0.0,    -40.0
    };
    // Copy our attribute data into the VBO.
    glBufferData( GL_ARRAY_BUFFER, sizeof(float)*8, attribs, GL_STATIC_DRAW );
}

void Game::Update()
{
    m_timer += 0.01;
    if (m_pFramework->IsKeyDown(VK_UP))
    {
        m_up += 0.01f;
    }
    else if (m_pFramework->IsKeyDown(VK_DOWN))
    {
        m_up -= 0.01f;
    }
    else
    {
        m_up += 0.0f;
    }
    if (m_pFramework->IsKeyDown(VK_SPACE))
    {
        m_up = 0.0f;
        m_timer = 0.0f;
    }

}

void Game::Draw()
{
    int numberOfVerts = 4;
    glClearColor(1.0f, 0.5f, 0.75f, 1.0f); //set clear color to pink
    glClear(GL_COLOR_BUFFER_BIT); //clears screen

    //Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    // Get the attribute variable’s location from the shader.
    GLint loc = glGetAttribLocation( m_pShader->GetProgram(), "a_Position" );
    glEnableVertexAttribArray( loc );
    // Describe the attributes in the VBO to OpenGL.
    glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 8, (void*)0 );

    glPointSize(10);
    glLineWidth(5);

    //Enable Shader
    glUseProgram(m_pShader->GetProgram());

    //Setup Uniforms
    GLint uXloc = glGetUniformLocation(m_pShader->GetProgram(), "u_XOffset");
    glUniform1f(uXloc, sinf(m_timer));
    GLint uYloc = glGetUniformLocation(m_pShader->GetProgram(), "u_YOffset");
    glUniform1f(uYloc, m_up);

    // Draw the primitive.
    glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVerts );

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