#include <xtd/xtd.tunit>
#include "executor/executor.hpp"
#include "events/mouse/mouse_click.hpp"
#include "events/mouse/mouse_move.hpp"
#include "events/mouse/mouse_press.hpp"
#include "events/mouse/mouse_release.hpp"
#include "events/mouse/mouse_scroll.hpp"
using namespace xtd::tunit;
using namespace virtware;

namespace test 
{
  class test_class_(mouse_move_event_tests) 
  {
  public:
    void test_method_(from_string) 
    {
        std::string str = "mouse move 100 50";
        MouseMoveEvent e1;
        e1.from_string(str);
        assert::are_equal(e1.get_x(), 100);
        assert::are_equal(e1.get_y(), 50);
        assert::are_equal(str, e1.to_string());

        assert::does_not_throw([] {
            MouseMoveEvent e("mouse move 0 0");
            });
        assert::throws<std::logic_error>([] {
            MouseMoveEvent e("mouse MOVE 254 14");
        });
        assert::throws<std::logic_error>([] {
            MouseMoveEvent e("mouse move");
            });
        assert::throws<std::logic_error>([] {
            MouseMoveEvent e("MOUSE MOVE 100 434");
            });
    }

    void test_method_(to_string)
    {
        MouseMoveEvent e(1024, 500);
        assert::are_equal(e.to_string(), "mouse move 1024 500");
        MouseMoveEvent e1(e.to_string());
        assert::are_equal(e1.to_string(), e.to_string());
    }
  };
}
