cmake_minimum_required(VERSION 3.3)

# Project
project(virtware VERSION 0.0.1 DESCRIPTION "Virtware" LANGUAGES C CXX)
set(INCLUDES
  include/pch.hpp
  include/events/event.hpp
  include/events/mouse/mouse_move.hpp
  include/events/mouse/mouse_press.hpp
  include/events/mouse/mouse_release.hpp
  include/events/mouse/mouse_click.hpp
  include/events/mouse/mouse_scroll.hpp
  include/events/time/wait.hpp
  include/routine/routine.hpp
  include/executor/executor.hpp
  include/recorder/recorder.hpp
  include/io/key/key.hpp
  include/io/mouse/mouse.hpp
  include/types/vec.hpp
  include/gui/main_form.hpp
)
set(SOURCES
  src/pch.cpp
  src/events/event.cpp
  src/events/mouse/mouse_move.cpp
  src/events/mouse/mouse_press.cpp
  src/events/mouse/mouse_release.cpp
  src/events/mouse/mouse_click.cpp
  src/events/mouse/mouse_scroll.cpp
  src/events/time/wait.cpp
  src/routine/routine.cpp
  src/executor/executor.cpp
  src/recorder/recorder.cpp
  src/io/key/key.cpp
  src/io/mouse/mouse.cpp
  src/gui/main_form.cpp

)
# Filters
source_group(include FILES ${INCLUDES})
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Definitions
add_definitions(-DVIRTWARE_VERSION=${PROJECT_VERSION})

# XTD
find_package(xtd REQUIRED)
add_sources(${SOURCES} ${INCLUDES})
include_directories(${CMAKE_SOURCE_DIR}/include)
message(STATUS "Virtware sources: ${SOURCES}")
target_type(GUI_APPLICATION)

# PCH
target_precompile_headers(${PROJECT_NAME} PRIVATE include/pch.hpp)

# Install
install_component()

# Tests
#add_projects(tests)
