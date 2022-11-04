#pragma once

#include <string>

namespace virtware
{
    class  Event
    {
    public:
        enum class EventType
        {
            Key,        // Keyboard interactions
            Mouse,      // Mouse interactions
            Joystick,   // aka Gamepad interactions
            Time,       // The do nothing event (HALT), represents the gape between events, or duration to wait before launching an event..
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