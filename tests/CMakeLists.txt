cmake_minimum_required(VERSION 3.3)

# Project
project(tests)

set(SOURCES
  src/mouse_events_tests.cpp
)
source_group(src FILES ${SOURCES})
message(STATUS "Tests files: ${SOURCES}")
find_package(xtd REQUIRED)
add_sources(${SOURCES})
target_type(TEST_APPLICATION)

#target_link_libraries(${PROJECT_NAME}
# virtware
#)
#target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})
# Install
install_component()
