cmake_minimum_required(VERSION 3.3)

# Solution
project(virtware)
find_package(xtd REQUIRED)
add_projects(
  virtware
)

# Install
install_package()
add_projects(virtware_script)
