#include "core/core.hpp"
#include "executor/executor.hpp"
#include "events/time/wait.hpp"
#include "events/mouse/mouse_move.hpp"
#include "events/mouse/mouse_press.hpp"
#include "events/mouse/mouse_release.hpp"
#include "events/mouse/mouse_click.hpp"
#include "events/mouse/mouse_scroll.hpp"
#include "events/key/key_press.hpp"
#include "events/key/key_release.hpp"
#include "events/key/key_click.hpp"
#include "io/key/key.hpp"
#include <utility>
#include <stdexcept>
using namespace Virtware;

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
	case Key: 
	{
		if (KeyPressEvent* key_press_event = dynamic_cast<KeyPressEvent*>(event.get()))
		{
			Key::press(key_press_event->get_keycode());
		}
		else if (KeyReleaseEvent* key_release_event = dynamic_cast<KeyReleaseEvent*>(event.get()))
		{
			Key::release(key_release_event->get_keycode());
		}
		else if (KeyClickEvent* key_click_event = dynamic_cast<KeyClickEvent*>(event.get()))
		{
			Key::click(key_click_event->get_keycode());
		}
		else
		{
			throw std::logic_error("Unhandled Key Event '" + event->to_string() + '\'');
		}
		break;
	}
	case Mouse:
	{
		if(MouseMoveEvent* mouse_move_event = dynamic_cast<MouseMoveEvent*>(event.get()))
		{
			Mouse::set_position(mouse_move_event->get_position());
		}
#if implemented 
		else if (MousePressEvent* mouse_press_event = dynamic_cast<MousePressEvent*>(event.get()))
		{
			Mouse::press(mouse_press_event->get_button());
		}
		else if (MouseReleaseEvent* mouse_release_event = dynamic_cast<MouseReleaseEvent*>(event.get()))
		{
			Mouse::release(mouse_release_event->get_button());
		}
		else if (MouseClickEvent* mouse_click_event = dynamic_cast<MouseClickEvent*>(event.get()))
		{
			Mouse::click(mouse_click_event->get_button());
		}
		else if (MouseScrollEvent* mouse_scroll_event = dynamic_cast<MouseScrollEvent*>(event.get()))
		{
			if(mouse_scroll_event->is_up())
				Mouse::scroll_up();
			else 
				Mouse::scroll_down();
		}
		else
		{
			throw std::logic_error("Unhandled Mouse Event '" + event->to_string() + '\'');
		}
#endif
		break;
	}
	case Joystick:
	{
		throw xtd::not_implemented_exception();
	}
	case Time:
	{
		if (WaitEvent* wait_event = dynamic_cast<WaitEvent*>(event.get()))
		{
			// TODO: do we really want to halt the main thread? or shall the executor run in a separate thread?
			std::this_thread::sleep_for(wait_event->get_duration());
		}
		break;
	}
	default: 
		throw std::out_of_range("Unhandled Event Type '" + event->to_string() + '\'');
		
	}
}

void Executor::execute(const std::shared_ptr<Routine>& routine)
{
	for (const std::shared_ptr<Event>& event : routine->get_events())
	{
		this->execute(event);
	}
}
