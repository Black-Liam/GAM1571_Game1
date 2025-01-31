#include "GamePCH.h"
#include "Tilemap.h"
#include "Base/Mesh.h"
#include "GameObjects/Camera.h"

#define TT0 (int)TileType::TT_Ground
#define TT1 (int)TileType::TT_Wall
#define TT2 (int)TileType::TT_Water
#define TTM (int)TileType::TT_Max


/*

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
    assert(sizeY == height);

    for (int y = 0; y < sizeY; y++)
    {
        cJSON* jRow = cJSON_GetArrayItem(jLayout, y);
        int sizeX = cJSON_GetArraySize(jRow);
        assert(sizeX == width);

        for (int x = 0; x < sizeX; x++)
        {
            TileType type = (TileType)cJSON_GetArrayItem(jRow, x)->valueint;

            int index = y * width + x;
            pLayout[index] = type;
        }
    }

    delete[] fileContents;
    // -  -  -  -  -  -  -  -  -  -  -  

    myProperties = new TileProperties[TTM];

    for (int i = 0; i < TTM; i++)
    {
        myProperties[i].m_pMesh = new Mesh();
        myProperties[i].m_pMesh->GenerateSquare(tileHeight);
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

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                int tileIndex = (y * width) + x;
                TileType propertiesLocation = pLayout[tileIndex];
                TileProperties* pProp = &myProperties[tileIndex];
                fw::vec2 offset(x * tileWidth, y * tileHeight);


                pProp.m_pMesh->Draw(view, pShader, pos + offset, myProperties[propertiesLocation].m_TextureID);

            }
        }

    }
}
