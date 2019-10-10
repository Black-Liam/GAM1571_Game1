#pragma once

#include "FrameworkPCH.h"

namespace fw {

    class EventManager
    {
    private:

    public:
        EventManager();
        EventManager(GameCore* gc);
        ~EventManager();
        std::queue<Event*> m_Queue;
        GameCore* m_pmyGame;
        void PushToQueue(Event* pEvent);
        void ProcessQueue();
    };
} //namespace fw