#include "core/core.hpp"
#include "events/key/key_click.hpp"
#include "io/key/key.hpp"
#include <ostream>
#include <stdexcept>
using namespace Virtware;

KeyClickEvent::KeyClickEvent(const std::uint16_t keycode)
    : Event(EventType::Key),
    m_keycode(keycode)
{

}

KeyClickEvent::KeyClickEvent(const std::string& str)
    : Event(EventType::Key)
{
    this->from_string(str);
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
        oss << "key click " << it->second;
        return oss.str();
    }
    throw std::logic_error("Failed to convert KeyClickEvent to string due invalid keycode '" + std::to_string(m_keycode) + '\'');
}

void KeyClickEvent::from_string(const std::string& str)
{
    // Parse expected format to extract keyname
    std::string keyname;
    const std::regex rgx("key click ([a-z0-9_]{1,32})"); // e.g: key click a OR key click left_windows or key click f12 ...
    std::smatch matches;
    if (std::regex_search(str, matches, rgx) && matches.size() == 2) // matches[0] gives the whole rgx
    {
        keyname = matches[1].str();
    }
    else throw std::logic_error("Failed to parse KeyClickEvent from '" + str + '\'');

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
        throw std::logic_error("Failed to parse KeyClickEvent. Invalid key name '" + keyname + '\'');
}