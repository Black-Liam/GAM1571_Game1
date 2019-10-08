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
        EventType GetEventType();

    };
} //namespace fw