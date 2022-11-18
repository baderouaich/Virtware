#include "core/core.hpp"
#include "events/time/wait.hpp"
#include <cinttypes> // PRId64 and SCNd64
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

WaitEvent::WaitEvent(const duration_t& duration, const std::string& suffix)
	:
	Event(EventType::Time),
	m_duration(duration),
	m_suffix(suffix)
{
}

WaitEvent::WaitEvent(const std::int64_t units, const std::string& suffix)
    : Event(EventType::Time)
{
    this->from_string("wait " + std::to_string(units) + suffix);
}

WaitEvent::WaitEvent(const std::chrono::nanoseconds& duration)
    : WaitEvent(duration, NANOSECONDS_SUFFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::microseconds& duration)
	: WaitEvent(duration, MICROSECONDS_SUFFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::milliseconds& duration)
	: WaitEvent(duration, MILLISECONDS_SUFFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::seconds& duration)
	: WaitEvent(duration, SECONDS_SUFFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::minutes& duration)
	: WaitEvent(duration, MINUTES_SUFFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::hours& duration)
	: WaitEvent(duration, HOURS_SUFFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::days& duration)
	: WaitEvent(duration, DAYS_SUFFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::weeks& duration)
	: WaitEvent(duration, WEEKS_SUFFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::months& duration)
    : WaitEvent(duration, MONTHS_SUFFIX)
{
}

WaitEvent::WaitEvent(const std::chrono::years& duration)
    : WaitEvent(duration, YEARS_SUFFIX)
{
}

const WaitEvent::duration_t& WaitEvent::get_duration() const noexcept
{
    return m_duration;
}


std::string WaitEvent::to_string() const
{
    std::ostringstream oss{};
    oss << "wait ";
    if (m_suffix == NANOSECONDS_SUFFIX)
        oss << std::chrono::duration_cast<std::chrono::nanoseconds> (m_duration).count();
    else if (m_suffix == MICROSECONDS_SUFFIX)
        oss << std::chrono::duration_cast<std::chrono::microseconds> (m_duration).count();
    else if (m_suffix == MILLISECONDS_SUFFIX)
        oss << std::chrono::duration_cast<std::chrono::milliseconds>(m_duration).count();
    else if (m_suffix == SECONDS_SUFFIX)
        oss << std::chrono::duration_cast<std::chrono::seconds>(m_duration).count();
    else if (m_suffix == MINUTES_SUFFIX)
        oss << std::chrono::duration_cast<std::chrono::minutes>(m_duration).count();
    else if (m_suffix == HOURS_SUFFIX)
        oss << std::chrono::duration_cast<std::chrono::hours>(m_duration).count();
    else if (m_suffix == DAYS_SUFFIX)
        oss << std::chrono::duration_cast<std::chrono::days>(m_duration).count();
    else if (m_suffix == WEEKS_SUFFIX)
        oss << std::chrono::duration_cast<std::chrono::weeks>(m_duration).count();
    else if (m_suffix == MONTHS_SUFFIX)
        oss << std::chrono::duration_cast<std::chrono::months>(m_duration).count();
    else if (m_suffix == YEARS_SUFFIX)
        oss << std::chrono::duration_cast<std::chrono::years>(m_duration).count();
    else
        throw std::logic_error("Invalid WaitEvent duration suffix '" + m_suffix + '\'');
    oss << m_suffix;
    return oss.str();
}
#include <regex>
#include "utils/convert_utils.hpp"

void WaitEvent::from_string(const std::string& str)
{
    // Parse expected format to extract duration count and duration suffix
    std::int64_t units{ 0 };
    std::string suffix;
    const std::regex rgx("wait ([0-9]{1,})([a-z]{1,3})"); // e.g: wait 10ms
    std::smatch matches;
    if (std::regex_search(str, matches, rgx) && matches.size() == 3) // matches[0] gives the whole rgx
    {
        units = ConvertUtils::to<std::int64_t>(matches[1].str());
        suffix = matches[2].str();
    }      
    else throw std::logic_error("Failed to parse WaitEvent from '" + str + '\'');
    
    // Assign duration count according to  duration suffix
    if (suffix == NANOSECONDS_SUFFIX)
        m_duration = std::chrono::nanoseconds(units);
    else if (suffix == MICROSECONDS_SUFFIX)
        m_duration = std::chrono::microseconds(units);
    else if (suffix == MILLISECONDS_SUFFIX)
        m_duration = std::chrono::milliseconds(units);
    else if (suffix == SECONDS_SUFFIX)
        m_duration = std::chrono::seconds(units);
    else if (suffix == MINUTES_SUFFIX)
        m_duration = std::chrono::minutes(units);
    else if (suffix == HOURS_SUFFIX)
        m_duration = std::chrono::hours(units);
    else if (suffix == DAYS_SUFFIX)
        m_duration = std::chrono::days(units);
    else if (suffix == WEEKS_SUFFIX)
        m_duration = std::chrono::weeks(units);
    else if (suffix == MONTHS_SUFFIX)
        m_duration = std::chrono::months(units);
    else if (suffix == YEARS_SUFFIX)
        m_duration = std::chrono::years(units);
    else
        throw std::logic_error("Failed to parse WaitEvent from '" + str + '\'' + ". Invalid duration suffix '" + (std::string&)suffix + '\'');

    // Assign duration suffix if things are fine
    m_suffix = suffix;
}
