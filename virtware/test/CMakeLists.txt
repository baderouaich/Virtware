cmake_minimum_required(VERSION 3.3)

# Project
project(test)
find_package(xtd REQUIRED)
add_sources(
  src/mouse_events_tests.cpp
)
target_type(TEST_APPLICATION)

target_link_libraries(test
	virtware
)
# Install
install_component()
