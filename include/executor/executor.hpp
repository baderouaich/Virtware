#pragma once

#include "events/event.hpp"
#include "routine/routine.hpp"
#include <vector>
#include <memory>

namespace Virtware
{
	/**
	* @brief Executes virtual hardware events
	*/
	class  Executor
	{
	public:
		Executor();
		~Executor();

	public:
		void execute(const std::shared_ptr<Event>& event);
		void execute(const std::shared_ptr<Routine>& routine);
	};

}
