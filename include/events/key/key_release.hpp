#pragma once
#include "../event.hpp"
#include <cstdint>

namespace virtware
{
    class KeyReleaseEvent : public Event
    {
    public:
        explicit KeyReleaseEvent(const std::uint16_t keycode);

        std::uint16_t get_keycode() const noexcept;

    public:
        /**
         * @brief Return current event as a string representation
         * @example: key release tab
         *           key release caps_lock
         *           key release a
         * @return std::string
         */
        std::string to_string() const override;

        /**
         * @brief Instantiates current event object from string representation
         * @example: str = "key release caps_lock" will initialize KeyReleaseEvent::m_keycode with caps_lock's keycode
         * @param str
         */
        void from_string(const std::string& str) override;

    private:
        std::uint16_t m_keycode;
    };
}