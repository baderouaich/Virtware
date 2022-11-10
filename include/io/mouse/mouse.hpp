#pragma once
#include <cstdint>
#include <algorithm>
#include "types/vec.hpp"
#include "events/mouse/mouse_button.hpp"

namespace Virtware
{
	class Mouse final
	{ 
	public: // Cursor
		static vec2i get_position() noexcept;
		static void set_position(const vec2i& pos) noexcept;

	public: // Buttons
		static void press(const MouseButton button);
		static void release(const MouseButton button);
		static void click(const MouseButton button);

		//static void is_pressed(const MouseButton button);

	public: // Wheel (scroll)
		static void scroll_up();
		static void scroll_down();


	};
}