#pragma once
#include "GamePCH.h"

//1 for each different looking tile
enum class TileTypes
{

};

//what does the tile do + has a mesh & Texture ids
struct TileProperties
{
    bool canWalk;
    class Mesh* tileShape;
    GLuint texture;
};

//2D array of TPs, plus functions that draws them
class Tilemap
{
    TileProperties** myMap;
    //vec2 origin;
    Tilemap();
    void Draw();
};

