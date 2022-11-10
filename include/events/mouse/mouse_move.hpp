#pragma once
#include "../event.hpp"
#include "types/vec.hpp"
#include <cstdint>

namespace Virtware 
{
	/**
	* @brief MouseMoveEvent occurs when mouse is dragged across the 2D screen.
	*/
	class  MouseMoveEvent : public Event
	{
	public:
		MouseMoveEvent();
		MouseMoveEvent(const std::string& str);
		MouseMoveEvent(const std::int32_t x, const std::int32_t y);
		MouseMoveEvent(const vec2i& pos);

	public:
		vec2i get_position() const noexcept;
		std::int32_t get_x() const noexcept;
		std::int32_t get_y() const noexcept;

	public:
		std::string to_string() const override;
		void from_string(const std::string& str) override;

	private:
		std::int32_t x; /**< The new location of the mouse's x coordinate in the 2D screen */
		std::int32_t y; /**< The new location of the mouse's y coordinate in the 2D screen */
	};
}
