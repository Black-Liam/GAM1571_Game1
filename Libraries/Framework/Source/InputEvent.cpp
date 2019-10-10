#include "FrameworkPCH.h"
#include "InputEvent.h"

fw::InputEvent::InputEvent(EventType et, DeviceType d, KeyStates s, int i, vec2 p)
    :Event(et),m_Device(d), m_State(s), m_ID(i), m_Pos(p){}
