#include "core/core.hpp"
#include "routine/routine.hpp"

#include "events/mouse/mouse_move.hpp"
#include "events/mouse/mouse_press.hpp"
#include "events/mouse/mouse_release.hpp"
#include "events/mouse/mouse_click.hpp"
#include "events/mouse/mouse_scroll.hpp"

#include "events/key/key_press.hpp"
#include "events/key/key_release.hpp"
#include "events/key/key_click.hpp"

#include "events/time/wait.hpp"

#include <fstream>

using namespace Virtware;

Routine::Routine()
{
}

Routine::~Routine()
{
	m_events.clear();
}

void Routine::add_event(const std::string& event_text)
{
#define	DETECT_EVENT_STR1(prefix, event_klass) if (event_text.starts_with(prefix)) { \
			event = std::make_shared<event_klass>(event_text); \
		}
#define DETECT_EVENT_STR(prefix, event_klass) else DETECT_EVENT_STR1(prefix, event_klass)


	std::shared_ptr<Event> event{ nullptr };
	DETECT_EVENT_STR1("key press", KeyPressEvent)
	DETECT_EVENT_STR("key release", KeyReleaseEvent)
	DETECT_EVENT_STR("key click", KeyClickEvent)

	DETECT_EVENT_STR("mouse move", MouseMoveEvent)
	//DETECT_EVENT_STR(str, "mouse press", MousePressEvent)
	//DETECT_EVENT_STR(str, "mouse release", MouseReleaseEvent)
	//DETECT_EVENT_STR(str, "mouse scroll", MouseScrollEvent)

	DETECT_EVENT_STR("wait", WaitEvent)
	else
	{
		throw std::logic_error("Could not detect event from '" + event_text + '\'');
	}
	//TODO: handle other events


	this->add_event(event);

#undef DETECT_EVENT_STR1
#undef DETECT_EVENT_STR
}

void Routine::to_file(const fs::path& filename)
{
	if (std::ofstream ofs{ filename })
	{
		for (const std::shared_ptr<Event>& event : m_events)
		{
			ofs << event->to_string() << '\n';
		}
		ofs.close();
	}
	else throw std::runtime_error("Could not save routine to file " + filename.string());
}

void Routine::from_file(const fs::path& filename)
{
	if (std::ifstream ifs{ filename })
	{
		std::string line;
		while (std::getline(ifs, line))
		{
			// Skip empty lines and comments
			line = xtd::ustring(line).trim();
			if (line.empty() or line.starts_with("#") or line.starts_with("//")) continue;
			this->add_event(line);
		}
		ifs.close();
	}
	else throw std::runtime_error("Could not read routine from file " + filename.string());
}

void Routine::add_event(const std::shared_ptr<Event>& event)
{
	m_events.push_back(event);
}

const std::vector<std::shared_ptr<Event>>& Routine::get_events() const noexcept
{
	return m_events;
}
