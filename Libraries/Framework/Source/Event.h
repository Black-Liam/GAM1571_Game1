#pragma once

#include "FrameworkPCH.h"

namespace fw {

    enum class EventType {
        Input,
        NotSet,
    };

    class Event
    {
    private:
        EventType m_Type;
    public:
        Event(EventType et);
        EventType GetEventType();

    };
} //namespace fw