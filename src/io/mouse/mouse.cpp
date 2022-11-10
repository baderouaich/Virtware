#include "core/core.hpp"
#include "io/mouse/mouse.hpp"

using namespace Virtware;

vec2i Mouse::get_position() noexcept
{
    ::POINT point{ .x = 0, .y = 0 };
    ::GetCursorPos(&point);
    return vec2i(point.x, point.y);
}

void Mouse::set_position(const vec2i& pos) noexcept
{
    const std::int32_t screen_width = ::GetSystemMetrics(SM_CXSCREEN);
    const std::int32_t screen_height = ::GetSystemMetrics(SM_CYSCREEN);

    const float fx = pos.x * (65536.0f / screen_width);   // x being coord in pixels
    const float fy = pos.y * (65536.0f / screen_height);  // y being coord in pixels

    ::INPUT input{ 0 };
    input.type = INPUT_MOUSE;
    input.mi.dx = static_cast<decltype(input.mi.dx)>(fx);
    input.mi.dy = static_cast<decltype(input.mi.dy)>(fy);
    input.mi.dwFlags = MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE;
    ::SendInput(1, &input, sizeof(::INPUT));
}

void Mouse::press(const MouseButton button)
{
    using enum MouseButton;

    INPUT input{ 0 };
    input.type = INPUT_MOUSE;
    switch (button)
    {
        case Left:
        {
            input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            break;
        }
        case Middle:
        {
            input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
            break;
        }
        case Right:
        {
            input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

            break;
        }
        case Side1:
        {
            input.mi.dwFlags = MOUSEEVENTF_XDOWN | XBUTTON1;
            break;
        }
        case Side2:
        {
            input.mi.dwFlags = MOUSEEVENTF_XDOWN | XBUTTON2;
            break;
        }
        default:
            throw std::logic_error("Invalid mouse button");
            break;
    }
    ::SendInput(1, &input, sizeof(::INPUT));
}

void Mouse::release(const MouseButton button)
{
    using enum MouseButton;

    INPUT input{ 0 };
    input.type = INPUT_MOUSE;
    switch (button)
    {
    case Left:
    {
        input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        break;
    }
    case Middle:
    {
        input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
        break;
    }
    case Right:
    {
        input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;

        break;
    }
    case Side1:
    {
        input.mi.dwFlags = MOUSEEVENTF_XUP | XBUTTON1;
        break;
    }
    case Side2:
    {
        input.mi.dwFlags = MOUSEEVENTF_XUP | XBUTTON2;
        break;
    }
    default:
        throw std::logic_error("Invalid mouse button");
        break;
    }
    ::SendInput(1, &input, sizeof(::INPUT));
}

void Mouse::click(const MouseButton button)
{
    press(button);
    release(button);
}

void Mouse::scroll_up()
{
    ::INPUT input{ 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    input.mi.mouseData = WHEEL_DELTA;
    ::SendInput(1, &input, sizeof(::INPUT));
}

void Mouse::scroll_down()
{
    ::INPUT input{ 0 };
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    input.mi.mouseData = static_cast<decltype(input.mi.mouseData)>(-WHEEL_DELTA); // negative scroll down
    ::SendInput(1, &input, sizeof(::INPUT));
}
