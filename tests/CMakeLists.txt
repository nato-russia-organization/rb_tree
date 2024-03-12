set(TARGET memory_tests)

add_executable(${TARGET} memory_tests.cpp)
target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/inc)
target_link_libraries(${TARGET} PRIVATE Gtest::gtest_main)
