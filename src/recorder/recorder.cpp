#include "pch.hpp"
#include "recorder/recorder.hpp"
#include "io/key/key.hpp"
#include "events/mouse/mouse_move.hpp"
#include "events/time/wait.hpp"
#include "events/key/key_press.hpp"
#include "pch.hpp"
#include "io/mouse/mouse.hpp"
#include <xtd/diagnostics/debug.h>
#include <map>
#include <string>
using namespace virtware;

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
    m_is_recording = true;
    while(m_is_recording)
    {
        static std::chrono::system_clock::time_point last_event_time = std::chrono::system_clock::now(); // Duration between events, its also an event.
        std::chrono::system_clock::time_point current_event_time;
        
        // Check keyboard state 
        for(const auto& [keycode, keyname] : Key::KEYBOARD)
        {
            if(Key::is_key_pressed(keycode))
            {
                m_events.push_back(std::make_shared<KeyPressEvent>(keycode));
                xtd::diagnostics::debug::write_line("Key {} pressed", keyname);
            }
            else if(Key::is_key_released(keycode))
            {
                xtd::diagnostics::debug::write_line("Key {} released", keyname);
                /*std::shared_ptr<Event> event = std::make_shared<KeyReleaseEvent>(keycode); 
                xtd::diagnostics::debug::write_line("Key {} released", keyname);*/
            }
        }
        
        // Check mouse state
        static vec2i last_mouse_pos{ -1, -1 };
        vec2i mouse_pos = Mouse::get_position();
        if (mouse_pos != last_mouse_pos) 
        {
            current_event_time = std::chrono::system_clock::now();
            
            auto wait_event = current_event_time - last_event_time;
            if(auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(wait_event);
                ms.count() > 50)
                m_events.push_back(std::make_shared<WaitEvent>(ms, "ms"));
            m_events.push_back(std::make_shared<MouseMoveEvent>(mouse_pos));
            last_event_time = current_event_time;
            last_mouse_pos = mouse_pos;
        }

        // Check joystick state


        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

const std::atomic<bool>& Recorder::is_recording() const noexcept
{
    return m_is_recording;
}

const std::list<std::shared_ptr<Event>>& Recorder::get_events() const noexcept
{
    return m_events;
}
