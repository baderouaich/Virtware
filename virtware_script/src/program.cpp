#include "program.h"
#include <xtd/console.h>

using namespace std;
using namespace xtd;
using namespace vhelang;

void program::main(const vector<ustring>& args) {
  console::write_line("Hello, World!");
}
