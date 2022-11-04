#include "pch.hpp"
#include "routine/routine.hpp"
using namespace virtware;

Routine::Routine()
{
}

Routine::~Routine()
{
	m_events.clear();
}

void Routine::add_event(const std::shared_ptr<Event>& event)
{
	m_events.push_back(event);
}

const std::vector<std::shared_ptr<Event>>& Routine::get_events() const noexcept
{
	return m_events;
}
