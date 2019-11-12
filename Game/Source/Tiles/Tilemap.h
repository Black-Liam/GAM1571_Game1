#pragma once
#include "GamePCH.h"

//1 for each different looking tile
enum class TileTypes
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
    bool canWalk;
    class Mesh* tileShape;
    GLuint texture;
};

//2D array of TPs, plus functions that draws them
class Tilemap
{
public:
    TileProperties* myProperties;
    int* pLayout;
    float tileSize = 1.0f;
    //vec2 origin;
    Tilemap();
    ~Tilemap();
    void Draw(class Camera* view, fw::ShaderProgram* pShader, fw::vec2 pos);
};

