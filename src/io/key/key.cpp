#include "pch.hpp"
#include "io/key/key.hpp"
using namespace virtware;

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
