#include "pch.hpp"
#include <gui/main_form.hpp>
#include "io/mouse/mouse.hpp"
#include "events/mouse/mouse_move.hpp"
using namespace xtd::forms;
using namespace virtware;

main_form::main_form() :
	m_start_recording_btn(new button()),
	m_stop_recording_btn(new button()), 
	m_play_recording(new button()),
	m_events_lst(new list_box()),
	m_recorder(new Recorder())
{
  text("Virtware");
  client_size({800, 600});

  // todo image button icon (obs like play/pause/resume/stop)
  m_start_recording_btn->parent(*this)
	  .text("Start recording")
	  .location({ 0,0 })
	  .size({ 170,50 })
	  .font(xtd::drawing::font(xtd::drawing::system_fonts::default_font(), 15.0f))
	  .click += [this] {
		
			  if (not m_recorder->is_recording()) {
				  m_recorder->start();
			  }
		 };
  m_stop_recording_btn->parent(*this)
	  .text("Stop recording")
	  .location({ 0,60 })
	  .size({ 170,50 })
	  .font(xtd::drawing::font(xtd::drawing::system_fonts::default_font(), 15.0f))
	  .click += [this] {
			if (m_recorder->is_recording()) {
				m_recorder->stop();
				for (const std::shared_ptr<Event>& event : m_recorder->get_events()) {
					m_events_lst->items().push_back(event->to_string());
				}
			}
		};

  m_play_recording->parent(*this)
	  .text("Play")
	  .location({ 0, 120 })
	  .size({ 170,50 })
	  .font(xtd::drawing::font(xtd::drawing::system_fonts::default_font(), 15.0f))
	  .click += [this] {
			for (auto e : m_events_lst->items())
			{
				MouseMoveEvent event(e.to_string());
				Mouse::set_position({ event.get_x(), event.get_y() });
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
	  };
  m_events_lst->parent(*this)
	  .text("Stop recording")
	  .location({ 0,180 })
	  .size({ width()-50,350 });
}
main_form::~main_form() {

}
void main_form::main() {
	const std::unique_ptr<main_form> main_form_ptr(new main_form());
	application::run(*main_form_ptr);
}