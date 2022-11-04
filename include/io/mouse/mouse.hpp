#pragma once
#include <cstdint>
#include <algorithm>
#include "types/vec.hpp"

namespace virtware
{
	class Mouse final
	{ 
	public:
		static vec2i get_position() noexcept;
		static void set_position(const vec2i& pos) noexcept;
	};
}