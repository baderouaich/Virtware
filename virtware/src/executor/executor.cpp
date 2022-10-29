#include "executor/executor.hpp"
#include "events/mouse/mouse_click.hpp"
#include "events/mouse/mouse_move.hpp"
#include "events/mouse/mouse_press.hpp"
#include "events/mouse/mouse_release.hpp"
#include "events/mouse/mouse_scroll.hpp"
#include <utility>
using namespace virtware;

Executor::Executor()
{
}

Executor::~Executor()
{
}

void Executor::execute(const std::shared_ptr<Event>& event)
{
	using enum Event::EventType;
	switch (event->get_type())
	{
	case Key: {
		
		break;
	}
	case Mouse: {
		if(MouseMoveEvent* mouse_move = dynamic_cast<MouseMoveEvent*>(event.get()))
		{

		}
		break;
	}
	case Joystick: {

		break;
	}
	case Time: {

		break;
	}
	default:
		std::unreachable();
		break;
	}
}

void Executor::execute(const std::shared_ptr<Routine>& routine)
{
	for (const std::shared_ptr<Event>& event : routine->get_events())
	{
		this->execute(event);
	}
}
