cmake_minimum_required(VERSION 3.3)

# Solution
project(virtware)
find_package(xtd REQUIRED)
add_projects(
  virtware
  gui
)

# Install
install_package()

