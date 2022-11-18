#pragma once

#include "events/event.hpp"
#include "timer/timer.hpp"
#include <thread>
#include <list>
#include <atomic>

namespace Virtware
{
    /*
    *   Hardware Events Recorder (Mouse, Keyboard, Joystick...)
    */
    class  Recorder 
    {
    public:
        Recorder();
        ~Recorder();

    public:
        void start();
        void stop();

     

       /* void restart() {
            stop();
            m_events.clear();
            start();
        }*/
    public:
        const std::atomic<bool>& is_recording() const noexcept;
        const std::list<std::shared_ptr<Event>>& get_events() const noexcept;

    private:
        void recording_loop();
        bool handle_key_events();
        bool handle_mouse_events();

    private:
        std::atomic<bool> m_is_recording;
        std::unique_ptr<std::thread> m_recording_thread;
        std::list<std::shared_ptr<Event>> m_events;
        std::unique_ptr<Timer> m_timer;
    }; 
} 
