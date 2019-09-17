#include "Game.h"

Game::Game()
{
    m_VBO = 0;
}

Game::~Game()
{
}

void Game::Init()
{
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
}

void Game::Draw()
{
    int numberOfVerts = 4;
    glClearColor(1.0f, 0.5f, 0.75f, 1.0f); //set clear color to pink
    glClear(GL_COLOR_BUFFER_BIT); //clears screen

    //Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    // Get the attribute variable’s location from the shader.
    GLint loc = 0; 
    //glGetAttribLocation( m_pShader->m_Program, "a_Position" );
    glEnableVertexAttribArray( loc );
    // Describe the attributes in the VBO to OpenGL.
    glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 8, (void*)0 );

    glPointSize(10);
    glLineWidth(5);

    // Draw the primitive.
    glDrawArrays(GL_LINE_LOOP, 0, numberOfVerts );

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