#pragma once
#include "GameObject.h"
#include "PlayerObject.h"
#include "RockObject.h"
#include "Mesh.h"

//class ShaderProgram;
//class Event;

class Game :
    public fw::GameCore
{
protected:
    //fw::ShaderProgram* m_pShader;
    fw::Framework* m_pFramework;

    std::vector<fw::ShaderProgram*> m_pShaders;
    std::vector<Mesh*> m_pMeshes;
    std::vector<GameObject*> m_pGameObjects;
    
public:
    Game(fw::Framework* pFramework);
    ~Game();
    void Init() override;
    void OnEvent(fw::Event* pEvent);
    void Update(float deltaTime) override;
    void Draw() override;
    GameObject* CheckCollision(GameObject*);

    
    /*
    std::vector<Mesh*> m_Meshes;
    isColliding
    
    */
};
