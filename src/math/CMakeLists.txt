cmake_minimum_required(VERSION 3.14)

target_sources(${LIBRARY_MATH}
  PUBLIC
    Common.hpp

  PRIVATE
)

target_sources(${UNITTEST_MATH}
  PRIVATE
    Common.test.cpp
)
