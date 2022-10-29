#include "events/event.hpp"

using namespace virtware;

Event::Event(const EventType type)
    : m_type(type)
{

}

Event::EventType Event::get_type() const noexcept
{
    return m_type;
}
