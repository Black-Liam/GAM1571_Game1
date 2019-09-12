#pragma once
#include "../Libraries/Framework/Source/FrameworkPCH.h"

class Game :
    public fw::GameCore
{
public:
    Game();
    ~Game();
    void Init() override;
    void Update() override;
    void Draw() override;
    GLuint m_VBO;
};
