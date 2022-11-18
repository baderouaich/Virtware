#pragma once
#include "core/core.hpp"
#include <sstream>

namespace Virtware {
	namespace ConvertUtils {

		template<typename to_t, typename from_t>
		static auto to(const from_t& value) -> to_t
		{
			to_t out{};
			std::stringstream ss{ value };
			ss >> out;
			return out;
		}

	}
}