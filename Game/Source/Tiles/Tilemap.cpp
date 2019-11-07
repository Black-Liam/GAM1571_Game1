#include "GamePCH.h"
#include "Tilemap.h"
#include "Base/Mesh.h"

Tilemap::Tilemap()
{
    int arraySize = (int)TileTypes::TT_Max;
    myProperties = new TileProperties[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        myProperties[i].tileShape = new Mesh();
        myProperties[i].tileShape->GenerateSquare(tileSize);
    }

    myProperties[(int)TileTypes::TT_Ground].canWalk = true;
    myProperties[(int)TileTypes::TT_Ground].texture = fw::LoadTexture("Data/Textures/TileEmpty.png");

    myProperties[(int)TileTypes::TT_Water].canWalk = false;
    myProperties[(int)TileTypes::TT_Water].texture = fw::LoadTexture("Data/Textures/TileWater5.png");

    myProperties[(int)TileTypes::TT_Wall].canWalk = false;
    myProperties[(int)TileTypes::TT_Wall].texture = fw::LoadTexture("Data/Textures/TileMountain2.png");

    pLayout = new TileTypes
    [
        2,2,2,2,2,2,2,2,
        2,0,0,0,0,0,0,2,
        2,0,0,1,1,0,0,2,
        2,0,0,0,0,0,0,2,
        2,2,2,2,2,2,2,2
    ];
}

Tilemap::~Tilemap()
{
    for (int i = 0; i < (int)TileTypes::TT_Max; i++)
    {
        delete myProperties[i].tileShape;
    }
    delete[] myProperties;
    delete[] pLayout;
}

void Tilemap::Draw()            //What do I put in here again?
{

}
