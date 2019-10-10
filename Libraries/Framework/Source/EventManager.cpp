#include "FrameworkPCH.h"

namespace fw {

    EventManager::EventManager()
    {
        m_pmyGame = nullptr;
    }
    EventManager::EventManager(GameCore* gc)
    {
        m_pmyGame = gc;
    }

    void EventManager::PushToQueue(Event* pEvent)
    {
        m_Queue.push(pEvent);
    }

    void EventManager::ProcessQueue()
    {
        
    }

}
