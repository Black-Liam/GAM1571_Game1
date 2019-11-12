#include "GamePCH.h"
#include "Tilemap.h"
#include "Base/Mesh.h"
#include "GameObjects/Camera.h"

#define TT0 (int)TileTypes::TT_Ground
#define TT1 (int)TileTypes::TT_Wall
#define TT2 (int)TileTypes::TT_Water
#define TTM (int)TileTypes::TT_Max

Tilemap::Tilemap()
{
    myProperties = new TileProperties[TTM];

    for (int i = 0; i < TTM; i++)
    {
        myProperties[i].tileShape = new Mesh();
        myProperties[i].tileShape->GenerateSquare(tileSize);
    }

    myProperties[TT0].canWalk = true;
    myProperties[TT0].texture = fw::LoadTexture("Data/Textures/TileEmpty.png");

    myProperties[TT2].canWalk = false;
    myProperties[TT2].texture = fw::LoadTexture("Data/Textures/TileWater5.png");

    myProperties[TT1].canWalk = false;
    myProperties[TT1].texture = fw::LoadTexture("Data/Textures/TileMountain2.png");

    pLayout = new int[5 * 8];
    int layout[5 * 8] =
    {
        TT1,TT1,TT1,TT1,TT1,TT1,TT1,TT1,
        TT1,TT0,TT0,TT0,TT0,TT0,TT0,TT1,
        TT1,TT0,TT0,TT2,TT2,TT0,TT0,TT1,
        TT1,TT0,TT0,TT0,TT0,TT0,TT0,TT1,
        TT1,TT1,TT1,TT1,TT1,TT1,TT1,TT1
    };
    for (int i = 0; i < 5 * 8; i++)
    {
        pLayout[i] = layout[i];
    }
}

Tilemap::~Tilemap()
{
    for (int i = 0; i < TTM; i++)
    {
        delete myProperties[i].tileShape;
    }
    delete[] myProperties;
    delete[] pLayout;
}

void Tilemap::Draw(Camera* view, fw::ShaderProgram* pShader, fw::vec2 pos)            //What do I put in here again?
{
    if (pLayout != nullptr)
    {

        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                int layoutLocation = (i * j) + j;
                int propertiesLocation = (int)pLayout[layoutLocation];
                myProperties[propertiesLocation].tileShape->Draw(view, pShader, pos + fw::vec2(j * tileSize, i * tileSize), myProperties[propertiesLocation].texture);

            }
        }

    }
}
