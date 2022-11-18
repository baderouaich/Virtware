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

Executor::Executor() : 
	m_stop_keycode(VK_ESCAPE),
	m_is_executing(false)
{

}

Executor::~Executor()
{
	this->stop();
}

void Executor::set_stop_keycode(const std::uint16_t keycode) noexcept
{
	m_stop_keycode = keycode;
}

std::uint16_t Executor::get_stop_keycode() const noexcept
{
	return this->m_stop_keycode;
}

void Executor::start()
{
	stop();
	m_executing_thread.reset(new std::thread(&Executor::executing_loop, this));
	m_is_executing = true;
}

void Executor::stop()
{
	if (not m_is_executing) return;

	m_is_executing = false;
	if (m_executing_thread && m_executing_thread->joinable())
	{
		m_executing_thread->join();
	}

	// clear queue of events
	while (not m_events_queue.empty()) 
	{
		m_events_queue.pop();
	}
}

void Executor::execute(const std::shared_ptr<Event>& event)
{
	m_events_queue.push(event);
}

void Executor::execute(const std::shared_ptr<Routine>& routine)
{
	for (const std::shared_ptr<Event>& event : routine->get_events())
	{
		m_events_queue.push(event);
	}
}

const std::atomic<bool>& Executor::is_running() const noexcept
{
	return m_is_executing;
}

void Executor::executing_loop() 
{
	while (m_is_executing)
	{
		// Check first if we need to stop execution, if the key set as a stopping flag is pressed
		if (Key::is_pressed(m_stop_keycode)) 
		{
			//TODO: problem how can we stop the execution loop within the loop thread without crashing the thread
			break;
		}

		if(not m_events_queue.empty())
		{ 
			const std::shared_ptr<Event>& event = m_events_queue.front();
			do_event(event);
			m_events_queue.pop();
		}
		else // no events to execute, let's chill a bit.
			std::this_thread::yield();
	}
}

void Executor::do_event(const std::shared_ptr<Event>& event)
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
		if (MouseMoveEvent* mouse_move_event = dynamic_cast<MouseMoveEvent*>(event.get()))
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
			if (mouse_scroll_event->is_up())
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

