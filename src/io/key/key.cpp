#include "core/core.hpp"
#include "io/key/key.hpp"
using namespace Virtware;

bool Key::is_key_pressed(const std::uint16_t keycode) noexcept
{
/*
    const ::SHORT keystate = ::GetKeyState(keycode);
    const bool isToggled = keystate & 0b00000000'00000001;
    const bool isDown = keystate & 0b10000000'00000000;
*/     
    const std::int16_t state = ::GetKeyState(static_cast<std::int32_t>(keycode));
    return !!(0b10000000'00000000ui16 & state);
}
//bool Key::is_key_toggled(const std::uint16_t keycode) noexcept
//{
//    const std::int16_t state = ::GetKeyState(static_cast<std::int32_t>(keycode));
//    return !!(0b00000000'00000001ui16 & state);
//}


void Key::press(const std::uint16_t keycode) noexcept
{
    ::INPUT input{ 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = static_cast<decltype(input.ki.wVk)>(keycode);
    input.ki.dwFlags = 0;
    ::SendInput(1, &input, sizeof(::INPUT));
}

void Key::release(const std::uint16_t keycode) noexcept
{
    ::INPUT input{ 0 };
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = static_cast<decltype(input.ki.wVk)>(keycode);
    input.ki.dwFlags = KEYEVENTF_KEYUP;
    ::SendInput(1, &input, sizeof(::INPUT));
}

void Key::click(const std::uint16_t keycode) noexcept
{
    press(keycode);
    release(keycode);
}
