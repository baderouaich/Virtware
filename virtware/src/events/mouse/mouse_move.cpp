#pragma once
#include "events/mouse/mouse_move.hpp"
#include <sstream>
#include <cstdio>
#include <stdexcept>
using namespace virtware;

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
#include <iostream>
void MouseMoveEvent::from_string(const std::string& str)
{
	// Scan expected format to be parsed from string and assign x and y with its correspondent values
	if (std::sscanf(str.c_str(), "mouse move %d %d", &this->x, &this->y) != 2) // EOF
		throw std::logic_error("Could not parse MouseMoveEvent from '" + str + '\'');
}

