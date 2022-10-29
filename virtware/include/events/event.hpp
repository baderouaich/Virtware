#pragma once
#include "export.hpp"
#include <string>

namespace virtware
{
    class virtware_export_ Event
    {
    public:
        enum class EventType
        {
            Key,
            Mouse,
            Joystick,
            Time
        };

    public:
        explicit Event(const EventType type);

    public:
        /**
         * @brief Returns the string representation of the event
         * @example: MouseMoveEvent{100, 50}.to_string() => "mouse move 100 50"
         */
        virtual std::string to_string() const = 0;
 
        /**
         * @brief Initializes current event object from string representation
         */
        virtual void from_string(const std::string& str) = 0;

    public:
        EventType get_type() const noexcept;

    protected:
        EventType m_type;
    };
}