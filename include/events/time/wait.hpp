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
        using duration_t = std::chrono::high_resolution_clock::duration;

    public:
        static inline constexpr const char NANOSECONDS_SUFFIX  [] = "ns";
        static inline constexpr const char MICROSECONDS_SUFFIX [] = "mc";
        static inline constexpr const char MILLISECONDS_SUFFIX [] = "ms";
        static inline constexpr const char SECONDS_SUFFIX      [] = "s";
        static inline constexpr const char MINUTES_SUFFIX      [] = "min";
        static inline constexpr const char HOURS_SUFFIX        [] = "hr";
        static inline constexpr const char DAYS_SUFFIX         [] = "d";
        static inline constexpr const char WEEKS_SUFFIX        [] = "w";
        static inline constexpr const char MONTHS_SUFFIX       [] = "mon";
        static inline constexpr const char YEARS_SUFFIX        [] = "yr";

	public:
        WaitEvent();
        WaitEvent(const std::string& str);
		WaitEvent(const duration_t& duration, const std::string& suffix);
		WaitEvent(const std::int64_t units, const std::string& suffix);
        explicit WaitEvent(const std::chrono::nanoseconds& duration);
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
        const duration_t& get_duration() const noexcept;

#if 0
        std::shared_ptr<WaitEvent> get() {
            std::chrono::system_clock::duration dur = m_duration;
            const auto count = dur.count();

            
            // Simplify 1000ms to 1s ...
            if (count >= 1000)
            {
               
                if (m_suffix == MICROSECONDS_SUFFIX)
                {
                    return std::make_shared<WaitEvent>(std::chrono::duration_cast<std::chrono::milliseconds>(dur));
                }
                else if (m_suffix == MILLISECONDS_SUFFIX)
                {
                    return std::make_shared<WaitEvent>(std::chrono::duration_cast<std::chrono::seconds>(dur));
                }
                else if (m_suffix == SECONDS_SUFFIX)
                {
                    return std::make_shared<WaitEvent>(std::chrono::duration_cast<std::chrono::minutes>(dur));
                }
            }
            else
            {
                return std::make_shared<WaitEvent>(dur);
            }
            
        }
#endif

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
        duration_t m_duration; /**< Duration to wait for (we need a high resolution clock for nanoseconds) */
		std::string m_suffix; /**< Suffix string after duration number, example: 300ms, 1s, 10hr ... */
	};
}