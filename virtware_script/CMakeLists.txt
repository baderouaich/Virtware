cmake_minimum_required(VERSION 3.3)

# Project
project(virtware_script)
find_package(xtd REQUIRED)
add_sources(
  src/program.h
  src/program.cpp
)
target_type(CONSOLE_APPLICATION)

# Install
install_component()
