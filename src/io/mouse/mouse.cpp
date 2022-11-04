#include "pch.hpp"
#include "io/mouse/mouse.hpp"


using namespace virtware;

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
    ::SendInput(1, &input, sizeof(INPUT));
}