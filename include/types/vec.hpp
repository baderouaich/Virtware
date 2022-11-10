#pragma once
#include <concepts>
#include <cstdint>

namespace Virtware
{
	template <typename T> 
	requires std::is_integral_v<T> or std::is_floating_point_v<T> // equiv to std::is_arithmetic_v<T>
	struct vec2 
	{
		T x;
		T y;

		constexpr vec2(const T& _x, const T& _y) noexcept
			: x(_x), y(_y)
		{

		}

		constexpr bool operator==(const vec2<T>& other) const noexcept
		{
			return this->x == other.x and this->y == other.y;
		}
		constexpr bool operator!=(const vec2<T>& other) const noexcept
		{
			return not ((*this) == other);
		}
			
	};

	using vec2i = vec2<std::int32_t>;
	using vec2u = vec2<std::uint32_t>;
	using vec2ll = vec2<std::int64_t>;
	using vec2ull = vec2<std::uint64_t>;
	using vec2f = vec2<float>;
	using vec2d = vec2<double>;
}