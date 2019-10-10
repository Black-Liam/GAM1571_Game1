#include "FrameworkPCH.h"

namespace fw {
    Event::Event(EventType et):m_Type(et){}

    EventType fw::Event::GetEventType()
    {
        return m_Type;
    }

}
