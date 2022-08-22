cmake_minimum_required(VERSION 3.20)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt
    ON
    CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# adder example
add_subdirectory(adder)
list(APPEND EXTRA_LIBS adder)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/adder")

enable_testing()

# adder example test
add_executable(adder_test "${PROJECT_SOURCE_DIR}/test/adder_test.cpp")
target_link_libraries(adder_test GTest::gtest_main ${EXTRA_LIBS})
target_include_directories(adder_test PUBLIC ${EXTRA_INCLUDES})

include(GoogleTest)
gtest_discover_tests(adder_test)
