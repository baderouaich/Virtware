#include "pch.hpp"
#include "io/key/key.hpp"
using namespace virtware;

bool Key::is_key_pressed(const std::uint16_t keycode) noexcept
{
/*
    const ::SHORT keystate = ::GetKeyState(keycode);
    const bool isToggled = keystate & 0b00000000'00000001;
    const bool isDown = keystate & 0b10000000'00000000;
*/     
    return !!(( 1 << 15 ) & ::GetAsyncKeyState(static_cast<std::int32_t>(keycode)));
}
bool Key::is_key_released(const std::uint16_t keycode) noexcept
{
    return !!(0b00000000'00000001 & ::GetAsyncKeyState(static_cast<std::int32_t>(keycode)));
}

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
