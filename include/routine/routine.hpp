#pragma once

#include "events/event.hpp"
#include <vector>
#include <memory>

namespace Virtware
{
	/**
	* @brief A Routine represents a sequence of polymorphic hardware events.
	* @note A routine can be saved to file, loaded from file, simplified...etc
	*/
	class  Routine
	{
	public:
		Routine();
		~Routine();

	public:
		void add_event(const std::shared_ptr<Event>& event);
		/*void to_file(const fs::path&);
		* void from_file(const fs::path&);
		*/
	public:
		const std::vector<std::shared_ptr<Event>>& get_events() const noexcept;

	private:
		std::vector<std::shared_ptr<Event>> m_events;
	};
	
}
