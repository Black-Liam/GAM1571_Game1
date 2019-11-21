#include "GamePCH.h"
#include "Tilemap.h"
#include "Base/Mesh.h"
#include "GameObjects/Camera.h"

#define TT0 (int)TileType::TT_Ground
#define TT1 (int)TileType::TT_Wall
#define TT2 (int)TileType::TT_Water
#define TTM (int)TileType::TT_Max


/*
{
  "mapW": 8,
  "mapH": 5,
  "tileSize": [ 5.0, 5.0 ],
  "layout": [
    [ 1, 1, 1, 1, 1, 1, 1, 1 ],
    [ 1, 0, 0, 0, 0, 0, 0, 1 ],
    [ 1, 0, 0, 2, 2, 0, 0, 1 ],
    [ 1, 0, 0, 0, 0, 0, 0, 1 ],
    [ 1, 1, 1, 1, 1, 1, 1, 1 ]  
  ]
}
*/

Tilemap::Tilemap(char* filename)
{
    // -  -  -  -  -  -  -  -  -  -  -

    long fileLen;
    char* fileContents = fw::LoadCompleteFile(filename, &fileLen);

    cJSON* jRoot = cJSON_Parse(fileContents);

    width = cJSON_GetObjectItem(jRoot, "mapW")->valueint;
    height = cJSON_GetObjectItem(jRoot, "mapH")->valueint;

    tileWidth = cJSON_GetObjectItem(jRoot, "tileW")->valueint;
    tileHeight = cJSON_GetObjectItem(jRoot, "tileH")->valueint;

    cJSON* jLayout = cJSON_GetObjectItem(jRoot, "layout");
    int sizeY = cJSON_GetArraySize(jLayout);
    assert(sizeY == m_MapSize.y);

    for (int y = 0; y < sizeY; y++)
    {
        cJSON* jRow = cJSON_GetArrayItem(jLayout, y);
        int sizeX = cJSON_GetArraySize(jRow);
        assert(sizeX == m_MapSize.x);

        for (int x = 0; x < sizeX; x++)
        {
            TileType type = (TileType)cJSON_GetArrayItem(jRow, x)->valueint;

            int index = y * m_MapSize.x + x;
            pLayout[index] = type;
        }
    }

    delete[] fileContents;
    // -  -  -  -  -  -  -  -  -  -  -  

    myProperties = new TileProperties[TTM];

    for (int i = 0; i < TTM; i++)
    {
        myProperties[i].m_pMesh = new Mesh();
        myProperties[i].m_pMesh->GenerateSquare(tileSize);
    }

    myProperties[TT0].m_IsWalkable = true;
    myProperties[TT0].m_TextureID = fw::LoadTexture("Data/Textures/TileEmpty.png");

    myProperties[TT2].m_IsWalkable = false;
    myProperties[TT2].m_TextureID = fw::LoadTexture("Data/Textures/TileWater5.png");

    myProperties[TT1].m_IsWalkable = false;
    myProperties[TT1].m_TextureID = fw::LoadTexture("Data/Textures/TileMountain2.png");

    pLayout = new TileType[5 * 8]; 
    
    //{
    //    TT1,TT1,TT1,TT1,TT1,TT1,TT1,TT1,
    //    TT1,TT0,TT0,TT0,TT0,TT0,TT0,TT1,
    //    TT1,TT0,TT0,TT2,TT2,TT0,TT0,TT1,
    //    TT1,TT0,TT0,TT0,TT0,TT0,TT0,TT1,
    //    TT1,TT1,TT1,TT1,TT1,TT1,TT1,TT1
    //};

}

Tilemap::~Tilemap()
{
    for (int i = 0; i < TTM; i++)
    {
        delete myProperties[i].m_pMesh;
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
                int layoutLocation = (i * 8) + j;
                int propertiesLocation = (int)pLayout[layoutLocation];
                myProperties[propertiesLocation].m_pMesh->Draw(view, pShader, pos + fw::vec2(j * tileSize, i * tileSize), myProperties[propertiesLocation].m_TextureID);

            }
        }

    }
}
