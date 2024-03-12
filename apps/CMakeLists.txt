set(TARGET rb_tree)

add_executable(${TARGET} rb_tree.cpp)

target_compile_options(${TARGET} PUBLIC -Wall -Werror -O2)

target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/inc)
