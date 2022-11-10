#pragma once
#include "events/event.hpp"
#include <chrono>
#include <string>
#include <sstream>

namespace Virtware
{
	class WaitEvent : public Event
	{
    public:
        //static inline const std::string NANOSECONDS_PREFIX = "nc";
        static inline const std::string MICROSECONDS_PREFIX = "mc";
        static inline const std::string MILLISECONDS_PREFIX = "ms";
        static inline const std::string SECONDS_PREFIX = "s";
        static inline const std::string MINUTES_PREFIX = "min";
        static inline const std::string HOURS_PREFIX = "hr";
        static inline const std::string DAYS_PREFIX = "d";
        static inline const std::string WEEKS_PREFIX = "w";
        static inline const std::string MONTHS_PREFIX = "mon";
        static inline const std::string YEARS_PREFIX = "yr";

	public:
		WaitEvent();
		WaitEvent(const std::chrono::system_clock::duration& duration, const std::string& suffix);
		WaitEvent(const std::size_t units, const std::string& suffix);
        //explicit WaitEvent(const std::chrono::nanoseconds& duration);
        explicit WaitEvent(const std::chrono::microseconds& duration);
		explicit WaitEvent(const std::chrono::milliseconds& duration);
		explicit WaitEvent(const std::chrono::seconds& duration);
		explicit WaitEvent(const std::chrono::minutes& duration);
		explicit WaitEvent(const std::chrono::hours& duration);
		explicit WaitEvent(const std::chrono::days& duration);
		explicit WaitEvent(const std::chrono::weeks& duration);
		explicit WaitEvent(const std::chrono::months& duration);
		explicit WaitEvent(const std::chrono::years& duration);

    public:
        const std::chrono::system_clock::duration& get_duration() const noexcept;

    public:
        /**
         * @brief Return current event as a string representation.
         * @example: wait 100ms
         *           wait 2s
         *
         * @return std::string
         */
        std::string to_string() const override;

        /**
         * @brief Instantiates current event object from string representation.
         * @example: str = "wait 300ms" will initialize WaitEvent::duration to 300ms
         * @param str
         */
        void from_string(const std::string& str) override;

	private:
		std::chrono::system_clock::duration m_duration; /**< Duration to wait for */
		std::string m_suffix; /**< Suffix string after duration number, example: 300ms, 1s, 10hr ... */
	};
}