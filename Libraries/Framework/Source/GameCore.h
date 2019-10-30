#pragma once

#include "FrameworkPCH.h"


namespace fw {

    class Event;

    class GameCore
    {
    private:
        EventManager* m_pEventManager;
    protected:
        Framework* m_pFramework;
        bool upFlag = 0;
        bool dwFlag = 0;
        bool lfFlag = 0;
        bool rtFlag = 0;
    public:
        GameCore(Framework* pFramework);
        virtual ~GameCore();
        virtual void Init() = 0;
        virtual void Update(float deltaTime) = 0;
        virtual void Draw() = 0;
        virtual void OnEvent(Event* ev) = 0;
    };
} //namespace fw