#pragma once
#include "GamePCH.h"

//1 for each different looking tile
enum class TileType
{
    TT_Ground,
    TT_Wall,
    TT_Water,
    TT_Max
};


//what does the tile do + has a mesh & Texture ids
struct TileProperties
{
public:
    Mesh* m_pMesh;
    fw::ShaderProgram* m_pShader;
    GLuint m_TextureID;
    bool m_IsWalkable;
};

//2D array of TPs, plus functions that draws them
class Tilemap
{
public:
    TileProperties* myProperties;
    TileType* pLayout;
    float tileHeight = 5.0f;
    float tileWidth = 5.0f;
    int height = 5;
    int width = 8;

    Tilemap(char* filename);
    ~Tilemap();
    void Draw(class Camera* view, fw::ShaderProgram* pShader, fw::vec2 pos);
};

