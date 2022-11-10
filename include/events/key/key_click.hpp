#pragma once
#include "../event.hpp"
#include <cstdint>

namespace Virtware
{
    class KeyClickEvent : public Event
    {
    public:
        explicit KeyClickEvent(const std::uint16_t keycode);

        std::uint16_t get_keycode() const noexcept;

    public:
        /**
         * @brief Return current event as a string representation
         * @example: key click tab
         *           key click caps_lock
         *           key click a
         * @return std::string
         */
        std::string to_string() const override;

        /**
         * @brief Instantiates current event object from string representation
         * @example: str = "key click caps_lock" will initialize KeyClickEvent::m_keycode with caps_lock's keycode
         * @param str
         */
        void from_string(const std::string& str) override;

    private:
        std::uint16_t m_keycode;
    };
}