#pragma once

#include "FrameworkPCH.h"

namespace fw {

    class EventManager
    {
    private:

    public:
        EventManager();
        ~EventManager();
        std::queue<Event*> m_Queue;
        GameCore* p_myGame;
        void PushToQueue(Event* pEvent);
        void ProcessQueue();
    };
} //namespace fw