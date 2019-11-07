#include "GamePCH.h"

#include "Base/Mesh.h"
#include "Base/VertexFormat.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Camera.h"
#include "GameObjects/GameObject.h"

using namespace fw;

Mesh::Mesh()
{
    m_VBO = 0;

    m_PrimitiveType = -1;
    m_NumVerts = 0;
}
    
Mesh::~Mesh()
{
    glDeleteBuffers( 1, &m_VBO );
}

void Mesh::Init(VertexFormat* pVerts, unsigned int numVerts, GLenum primitiveType)
{
    // Gen and fill buffer with our attributes.
    glGenBuffers( 1, &m_VBO );
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );
    glBufferData( GL_ARRAY_BUFFER, sizeof(VertexFormat) * numVerts, pVerts, GL_STATIC_DRAW );
    glBindBuffer( GL_ARRAY_BUFFER, 0 );

    m_NumVerts = numVerts;
    m_PrimitiveType = primitiveType;
}

void Mesh::Draw(Camera* pCamera, ShaderProgram* pShader, vec2 pos, GLuint textureID)
{
    assert( m_PrimitiveType != -1 );
    assert( m_NumVerts != 0 );

    // Setup attributes.
    glBindBuffer( GL_ARRAY_BUFFER, m_VBO );

    GLint locPosition = glGetAttribLocation( pShader->GetProgram(), "a_Position" );
    if( locPosition != -1 )
    {
        glVertexAttribPointer( locPosition, 2, GL_FLOAT, GL_FALSE, 20, (void*)0 );
        glEnableVertexAttribArray( locPosition );
    }

    GLint locColor = glGetAttribLocation( pShader->GetProgram(), "a_Color" );
    if( locColor != -1 )
    {
        glVertexAttribPointer( locColor, 4, GL_UNSIGNED_BYTE, GL_TRUE, 20, (void*)8 );
        glEnableVertexAttribArray( locColor );
    }

    GLint locUV = glGetAttribLocation( pShader->GetProgram(), "a_UV" );
    if( locUV != -1 )
    {
        glVertexAttribPointer( locUV, 2, GL_FLOAT, GL_FALSE, 20, (void*)12 );
        glEnableVertexAttribArray( locUV );
    }

    // Enable shader and setup uniforms.
    glUseProgram( pShader->GetProgram() );

    GLint uObjectTranslation = glGetUniformLocation( pShader->GetProgram(), "u_ObjectTranslation" );
    if( uObjectTranslation != -1 )
    {
        glUniform2f( uObjectTranslation, pos.x, pos.y );
    }

    GLint uCameraTranslation = glGetUniformLocation( pShader->GetProgram(), "u_CameraTranslation" );
    if( uCameraTranslation != -1 )
    {
        glUniform2f( uCameraTranslation, -pCamera->GetPosition().x, -pCamera->GetPosition().y );
    }

    GLint uProjectionScale = glGetUniformLocation( pShader->GetProgram(), "u_ProjectionScale" );
    if( uProjectionScale != -1 )
    {
        glUniform2f( uProjectionScale, pCamera->GetProjectionScale().x, pCamera->GetProjectionScale().y );
    }

    // Setup the texture.
    int textureUnit = 0;
    glActiveTexture( GL_TEXTURE0 + textureUnit );
    glBindTexture( GL_TEXTURE_2D, textureID );
    GLint uTexture = glGetUniformLocation( pShader->GetProgram(), "u_Texture" );
    if( uTexture != -1 )
    {
        glUniform1i( uTexture, textureUnit );
    }

    // Draw.
    glDrawArrays( m_PrimitiveType, 0, m_NumVerts );
}

void Mesh::GenerateTriangle()
{
    // ATM this can only be called once, so we assert if it's called again with a VBO already allocated.
    assert( m_VBO == 0 );

    // Vertex position info for a triangle.
    VertexFormat vertices[] = {
        VertexFormat(  0.0f,  4.0f, 0, 255, 0, 255, 0, 0 ),
        VertexFormat( -2.0f, -4.0f, 0, 128, 0, 255, 0, 0 ),
        VertexFormat(  2.0f, -4.0f, 0, 128, 0, 255, 0, 0 ),
    };

    Init( vertices, 3, GL_TRIANGLES );
}

void Mesh::GenerateCircle()
{
    // ATM this can only be called once, so we assert if it's called again with a VBO already allocated.
    assert( m_VBO == 0 );

    // Vertex position info for a circle.
    int numSegments = 30;
    float radius = 3.6f;

    VertexFormat* vertices = new VertexFormat[numSegments];
    for( int i=0; i<numSegments; i++ )
    {
        float angleDiff = 2 * PI / numSegments;
        float x = cosf( angleDiff * i ) * radius;
        float y = sinf( angleDiff * i ) * radius;

        vertices[i] = VertexFormat( x, y, 255, 255, 255, 255, x/8+0.5f, y/8+0.5f );
    }

    Init( vertices, numSegments, GL_TRIANGLE_FAN );

    delete[] vertices;
}

void Mesh::GeneratePlayer()
{
    assert(m_VBO == 0);

    VertexFormat pa[] =
    {
    VertexFormat(-2.0f,     2.0f,   0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(-2.0f,     6.0f,  0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(2.0f,      6.0f,  0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(-2.0f,     2.0f,   0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(2.0f,      2.0f,   0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(2.0f,      6.0f,  0xff,   0xff,   0x00,   0xFF,0,0),

    VertexFormat(2.0f,      -2.0f,  0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(2.0f,      2.0f,   0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(4.0f,     2.0f,   0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(2.0f,      -2.0f,  0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(4.0f,     -2.0f,  0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(4.0f,     2.0f,   0xff,   0xff,   0x00,   0xFF,0,0),

    VertexFormat(-4.0f,    -2.0f,  0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(-4.0f,    2.0f,   0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(-2.0f,     2.0f,   0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(-4.0f,    -2.0f,  0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(-2.0f,     -2.0f,  0xff,   0xff,   0x00,   0xFF,0,0),
    VertexFormat(-2.0f,     2.0f,   0xff,   0xff,   0x00,   0xFF,0,0),

    VertexFormat(-2.0f,     -6.0f, 0x00,   0x00,   0x80,   0xFF,0,0),
    VertexFormat(2.0f,      -6.0f, 0x00,   0x00,   0x80,   0xFF,0,0),
    VertexFormat(2.0f,      2.0f,   0x00,   0x00,   0x80,   0xFF,0,0),
    VertexFormat(-2.0f,     -6.0f, 0x00,   0x00,   0x80,   0xFF,0,0),
    VertexFormat(-2.0f,     2.0f,   0x00,   0x00,   0x80,   0xFF,0,0),
    VertexFormat(2.0f,      2.0f,   0x00,   0x00,   0x80,   0xFF,0,0),
    };
    Init(pa, 24, GL_TRIANGLES);
}

void Mesh::GenerateSquare(float sideLength)
{
    VertexFormat vertices[4];
    for (int i = 0; i < 4; i++)
    {
        float h = i / 2;
        float w = i % 2;
        float x = w * sideLength;
        float y = h * sideLength;
        vertices[i] = VertexFormat(x, y, 255, 255, 255, 255, w, h);
    }

    Init(vertices, 4, GL_TRIANGLE_STRIP);

}
