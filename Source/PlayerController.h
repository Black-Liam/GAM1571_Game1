#pragma once

class PlayerController
{

public:
    bool dwFlag = 0;
    bool upFlag = 0;
    bool lfFlag = 0;
    bool rtFlag = 0;
    void OnEvent(fw::InputEvent* ie);
};