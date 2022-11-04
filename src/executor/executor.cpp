#include "pch.hpp"
#include "executor/executor.hpp"
#include "events/mouse/mouse_click.hpp"
#include "events/mouse/mouse_move.hpp"
#include "events/mouse/mouse_press.hpp"
#include "events/mouse/mouse_release.hpp"
#include "events/mouse/mouse_scroll.hpp"
#include "events/key/key_press.hpp"
#include "events/key/key_release.hpp"
#include "events/key/key_click.hpp"
#include "io/key/key.hpp"
#include <utility>
#include <stdexcept>
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
	case Key: 
	{
		if (KeyPressEvent* key_press_event = dynamic_cast<KeyPressEvent*>(event.get()))
		{
			Key::press(key_press_event->get_keycode());
		}
		else if (KeyReleaseEvent* key_release_event = dynamic_cast<KeyReleasesEvent*>(event.get()))
		{
			Key::release(key_release_event->get_keycode());
		}
		else if (KeyClickEvent* key_click_event = dynamic_cast<KeyClickEvent*>(event.get()))
		{
			Key::click(key_click_event->get_keycode());
		}
		break;
	}
	case Mouse: {
		if(MouseMoveEvent* mouse_move_event = dynamic_cast<MouseMoveEvent*>(event.get()))
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
		throw std::out_of_range("unreachable event " + event->to_string());
		
	}
}

void Executor::execute(const std::shared_ptr<Routine>& routine)
{
	for (const std::shared_ptr<Event>& event : routine->get_events())
	{
		this->execute(event);
	}
}
