#pragma once

#include "FrameworkPCH.h"

class EventManager;

namespace fw {

    class GameCore
    {
    private:
        EventManager* m_pEventManager;
    protected:
        Framework* m_pFramework;
    public:
        GameCore(Framework* pFramework);
        ~GameCore();
        virtual void Init() = 0;
        virtual void Update(float deltaTime) = 0;
        virtual void Draw() = 0;
    };
} //namespace fw