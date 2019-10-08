#pragma once

#include "FrameworkPCH.h"

namespace fw {

    enum class DeviceType {
        Keyboard,
        Mouse,
        NotSet,
    };

    enum class KeyStates {
        Pressed,
        Held,
        Release,
        NotSet,
    };

    class InputEvent : public Event
    {
    private:
        DeviceType m_Device;
        KeyStates m_State;
        int m_ID;
        vec2 m_Pos;
    public:
        InputEvent(DeviceType d, KeyStates s, int i, vec2 p);
    };
} //namespace fw