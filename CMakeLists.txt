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

# lt1512::nogp
add_subdirectory(lt1512)
list(APPEND EXTRA_LIBS nogp)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/lt1512")

# Testing
enable_testing()
include(GoogleTest)

# adder example test
add_executable(adder_test "${PROJECT_SOURCE_DIR}/test/adder_test.cpp")
target_link_libraries(adder_test GTest::gtest_main ${EXTRA_LIBS})
target_include_directories(adder_test PUBLIC ${EXTRA_INCLUDES})
gtest_discover_tests(adder_test)

# lt1512::nogp test
add_executable(nogp_test "${PROJECT_SOURCE_DIR}/test/nogp_test.cpp")
target_link_libraries(nogp_test GTest::gtest_main ${EXTRA_LIBS})
target_include_directories(nogp_test PUBLIC ${EXTRA_INCLUDES})
gtest_discover_tests(nogp_test)


