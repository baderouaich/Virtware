#include "core/core.hpp"
#include <gui/main_form.hpp>
#include "io/mouse/mouse.hpp"
#include "events/mouse/mouse_move.hpp"
#include "executor/executor.hpp"
#include "routine/routine.hpp"
using namespace xtd::forms;
using namespace Virtware;

main_form::main_form() :
	m_start_recording_btn(new button()),
	m_stop_recording_btn(new button()), 
	m_play_recording(new button()),
	m_save_recording(new button()),
	m_load_recording(new button()),
	m_events_lst(new list_box()),
	m_recorder(new Recorder()),
	m_executor(new Executor())
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
	  .click += [this] 
      {
			std::shared_ptr<Routine> routine = std::make_shared<Routine>();
			for (auto &str : m_events_lst->items())
			{
				routine->add_event(str.to_string());
			}
			m_executor->execute(routine);
	  }; 


  m_save_recording->parent(*this)
	  .text("Save routine to file...")
	  .location({ 200, 120 })
	  .size({ 170,60 })
	  .font(xtd::drawing::font(xtd::drawing::system_fonts::default_font(), 15.0f))
	  .click += [this] 
      {
			std::shared_ptr<Routine> routine = std::make_shared<Routine>();
			for (auto &str : m_events_lst->items())
			{
				routine->add_event(str.to_string());
			}
			xtd::ustring filename;
			if (xtd::forms::save_file_box::show(filename,
				"Save routine to a file...",
		xtd::environment::get_folder_path(xtd::environment::special_folder::desktop),
				"*.vtw") == xtd::forms::dialog_result::ok)
			{
				routine->to_file((std::string)filename);
			}
	  };


  m_load_recording->parent(*this)
	  .text("Load routine from file...")
	  .location({ 380, 120 })
	  .size({ 170,60 })
	  .font(xtd::drawing::font(xtd::drawing::system_fonts::default_font(), 15.0f))
	  .click += [this]
  {
	  std::shared_ptr<Routine> routine = std::make_shared<Routine>();
	  xtd::ustring filename;
	  if (xtd::forms::open_file_box::show(filename,
		  "Select routine file to load...",
		  xtd::environment::get_folder_path(xtd::environment::special_folder::desktop),
		  "*.vtw") == xtd::forms::dialog_result::ok)
	  {
		  routine->from_file((std::string)filename);
	  }

	  for (const std::shared_ptr<Event>& event : routine->get_events())
	  {
		  m_events_lst->items().push_back(event->to_string());
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
