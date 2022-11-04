#pragma once

#include <string>

namespace virtware
{
    class  Event
    {
    public:
        enum class EventType : std::uint8_t
        {
            Key,        // Keyboard interactions
            Mouse,      // Mouse interactions
            Joystick,   // (AKA Gamepad) interactions
            Time,       // Wait events, represents the time that passes between two events
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