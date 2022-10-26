#include "form1.h"

using namespace xtd::forms;
using namespace virtware;

form1::form1() {
  text("form1");
  client_size({800, 450});
}

void form1::main() {
  application::run(form1());
}
