#include "core/core.hpp"
#include "events/mouse/mouse_move.hpp"
#include "utils/convert_utils.hpp"
#include <sstream>
#include <cstdio>
#include <stdexcept>
using namespace Virtware;

MouseMoveEvent::MouseMoveEvent() :
	Event(Event::EventType::Mouse),
	x(0), y(0)
{
}
MouseMoveEvent::MouseMoveEvent(const std::string& str) :
	Event(Event::EventType::Mouse),
	x(0), y(0)
{
	this->from_string(str);
}
MouseMoveEvent::MouseMoveEvent(const std::int32_t px, const std::int32_t py) :
	Event(Event::EventType::Mouse), 
	x(px), y(py) 
{
}

MouseMoveEvent::MouseMoveEvent(const vec2i& pos) :
	Event(Event::EventType::Mouse),
	x(pos.x), y(pos.y)
{
}

vec2i MouseMoveEvent::get_position() const noexcept
{
	return vec2i(x, y);
}

std::int32_t MouseMoveEvent::get_x() const noexcept
{
	return this->x;
}

std::int32_t MouseMoveEvent::get_y() const noexcept
{
	return this->y;
}

std::string MouseMoveEvent::to_string() const
{
	std::ostringstream oss{};
	oss << "mouse move " << this->x << ' ' << this->y;
	return oss.str();
}

void MouseMoveEvent::from_string(const std::string& str)
{
	// Parse expected format to extract x and y)
	const std::regex rgx("mouse move ([0-9]{1,10}) ([0-9]{1,10})"); // e.g: mouse move 100 160
	std::smatch matches;
	if (std::regex_search(str, matches, rgx) && matches.size() == 3) // matches[0] gives the whole rgx
	{
		this->x = ConvertUtils::to<decltype(this->x)>(matches[1].str());
		this->y = ConvertUtils::to<decltype(this->y)>(matches[2].str());
	}
	else throw std::logic_error("Failed to parse MouseMoveEvent from '" + str + '\'');
}

