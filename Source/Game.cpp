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
    float attribs[] = { 0, 0, 10, 20, 20, 0 };
    // Copy our attribute data into the VBO.
    glBufferData( GL_ARRAY_BUFFER, sizeof(float)*6, attribs, GL_STATIC_DRAW );
}

void Game::Update()
{
}

void Game::Draw()
{
    glClearColor(1.0f, 0.5f, 0.75f, 1.0f); //set clear color to white
    glClear(GL_COLOR_BUFFER_BIT); //clears screen

    //Set this VBO to be the currently active one.
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    // Get the attribute variable’s location from the shader.
    GLint loc = 0; 
    //glGetAttribLocation( m_pShader->m_Program, "a_Position" );
    glEnableVertexAttribArray( loc );
    // Describe the attributes in the VBO to OpenGL.
    glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 8, (void*)0 );
    // Draw the primitive.
    glDrawArrays( GL_TRIANGLES, 0, 3 );
}
