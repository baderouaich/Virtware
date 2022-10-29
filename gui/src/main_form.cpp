#include "main_form.hpp"
#include "new_routine_form.hpp"
using namespace xtd::forms;
using namespace virtware;

main_form::main_form() : m_new_routine_btn(new button) {
  text("Virtware");
  client_size({800, 450});

  m_new_routine_btn->parent(*this)
	  .text("New Routine")
	  .location({ 0,0 })
	  .size({ 170,50 })
	  .font(xtd::drawing::font(xtd::drawing::system_fonts::default_font(), 15.0f))
	  .click += [this] {
			  std::unique_ptr<new_routine_form> nrf(new new_routine_form);
			  nrf->show_dialog(*this);
		 };
}
main_form::~main_form() {

}
void main_form::main() {
	const std::unique_ptr<main_form> main_form_ptr(new main_form());
	application::run(*main_form_ptr);
}
