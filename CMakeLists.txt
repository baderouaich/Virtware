cmake_minimum_required(VERSION 3.3)

# Project
project(Virtware VERSION 0.0.1 DESCRIPTION "Record/Play Virtual Sequence of Hardware Events" LANGUAGES C CXX)

# Sources & Headers
set(HEADERS
  include/core/core.hpp
  include/events/event.hpp
  include/events/mouse/mouse_move.hpp
  include/events/mouse/mouse_press.hpp
  include/events/mouse/mouse_release.hpp
  include/events/mouse/mouse_click.hpp
  include/events/mouse/mouse_scroll.hpp
  include/events/mouse/mouse_button.hpp
  include/events/key/key_press.hpp
  include/events/key/key_release.hpp
  include/events/key/key_click.hpp
  include/events/time/wait.hpp
  include/routine/routine.hpp
  include/executor/executor.hpp
  include/recorder/recorder.hpp
  include/io/key/key.hpp
  include/io/mouse/mouse.hpp
  include/types/vec.hpp
  include/timer/timer.hpp
  include/utils/convert_utils.hpp
  include/gui/main_form.hpp
)
set(SOURCES
  src/events/event.cpp
  src/events/mouse/mouse_move.cpp
  src/events/mouse/mouse_press.cpp
  src/events/mouse/mouse_release.cpp
  src/events/mouse/mouse_click.cpp
  src/events/mouse/mouse_scroll.cpp
  src/events/key/key_press.cpp
  src/events/key/key_release.cpp
  src/events/key/key_click.cpp
  src/events/time/wait.cpp
  src/routine/routine.cpp
  src/executor/executor.cpp
  src/recorder/recorder.cpp
  src/io/key/key.cpp
  src/io/mouse/mouse.cpp
  src/gui/main_form.cpp
)

# Filters
# Create the source groups for source tree with root at CMAKE_CURRENT_SOURCE_DIR.
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCES} ${HEADERS})
#source_group(include FILES ${HEADERS})
#source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Definitions
add_definitions(-DVIRTWARE_VERSION="${PROJECT_VERSION}")

# XTD
find_package(xtd REQUIRED)
add_sources(${SOURCES} ${HEADERS})
include_directories(${CMAKE_SOURCE_DIR}/include)
message(STATUS "Virtware sources: ${SOURCES}")
target_type(GUI_APPLICATION)

# Warnings as errors (helps maintaining strict C++ guidelines)
target_compile_options(${PROJECT_NAME} PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)

# PCH
target_precompile_headers(${PROJECT_NAME} PRIVATE ${HEADERS})

# Install
install_component()

# Tests
#add_projects(tests)
