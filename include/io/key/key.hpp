#pragma once
#include <cstdint>
#include <unordered_map>

namespace virtware
{
    class Key final
    {
    public:
        static void press(const std::uint16_t keycode) noexcept;
        static void release(const std::uint16_t keycode) noexcept;
        static void click(const std::uint16_t keycode) noexcept;

    public:
        /**
         * @brief Keyboard map of keycode, string representation
         * @note this map was taken from xtd::console_key
         */
        inline static const std::unordered_map<std::uint16_t, std::string> KEYBOARD =
        {
            // @brief The BACKSPACE key.
            {8, "backspace"},
            /// @brief The TAB key.
            {9, "tab"},
            /// @brief The CLEAR key.
            {12, "clear"},
            /// @brief The ENTER key.
            {13, "enter"},
            /// @brief The PAUSE key.
            {19, "pause"},
            /// @brief The CapsLock key.
            {20, "caps_lock"},
            /// @brief The ESC (ESCAPE) key.
            {27, "escape"},
            /// @brief The SPACEBAR key.
            {32, "spacebar"},
            /// @brief The PAGE UP key.
            {33, "page_up"},
            /// @brief The PAGE DOWN key.
            {34, "page_down"},
            /// @brief The END key.
            {35, "end"},
            /// @brief The HOME key.
            {36, "home"},
            /// @brief The LEFT ARROW key.
            {37, "left_arrow"},
            /// @brief The UP ARROW key.
            {38, "up_arrow"},
            /// @brief The RIGHT ARROW key.
            {39, "right_arrow"},
            /// @brief The DOWN ARROW key.
            {40, "down_arrow"},
            /// @brief The SELECT key.
            {41, "select"},
            /// @brief The PRINT key.
            {42, "print"},
            /// @brief The EXECUTE key.
            {43, "execute"},
            /// @brief The PRINT SCREEN key.
            {44, "print_screen"},
            /// @brief The INS (INSERT) key.
            {45, "insert"},
            /// @brief The DEL (DELETE) key.
            {46, "del"},
            /// @brief The HELP key.
            {47, "help"},
            /// @brief The 0 key.
            {48, "d0"},
            /// @brief The 1 key.
            {49, "d1"},
            /// @brief The 2 key.
            {50, "d2"},
            /// @brief The 3 key.
            {51, "d3"},
            /// @brief The 4 key.
            {52, "d4"},
            /// @brief The 5 key.
            {53, "d5"},
            /// @brief The 6 key.
            {54, "d6"},
            /// @brief The 7 key.
            {55, "d7"},
            /// @brief The 8 key.
            {56, "d8"},
            /// @brief The 9 key.
            {57, "d9"},
            /// @brief The A key.
            {65, "a"},
            /// @brief The B key.
            {66, "b"},
            /// @brief The C key.
            {67, "c"},
            /// @brief The D key.
            {68, "d"},
            /// @brief The E key.
            {69, "e"},
            /// @brief The F key.
            {70, "f"},
            /// @brief The G key.
            {71, "g"},
            /// @brief The H key.
            {72, "h"},
            /// @brief The I key.
            {73, "i"},
            /// @brief The J key.
            {74, "j"},
            /// @brief The K key.
            {75, "k"},
            /// @brief The L key.
            {76, "l"},
            /// @brief The M key.
            {77, "m"},
            /// @brief The N key.
            {78, "n"},
            /// @brief The O key.
            {79, "o"},
            /// @brief The P key.
            {80, "p"},
            /// @brief The Q key.
            {81, "q"},
            /// @brief The R key.
            {82, "r"},
            /// @brief The S key.
            {83, "s"},
            /// @brief The T key.
            {84, "t"},
            /// @brief The U key.
            {85, "u"},
            /// @brief The V key.
            {86, "v"},
            /// @brief The W key.
            {87, "w"},
            /// @brief The X key.
            {88, "x"},
            /// @brief The Y key.
            {89, "y"},
            /// @brief The Z key.
            {90, "z"},
            /// @brief The left Windows logo key (Microsoft Natural Keyboard).
            {91, "left_windows"},
            /// @brief The right Windows logo key (Microsoft Natural Keyboard).
            {92, "right_windows"},
            /// @brief The Application key (Microsoft Natural Keyboard).
            {93, "applications"},
            /// @brief The Computer Sleep key.
            {95, "sleep"},
            /// @brief The 0 key on the numeric keypad.
            {96, "num_pad_0"},
            /// @brief The 1 key on the numeric keypad.
            {97, "num_pad_1"},
            /// @brief The 2 key on the numeric keypad.
            {98, "num_pad_2"},
            /// @brief The 3 key on the numeric keypad.
            {99, "num_pad_3"},
            /// @brief The 4 key on the numeric keypad.
            {100, "num_pad_4"},
            /// @brief The 5 key on the numeric keypad.
            {101, "num_pad_5"},
            /// @brief The 6 key on the numeric keypad.
            {102, "num_pad_6"},
            /// @brief The 7 key on the numeric keypad.
            {103, "num_pad_7"},
            /// @brief The 8 key on the numeric keypad.
            {104, "num_pad_8"},
            /// @brief The 9 key on the numeric keypad.
            {105, "num_pad_9"},
            /// @brief The Multiply key.
            {106, "multiply"},
            /// @brief The Add key.
            {107, "add"},
            /// @brief The Separator key.
            {108, "separator"},
            /// @brief The Subtract key.
            {109, "subtract"},
            /// @brief The Decimal key.
            {110, "decimal"},
            /// @brief The Divide key.
            {111, "divide"},
            /// @brief The F1 key.
            {112, "f1"},
            /// @brief The F2 key.
            {113, "f2"},
            /// @brief The F3 key.
            {114, "f3"},
            /// @brief The F4 key.
            {115, "f4"},
            /// @brief The F5 key.
            {116, "f5"},
            /// @brief The F6 key.
            {117, "f6"},
            /// @brief The F7 key.
            {118, "f7"},
            /// @brief The F8 key.
            {119, "f8"},
            /// @brief The F9 key.
            {120, "f9"},
            /// @brief The F10 key.
            {121, "f10"},
            /// @brief The F11 key.
            {122, "f11"},
            /// @brief The F12 key.
            {123, "f12"},
            /// @brief The F13 key.
            {124, "f13"},
            /// @brief The F14 key.
            {125, "f14"},
            /// @brief The F15 key.
            {126, "f15"},
            /// @brief The F16 key.
            {127, "f16"},
            /// @brief The F17 key.
            {128, "f17"},
            /// @brief The F18 key.
            {129, "f18"},
            /// @brief The F19 key.
            {130, "f19"},
            /// @brief The F20 key.
            {131, "f20"},
            /// @brief The F21 key.
            {132, "f21"},
            /// @brief The F22 key.
            {133, "f22"},
            /// @brief The F23 key.
            {134, "f23"},
            /// @brief The F24 key.
            {135, "f24"},
            /// @brief The Browser Back key (Windows 2000 or later).
            {166, "browser_back"},
            /// @brief The Browser Forward key (Windows 2000 or later).
            {167, "browser_forward"},
            /// @brief The Browser Refresh key (Windows 2000 or later).
            {168, "browser_refresh"},
            /// @brief The Browser Stop key (Windows 2000 or later).
            {169, "browser_stop"},
            /// @brief The Browser Search key (Windows 2000 or later).
            {170, "browser_search"},
            /// @brief The Browser Favorite key (Windows 2000 or later).
            {171, "browser_favorites"},
            /// @brief The Browser Home key (Windows 2000 or later).
            {172, "browser_home"},
            /// @brief The Volume Mute key (Microsoft Natural Keyboard, Windows 2000 or later).
            {173, "volume_mute"},
            /// @brief The Volume Down key (Microsoft Natural Keyboard, Windows 2000 or later).
            {174, "volume_down"},
            /// @brief The Volume Up key (Microsoft Natural Keyboard, Windows 2000 or later).
            {175, "volume_up"},
            /// @brief The Media Next Track key (Microsoft Natural Keyboard, Windows 2000 or later).
            {176, "media_next"},
            /// @brief The Media Previous Track key (Microsoft Natural Keyboard, Windows 2000 or later).
            {177, "media_previous"},
            /// @brief The Media Stop key (Microsoft Natural Keyboard, Windows 2000 or later).
            {178, "media_stop"},
            /// @brief The Media Play/Pause key (Microsoft Natural Keyboard, Windows 2000 or later).
            {179, "media_play"},
            /// @brief The Start Mail key (Microsoft Natural Keyboard, Windows 2000 or later).
            {180, "launch_mail"},
            /// @brief The Select Media key (Microsoft Natural Keyboard, Windows 2000 or later).
            {181, "launch_media_select"},
            /// @brief The Start Application 1 key (Microsoft Natural Keyboard, Windows 2000 or later).
            {182, "launch_app1"},
            /// @brief The Start Application 2 key (Microsoft Natural Keyboard, Windows 2000 or later).
            {183, "launch_app2"},
            /// @brief The OEM 1 key (OEM specific).
            {186, "oem1"},
            /// @brief The OEM Plus key on any country/region keyboard (Windows 2000 or later).
            {187, "oem_plus"},
            /// @brief The OEM Comma key on any country/region keyboard (Windows 2000 or later).
            {188, "oem_comma"},
            /// @brief The OEM Minus key on any country/region keyboard (Windows 2000 or later).
            {189, "oem_minus"},
            /// @brief The OEM Period key on any country/region keyboard (Windows 2000 or later).
            {190, "oem_period"},
            /// @brief The OEM 2 key (OEM specific).
            {191, "oem2"},
            /// @brief The OEM " key (OEM specific).
            {192, "oem3"},
            /// @brief The OEM 4 key (OEM specific).
            {219, "oem4"},
            /// @brief The OEM 5 key (OEM specific).
            {220, "oem5"},
            /// @brief The OEM 6 key (OEM specific).
            {221, "oem6"},
            /// @brief The OEM 7 key (OEM specific).
            {222, "oem7"},
            /// @brief The OEM 8 key (OEM specific).
            {223, "oem8"},
            /// @brief The OEM 102 key (OEM specific).
            {226, "oem102"},
            /// @brief The IME PROCESS key.
            {229, "process"},
            /// @brief The PACKET key (used to pass Unicode characters with keystrokes).
            {231, "packet"},
            /// @brief The ATTN key.
            {246, "attention"},
            /// @brief The CRSEL (CURSOR SELECT) key.
            {247, "cr_sel"},
            /// @brief The EXSEL (EXTEND SELECTION) key.
            {248, "ex_sel"},
            /// @brief The ERASE EOF key.
            {249, "erase_end_of_file"},
            /// @brief The Play key.
            {250, "play"},
            /// @brief The ZOOM key.
            {251, "zoom"},
            /// @brief A constant reserved for future use.
            {252, "no_name"},
            /// @brief The PA1 key.
            {253, "pa1"},
            /// @brief The CLEAR key (OEM specific).
            {254, "oem_clear"},
        };
    };
}