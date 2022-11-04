#include "pch.hpp"
#include "events/key/key_click.hpp"
#include "io/key/key.hpp"
#include <ostream>
#include <stdexcept>
using namespace virtware;

KeyClickEvent::KeyClickEvent(const std::uint16_t keycode)
    : Event(EventType::Key),
    m_keycode(keycode)
{

}

std::uint16_t KeyClickEvent::get_keycode() const noexcept
{
    return m_keycode;
}

std::string KeyClickEvent::to_string() const
{
    if (const auto it = Key::KEYBOARD.find(m_keycode);
        it != Key::KEYBOARD.end())
    {
        std::ostringstream oss{};
        oss << "key release " << it->second;
        return oss.str();
    }
    throw std::logic_error("Failed to convert KeyClickEvent to string due invalid keycode '" + std::to_string(m_keycode) + '\'');
}

void KeyClickEvent::from_string(const std::string& str)
{
    // Prepare buffer to hold key string
    std::string keyname(32, '\000');
    // Scan string format to be parsed
    if (std::sscanf(str.c_str(), "key click %s", keyname.data()) != 1)
        throw std::logic_error("Failed to parse KeyClickEvent from '" + str + '\'');

    // Validate key name
    const auto it = std::find_if(Key::KEYBOARD.begin(), Key::KEYBOARD.end(), [&keyname](const auto& key)
    {
        const auto& [keycode, valid_keyname] = key;
        return keyname == valid_keyname;
    });
    if (it != Key::KEYBOARD.end())
    {
        // Assign keycode with its correspondent value if valid
        m_keycode = it->first;
    }
    else
        throw std::logic_error("Failed to parse KeyClickEvent. Invalid key name '" + keyname + "\'.");
}