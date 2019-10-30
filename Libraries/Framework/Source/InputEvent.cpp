#include "FrameworkPCH.h"
#include "InputEvent.h"

namespace fw {
    InputEvent::InputEvent(EventType et, DeviceType d, KeyStates s, int i, vec2 p)
        :Event(et), m_Device(d), m_State(s), m_ID(i), m_Pos(p) {}

    int InputEvent::GetID()
    {
        return m_ID;
    }

    KeyStates InputEvent::GetState()
    {
        return m_State;
    }
}