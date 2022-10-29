cmake_minimum_required(VERSION 3.3)

# Project
project(virtware)
find_package(xtd REQUIRED)
add_sources(
  src/main_form.hpp
  src/main_form.cpp
  src/new_routine_form.hpp
  src/new_routine_form.cpp
)
target_type(GUI_APPLICATION)

# Install
install_component()
