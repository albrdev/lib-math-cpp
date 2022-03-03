cmake_minimum_required(VERSION 3.14)

#set(CMAKE_C_STANDARD 98)
#set(CMAKE_C_STANDARD_REQUIRED True)
#set(CMAKE_C_COMPILER "gcc")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_COMPILER "g++")

set(LIBRARY_MATH math)
set(UNITTEST_MATH math-test)

project(lib-math VERSION 1.0.0)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wpedantic")
elseif(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()

add_library(${LIBRARY_MATH} STATIC)
set_target_properties(${LIBRARY_MATH} PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(${LIBRARY_MATH} PUBLIC src)

add_library(${UNITTEST_MATH} STATIC)
target_include_directories(${UNITTEST_MATH} PUBLIC src)
target_link_libraries(${UNITTEST_MATH} gtest_main gmock_main)

# Traverse directories
add_subdirectory(src)

set(PROJECT_TEST unit_testsuite-math)
set(EXECUTABLE_TEST unit_testsuite-math)

project(${PROJECT_TEST})

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

get_target_property(SOURCES ${UNITTEST_MATH} SOURCES)
add_executable(${EXECUTABLE_TEST} main-test.cpp ${SOURCES})
target_link_libraries(${EXECUTABLE_TEST} ${LIBRARY_MATH} ${UNITTEST_MATH})
enable_testing()
add_test(NAME ${PROJECT_TEST} COMMAND ${EXECUTABLE_TEST})
