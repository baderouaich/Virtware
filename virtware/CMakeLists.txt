cmake_minimum_required(VERSION 3.3)

# Project
project(virtware VERSION 0.0.1 DESCRIPTION "Virtware Core" LANGUAGES C CXX)
set(INCLUDES
  include/events/event.hpp
  include/events/mouse/mouse_move.hpp
  include/events/mouse/mouse_press.hpp
  include/events/mouse/mouse_release.hpp
  include/events/mouse/mouse_click.hpp
  include/events/mouse/mouse_scroll.hpp
  include/routine/routine.hpp
  include/executor/executor.hpp
  include/export.hpp
)
set(SOURCES
  src/events/event.cpp
  src/events/mouse/mouse_move.cpp
  src/events/mouse/mouse_press.cpp
  src/events/mouse/mouse_release.cpp
  src/events/mouse/mouse_click.cpp
  src/events/mouse/mouse_scroll.cpp
  src/routine/routine.cpp
  src/executor/executor.cpp
)
source_group(include FILES ${INCLUDES})
source_group(src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_definitions(-DVIRTWARE_EXPORT)

# Application properties
add_library(${PROJECT_NAME} SHARED ${INCLUDES} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)

# Install
install(DIRECTORY include/. DESTINATION include/virtware)
file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/virtwareConfig.cmake
  "include(CMakeFindDependencyMacro)\n"
  "include(\"\${CMAKE_CURRENT_LIST_DIR}/${PROJECT_NAME}.cmake\")\n"
  "\n"
  "get_filename_component(VIRTWARE_INCLUDE_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../include\" ABSOLUTE)\n"
  "get_filename_component(VIRTWARE_LIBRARIES_DIRS \"\${CMAKE_CURRENT_LIST_DIR}/../lib\" ABSOLUTE)\n"
  "\n"
  "set(VIRTWARE_LIBRARIES virtware)\n"
  "set(VIRTWARE_FOUND TRUE)\n"
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/virtwareConfig.cmake DESTINATION cmake)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
install(FILES $<TARGET_FILE_DIR:${PROJECT_NAME}>/${PROJECT_NAME}.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME} DESTINATION lib)
install(EXPORT ${PROJECT_NAME} DESTINATION cmake)


# Tests
add_subdirectory(test)