#pragma once
#include "core/core.hpp"
#include <cstdint>

namespace Virtware
{
	/*
#define MOUSEEVENTF_LEFTDOWN    0x0002 // left button down
#define MOUSEEVENTF_LEFTUP      0x0004 // left button up
#define MOUSEEVENTF_RIGHTDOWN   0x0008 // right button down
#define MOUSEEVENTF_RIGHTUP     0x0010 // right button up
#define MOUSEEVENTF_MIDDLEDOWN  0x0020 // middle button down
#define MOUSEEVENTF_MIDDLEUP    0x0040 // middle button up
#define MOUSEEVENTF_XDOWN       0x0080 // x button down
#define MOUSEEVENTF_XUP         0x0100 // x button down
	*/
	enum class MouseButton : std::uint8_t
	{
		Left,
		Middle,
		Right,
		Side1,
		Side2
	};
}