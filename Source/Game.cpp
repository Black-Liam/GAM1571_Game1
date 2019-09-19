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
        -20.0,   0.0,   0.0,    1.0,    1.0,    1.0,
        0.0,    40.0,   1.0,    0.0,    1.0,    1.0,
        20.0,    0.0,   1.0,    1.0,    0.0,    1.0,
    };
    // Copy our attribute data into the VBO.
    glBufferData( GL_ARRAY_BUFFER, sizeof(float)*18, attribs, GL_STATIC_DRAW ); //6 -> 18
}

void Game::Update()
{
    m_timer += 0.05f;
    if (m_pFramework->IsKeyDown(VK_UP))
    {
        m_up += 0.01f;
    }
    else if (m_pFramework->IsKeyDown(VK_DOWN))
    {
        m_up -= 0.01f;
    }

    if (m_pFramework->IsKeyDown(VK_RIGHT))
    {
        m_right += 0.01f;
    }
    else if (m_pFramework->IsKeyDown(VK_LEFT))
    {
        m_right -= 0.01f;
    }

    if (m_pFramework->IsKeyDown(VK_SPACE))
    {
        m_up = 0.0f;
        m_right = 0.0f;
    }

}

void Game::Draw()
{
    int numberOfVerts = 3;
    glClearColor(1.0f, 0.5f, 0.75f, 1.0f); //set clear color to pink
    glClear(GL_COLOR_BUFFER_BIT); //clears screen

    //Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    // Get the attribute variable’s location from the shader.
    GLint loc = glGetAttribLocation( m_pShader->GetProgram(), "a_Position" );
    glEnableVertexAttribArray( loc );
    // Describe the attributes in the VBO to OpenGL.
    glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 24, (void*)0 ); //8->24

    GLint cloc = glGetAttribLocation(m_pShader->GetProgram(), "a_Color");
    glEnableVertexAttribArray(cloc);
    // Describe the attributes in the VBO to OpenGL.
    glVertexAttribPointer(cloc, 4, GL_FLOAT, GL_FALSE, 24, (void*)8);


    glPointSize(10);
    glLineWidth(5);

    //Enable Shader
    glUseProgram(m_pShader->GetProgram());

    //Setup Uniforms
    GLint uXloc = glGetUniformLocation(m_pShader->GetProgram(), "u_XOffset");
    glUniform1f(uXloc, m_right);
    GLint uYloc = glGetUniformLocation(m_pShader->GetProgram(), "u_YOffset");
    glUniform1f(uYloc, m_up);
    GLint uColor = glGetUniformLocation(m_pShader->GetProgram(), "u_Timer");
    glUniform1f(uColor, (sinf(m_timer)+1)/2.0f);

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