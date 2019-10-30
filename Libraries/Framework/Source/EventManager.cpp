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

    EventManager::~EventManager()
    {
        for (int i = 0; i < m_Queue.size(); i++)
        {
            delete m_Queue.front();
        }
    }

    void EventManager::PushToQueue(Event* pEvent)
    {
        m_Queue.push(pEvent);
    }

    void EventManager::ProcessQueue()
    {
        for (int i = 0; i < m_Queue.size(); i++)
        {
            m_pmyGame->OnEvent(m_Queue.front());
            m_Queue.pop();
        }
    }

}
