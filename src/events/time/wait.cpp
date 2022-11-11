#include "core/core.hpp"
#include "events/time/wait.hpp"
using namespace Virtware;

WaitEvent::WaitEvent() : 
	Event(EventType::Time)
{
}

WaitEvent::WaitEvent(const std::string& str) : 
    Event(EventType::Time)
{
    this->from_string(str);
}

WaitEvent::WaitEvent(const std::chrono::system_clock::duration& duration, const std::string& suffix)
	:
	Event(EventType::Time),
	m_duration(duration),
	m_suffix(suffix)
{
}

WaitEvent::WaitEvent(const std::size_t units, const std::string& suffix)
    : Event(EventType::Time)
{
    this->from_string("wait " + std::to_string(units) + suffix);
}

WaitEvent::WaitEvent(const std::chrono::microseconds& duration)
	: WaitEvent(duration, MICROSECONDS_PREFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::milliseconds& duration)
	: WaitEvent(duration, MILLISECONDS_PREFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::seconds& duration)
	: WaitEvent(duration, SECONDS_PREFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::minutes& duration)
	: WaitEvent(duration, MINUTES_PREFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::hours& duration)
	: WaitEvent(duration, HOURS_PREFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::days& duration)
	: WaitEvent(duration, DAYS_PREFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::weeks& duration)
	: WaitEvent(duration, WEEKS_PREFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::months& duration)
    : WaitEvent(duration, MONTHS_PREFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::years& duration)
    : WaitEvent(duration, YEARS_PREFIX)
{
}

const std::chrono::system_clock::duration& WaitEvent::get_duration() const noexcept
{
    return m_duration;
}


std::string WaitEvent::to_string() const
{
    std::ostringstream oss{};
    oss << "wait ";
    if (m_suffix == MICROSECONDS_PREFIX)
        oss << std::chrono::duration_cast<std::chrono::microseconds>(m_duration).count();
    else if (m_suffix == MILLISECONDS_PREFIX)
        oss << std::chrono::duration_cast<std::chrono::milliseconds>(m_duration).count();
    else if (m_suffix == SECONDS_PREFIX)
        oss << std::chrono::duration_cast<std::chrono::seconds>(m_duration).count();
    else if (m_suffix == MINUTES_PREFIX)
        oss << std::chrono::duration_cast<std::chrono::minutes>(m_duration).count();
    else if (m_suffix == HOURS_PREFIX)
        oss << std::chrono::duration_cast<std::chrono::hours>(m_duration).count();
    else if (m_suffix == DAYS_PREFIX)
        oss << std::chrono::duration_cast<std::chrono::days>(m_duration).count();
    else if (m_suffix == WEEKS_PREFIX)
        oss << std::chrono::duration_cast<std::chrono::weeks>(m_duration).count();
    else if (m_suffix == MONTHS_PREFIX)
        oss << std::chrono::duration_cast<std::chrono::months>(m_duration).count();
    else if (m_suffix == YEARS_PREFIX)
        oss << std::chrono::duration_cast<std::chrono::years>(m_duration).count();
    else
        throw std::logic_error("Invalid WaitEvent duration suffix '" + m_suffix + '\'');
    oss << m_suffix;
    return oss.str();
}

void WaitEvent::from_string(const std::string& str)
{
    // Scan expected format to extract duration count and duration suffix
    std::size_t units{ 0 };
    char duration_suffix[32]{'\000'};
    if (std::sscanf(str.c_str(), "wait %zu%32s", &units, duration_suffix) != 2)
        throw std::logic_error("Failed to parse WaitEvent from '" + str + '\'');
    // Assign duration suffix
    m_suffix = std::string(duration_suffix);
    // Assign duration count according to  duration suffix
    if (m_suffix == MICROSECONDS_PREFIX)
        m_duration = std::chrono::microseconds(units);
    else if (m_suffix == MILLISECONDS_PREFIX)
        m_duration = std::chrono::milliseconds(units);
    else if (m_suffix == SECONDS_PREFIX)
        m_duration = std::chrono::seconds(units);
    else if (m_suffix == MINUTES_PREFIX)
        m_duration = std::chrono::minutes(units);
    else if (m_suffix == HOURS_PREFIX)
        m_duration = std::chrono::hours(units);
    else if (m_suffix == DAYS_PREFIX)
        m_duration = std::chrono::days(units);
    else if (m_suffix == WEEKS_PREFIX)
        m_duration = std::chrono::weeks(units);
    else if (m_suffix == MONTHS_PREFIX)
        m_duration = std::chrono::months(units);
    else if (m_suffix == YEARS_PREFIX)
        m_duration = std::chrono::years(units);
    else
        throw std::logic_error("Failed to parse WaitEvent from '" + str + '\'');
}