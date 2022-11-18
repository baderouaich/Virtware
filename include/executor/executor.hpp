#pragma once

#include "events/event.hpp"
#include "routine/routine.hpp"
#include <memory>
#include <queue>

namespace Virtware
{
	/**
	* @brief Executes a queue of virtual hardware events in a parallel thread
	*/
	class Executor
	{
	public:
		Executor();
		~Executor();

	public:
		void set_stop_keycode(const std::uint16_t keycode) noexcept;
		std::uint16_t get_stop_keycode() const noexcept;

		void start();
		void stop();
		void execute(const std::shared_ptr<Event>& event);
		void execute(const std::shared_ptr<Routine>& routine);

	public:
		const std::atomic<bool>& is_running() const noexcept;

	private:
		void executing_loop();
		void do_event(const std::shared_ptr<Event>& event); // the actual execution of the event

	private:
		std::queue<std::shared_ptr<Event>> m_events_queue; /*< Queue of events to execute in a parallel thread */
		std::atomic<bool> m_is_executing;
		std::unique_ptr<std::thread> m_executing_thread;

		std::uint16_t m_stop_keycode; /*< Escape key by default, If this key was clicked during the execution, it will stop */
	};
}
