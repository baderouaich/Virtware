#pragma once
#include "core/core.hpp"
#include <chrono>

namespace Virtware
{
    struct Timer
    {
        void start()
        {
            begin = std::chrono::high_resolution_clock::now(); // using a steady clock for nanoseconds
        }


        template<typename Duration>
        Duration restart()
        {
            // to restart timer at the end of scope
            //struct RAII_restarter { RAII_restarter(Timer& self) : _self(self) {} ~RAII_restarter() { _self.start(); } Timer& _self; } restarter(*this);
            const auto diff = std::chrono::high_resolution_clock::now() - begin;
            start();
            return std::chrono::duration_cast<Duration>(diff);
        } 

        std::chrono::high_resolution_clock::time_point begin;
    };
}