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


class GameObject
{
private:
    Game* m_pGame;
    Mesh* m_pMesh;
    fw::ShaderProgram* m_pShader;
    vec2 m_Position;
    GameObjectType m_type;

public:
    GameObject();
    ~GameObject();
    void Init(Game*, Mesh*, fw::ShaderProgram*, vec2);
    virtual void Update(float deltaTime, fw::Framework* p_Frame) = 0;
    void Draw();

    /*
    enum class Type
    Shader*
    Mesh*
    OnEvent()


    */
};