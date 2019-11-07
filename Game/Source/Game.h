#ifndef __Game_H__
#define __Game_H__

class Ball;
class Camera;
class GameObject;
class ImGuiManager;
class Mesh;
class Player;
class PlayerController;

class Tilemap;

class Game : public fw::GameCore
{
protected:
    ImGuiManager* m_pImGuiManager;

    fw::ShaderProgram* m_pShaderColor;
    fw::ShaderProgram* m_pShaderTexture;
    Mesh* m_pMeshPlayer;
    Mesh* m_pMeshCircle;
    GLuint m_TextureBall;

    Player* m_pPlayer;
    Camera* m_pCamera;
    Ball* m_pBall;

    Tilemap* m_pTilemap;        //how and what to include?

    PlayerController* m_pController;

public:
    Game(fw::Framework* pFramework);
    virtual ~Game();

    virtual void Init() override;
    virtual void OnEvent(fw::Event* pEvent) override;
    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

    void CheckForCollisions();

    // Getters.
    float GetWorldWidth() { return 100.0f; }
    float GetWorldHeight() { return 100.0f; }
};

#endif //__Game_H__
