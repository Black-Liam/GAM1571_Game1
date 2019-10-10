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
    fw::ShaderProgram* m_pShader;
    fw::Framework* m_pFramework;

    std::vector<fw::ShaderProgram*> m_pShaders;
    std::vector<Mesh*> m_pMeshes;
    std::vector<GameObject*> m_pGameObjects;
    
    PlayerObject* m_Player;
    RockObject* m_Rock1; 
    RockObject* m_Rock2;
    RockObject* m_Rock3;
    RockObject* m_Rock4;
    RockObject* m_Rock5;
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
