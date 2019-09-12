#pragma once
class GameCore
{
public:
    GameCore();
    ~GameCore();
    virtual void Init() =0;
    virtual void Update() = 0 ;
    virtual void Draw() = 0;
};
