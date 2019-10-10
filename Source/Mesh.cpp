#include "GamePCH.h"
#include "Mesh.h"

void Mesh::Init(VertexFormat* vf, uint32 nv, GLenum pt)
{
    m_primType = pt;
    numberOfVerts = nv;

    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexFormat) * numberOfVerts, vf, GL_STATIC_DRAW);


}

void Mesh::Draw(fw::ShaderProgram* p_Shader, vec2 pos)
{
    glUseProgram(p_Shader->GetProgram());

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);



    GLint loc = glGetAttribLocation(p_Shader->GetProgram(), "a_Position");
    glEnableVertexAttribArray(loc);
    glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, 12, (void*)0); //Stride: 2*4byte floats + 4*1byte usigned chars

    GLint cloc = glGetAttribLocation(p_Shader->GetProgram(), "a_Color");
    glEnableVertexAttribArray(cloc);
    glVertexAttribPointer(cloc, 4, GL_UNSIGNED_BYTE, GL_TRUE, 12, (void*)8); //Offset: Skip the 2*4byte floats



    GLint uXloc = glGetUniformLocation(p_Shader->GetProgram(), "u_XOffset");
    glUniform1f(uXloc, pos.x);
    GLint uYloc = glGetUniformLocation(p_Shader->GetProgram(), "u_YOffset");
    glUniform1f(uYloc, pos.y);

    glDrawArrays(m_primType, 0, numberOfVerts);
}
