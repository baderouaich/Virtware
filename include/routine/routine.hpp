#pragma once

#include "events/event.hpp"
#include <vector>
#include <memory>
#include <filesystem>
namespace fs = std::filesystem;

namespace Virtware
{
	/**
	* @brief A Routine represents a sequence of polymorphic hardware events.
	* @note A routine can be saved to file, loaded from file, simplified...etc
	*/
	class Routine
	{
	public:
		Routine();
		~Routine();

	public:
		//void from_file(const fs::path& filename);
		//void from_instructions_list(const std::vector<std::string>& instructions);

	public:
		void add_event(const std::shared_ptr<Event>& event);
		// from "key press a" for example
		void add_event(const std::string& event_text);

		void to_file(const fs::path& filename);
		void from_file(const fs::path& filename);
		
	public:
		const std::vector<std::shared_ptr<Event>>& get_events() const noexcept;

	private:
		std::vector<std::shared_ptr<Event>> m_events;
	};
	
}
