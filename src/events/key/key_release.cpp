#include "core/core.hpp"
#include "events/key/key_release.hpp"
#include "io/key/key.hpp"
#include <ostream>
#include <stdexcept>
using namespace Virtware;

KeyReleaseEvent::KeyReleaseEvent(const std::uint16_t keycode)
    : Event(EventType::Key),
    m_keycode(keycode)
{

}

KeyReleaseEvent::KeyReleaseEvent(const std::string& str)
    : Event(EventType::Key)
{
    this->from_string(str);
}

std::uint16_t KeyReleaseEvent::get_keycode() const noexcept
{
    return m_keycode;
}

std::string KeyReleaseEvent::to_string() const
{
    if (const auto it = Key::KEYBOARD.find(m_keycode);
        it != Key::KEYBOARD.end())
    {
        std::ostringstream oss{};
        oss << "key release " << it->second;
        return oss.str();
    }
    throw std::logic_error("Failed to convert KeyReleaseEvent to string due invalid keycode '" + std::to_string(m_keycode) + '\'');
}

void KeyReleaseEvent::from_string(const std::string& str)
{
    // Parse expected format to extract keyname
    std::string keyname;
    const std::regex rgx("key release ([a-z0-9_]{1,32})"); // e.g: key release a OR key release left_windows or key release f12 ...
    std::smatch matches;
    if (std::regex_search(str, matches, rgx) && matches.size() == 2) // matches[0] gives the whole rgx
    {
        keyname = matches[1].str();
    }
    else throw std::logic_error("Failed to parse KeyReleaseEvent from '" + str + '\'');

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
        throw std::logic_error("Failed to parse KeyReleaseEvent. Invalid key name '" + keyname + '\'');
}