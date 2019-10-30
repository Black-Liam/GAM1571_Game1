#pragma once
#include "GameObject.h"
#include "PlayerController.h"
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
    void Update(float deltaTime) override;
    void Draw() override;
    GameObject* CheckCollision(GameObject*);
    virtual void OnEvent(fw::Event* ev) override;

    PlayerController* m_playCont;
    
    /*
    std::vector<Mesh*> m_Meshes;
    isColliding
    
    */
};
