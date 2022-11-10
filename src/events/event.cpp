#include "core/core.hpp"
#include "events/event.hpp"

using namespace Virtware;

Event::Event(const EventType type)
    : m_type(type)
{

}

Event::EventType Event::get_type() const noexcept
{
    return m_type;
}
