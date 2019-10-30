#pragma once

enum class GameObjectType
{
    Player,
    Rock,
    Camera,
    NotSet,
};

class Game;
class Mesh;
class CameraObject;

class GameObject
{
protected:
    const Game* m_pGame;
    Mesh* m_pMesh;
    fw::ShaderProgram* m_pShader;
    GameObjectType m_type;

public:
    GameObject();
    ~GameObject();
    void Init(const Game*, Mesh*, fw::ShaderProgram*, vec2);
    virtual void Update(float deltaTime, fw::Framework* p_Frame) = 0;
    void Draw(CameraObject* c);
    vec2 m_Position;

    /*
    enum class Type
    Shader*
    Mesh*
    OnEvent()


    */
};