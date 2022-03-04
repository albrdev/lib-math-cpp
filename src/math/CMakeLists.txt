cmake_minimum_required(VERSION 3.14)

target_sources(${LIBRARY_MATH}
  PUBLIC
  Common.hpp
  Quaternion.hpp
  Vector2.hpp
  Vector3.hpp

  PRIVATE
)

target_sources(${UNITTEST_MATH}
  PRIVATE
  Common.test.cpp
  Quaternion.test.cpp
  Vector2.test.cpp
  Vector3.test.cpp
)
