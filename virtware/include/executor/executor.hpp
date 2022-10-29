#pragma once
#include "export.hpp"
#include "events/event.hpp"
#include "routine/routine.hpp"
#include <vector>
#include <memory>

namespace virtware
{
	/**
	* @brief Executes virtual hardware events
	*/
	class virtware_export_ Executor
	{
	public:
		Executor();
		~Executor();

	public:
		void execute(const std::shared_ptr<Event>& event);
		void execute(const std::shared_ptr<Routine>& routine);
	};

}
