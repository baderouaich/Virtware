#pragma once
#include "export.hpp"
#include "events/event.hpp"
#include <vector>
#include <memory>

namespace virtware
{
	/**
	* @brief A Routine represents a sequence of polymorphic events.
	*/
	class virtware_export_ Routine
	{
	public:
		Routine();
		~Routine();

	public:
		void add_event(const std::shared_ptr<Event>& event);
	
	public:
		const std::vector<std::shared_ptr<Event>>& get_events() const noexcept;

	private:
		std::vector<std::shared_ptr<Event>> m_events;
	};
	
}
