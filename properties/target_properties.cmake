target_default_namespace("Virtware")
target_icon(resources/Virtware)
target_name("Virtware")
target_startup("Virtware::main_form" ${CMAKE_SOURCE_DIR}/include/gui/main_form.hpp)
