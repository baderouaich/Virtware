#include "core/core.hpp"
#include "recorder/recorder.hpp"
#include "io/key/key.hpp"
#include "events/mouse/mouse_move.hpp"
#include "events/time/wait.hpp"
#include "events/key/key_press.hpp"
#include "core/core.hpp"
#include "io/mouse/mouse.hpp"
#include <xtd/diagnostics/debug.h>
#include <map>
#include <string>
using namespace Virtware;

Recorder::Recorder()
: m_is_recording(false) 
{
    
}
Recorder::~Recorder()
{
    this->stop();
}

void Recorder::start() 
{
    if(m_is_recording) return;
    
    m_recording_thread.reset(new std::thread(&Recorder::record_loop, this));
}

void Recorder::stop()
{
    if (not m_is_recording) return;

    m_is_recording = false;
    if(m_recording_thread && m_recording_thread->joinable())
    {
        m_recording_thread->join();
    }
}

void Recorder::record_loop()
{
    static struct Timer
    {
        void start()
        {
            begin = std::chrono::system_clock::now();
        }

        std::chrono::milliseconds restart()
        {
            const auto now = std::chrono::system_clock::now();
            const auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
            start();
            return diff;
        }

        std::chrono::system_clock::time_point begin;
    } timer;
    timer.start();

    m_is_recording = true;
    while(m_is_recording)
    {
        static std::chrono::system_clock::time_point last_event_time = std::chrono::system_clock::now(); // Duration between events, its also an event.
        //std::chrono::system_clock::time_point current_event_time;
        
        bool key_event_occured = handle_key_events();
        bool mouse_event_occured = handle_mouse_events();

        // Time event, duration between two events
        if (key_event_occured or mouse_event_occured)
        {
            auto time = timer.restart();
            m_events.push_back(std::make_shared<WaitEvent>(time));
        }
  
        /*
        
            current_event_time = std::chrono::system_clock::now();
            
            auto wait_event = current_event_time - last_event_time;
            if(auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(wait_event);
                ms.count() > 50)
                m_events.push_back(std::make_shared<WaitEvent>(ms, "ms"));
            last_event_time = current_event_time;

                */
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

bool Recorder::handle_key_events()
{
    bool event_occured = false;
    enum class KeyState : std::uint8_t 
    {
        Dormant, // Key is in idle state, never pressed pressed or released yet
        Pressed, // Key is pressed, used also to detect key released if key state was pressed and not in this frame
    };
    static std::map<std::uint16_t, KeyState> keyboard_state;
    static std::once_flag of;
    std::call_once(of, [&] 
    {
        for (const auto& [keycode, keyname] : Key::KEYBOARD)
        {
            keyboard_state[keycode] = KeyState::Dormant;
        }
    });
    for(const auto& [keycode, keyname] : Key::KEYBOARD)
    {
#pragma region handle key pressed event
        if(Key::is_key_pressed(keycode))
        {
            // was key already pressed ?
            if (keyboard_state[keycode] == KeyState::Pressed)
            {
                // do nothing
                xtd::diagnostics::debug::write_line("Key {} was already pressed, ignoring", keyname);
                event_occured = false;
            }
            else // if (keyboard_state[keycode] == KeyState::Dormant)
            { // otherwise if it was dormant then pressed, its a press event.
                m_events.push_back(std::make_shared<KeyPressEvent>(keycode));
                keyboard_state[keycode] = KeyState::Pressed;
                xtd::diagnostics::debug::write_line("Key {} pressed", keyname);
                event_occured = true;

            }
        }
#pragma endregion 
#pragma region handle key released event
        else // if it is not pressed now, lets see if it was pressed previously so we can mark it as released
        {
            if (keyboard_state[keycode] == KeyState::Pressed)
            {
                // if key was pressed, now its released and we mark it as dormant
                m_events.push_back(std::make_shared<KeyReleaseEvent>(keycode));
                keyboard_state[keycode] = KeyState::Dormant;
                xtd::diagnostics::debug::write_line("Key {} released", keyname);
                event_occured = true;
            }
        }
#pragma endregion
    }  
    return event_occured;
}

bool Recorder::handle_mouse_events()
{
    bool event_occured = false;

    // Cursor
    static vec2i last_mouse_pos{ -1, -1 };
    const vec2i current_mouse_pos = Mouse::get_position();
    if (current_mouse_pos != last_mouse_pos) 
    {
        m_events.push_back(std::make_shared<MouseMoveEvent>(current_mouse_pos));
        last_mouse_pos = current_mouse_pos;
        event_occured = true;
    }

    // Buttons
    

    // Scroll (wheel)
   /* ::WPARAM wparam;
    GET_WHEEL_DELTA_WPARAM(wparam);
    if(wparam.)*/

    return event_occured;
}

const std::atomic<bool>& Recorder::is_recording() const noexcept
{
    return m_is_recording;
}

const std::list<std::shared_ptr<Event>>& Recorder::get_events() const noexcept
{
    return m_events;
}
