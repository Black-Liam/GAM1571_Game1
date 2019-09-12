#pragma once
#include "../Libraries/Framework/Source/FrameworkPCH.h"

class GameCore;

class Game :
    public GameCore
{
    void Init() override;
    void Update() override;
    void Draw() override;
};
