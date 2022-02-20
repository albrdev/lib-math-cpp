#ifndef __LIB_MATH__COMMON_HPP__
#define __LIB_MATH__COMMON_HPP__

#include <cmath>
#include <algorithm>

namespace Math
{
  template<class T>
  T Sign(T value)
  {
    constexpr T zero = static_cast<T>(0);
    return (value > zero) - (value < zero);
  }

  template<class T>
  T Distance(T a, T b)
  {
    return static_cast<T>(::abs(a - b));
  }

  template<class T>
  T Reverse(T value, T min, T max)
  {
    return (max + min) - value;
  }

  template<class T>
  T Origo(T value, T min, T max)
  {
    constexpr T two = static_cast<T>(2);
    return (min + max) / two;
  }

  template<class T>
  T Clamp(T value, T min, T max)
  {
    return std::max(min, std::min(value, max));
  }

  template<class T>
  T Clamp01(T value)
  {
    constexpr T zero = static_cast<T>(0);
    constexpr T one  = static_cast<T>(1);
    return Clamp(value, zero, one);
  }

  template<class T>
  T Clamp11(T value)
  {
    constexpr T negone = static_cast<T>(-1);
    constexpr T one    = static_cast<T>(1);
    return Clamp(value, negone, one);
  }

  template<class T>
  T Normalize(T value, T inMin, T inMax, T outMin, T outMax)
  {
    return (((value - inMin) * (outMax - outMin)) / (inMax - inMin)) + outMin;
  }

  template<class T>
  T Normalize01(T value, T min, T max)
  {
    constexpr T zero = static_cast<T>(0);
    constexpr T one  = static_cast<T>(1);
    return Normalize(value, min, max, zero, one);
  }

  template<class T>
  T Denormalize01(T value, T min, T max)
  {
    constexpr T zero = static_cast<T>(0);
    constexpr T one  = static_cast<T>(1);
    return Normalize(value, zero, one, min, max);
  }

  template<class T>
  T Normalize11(T value, T min, T max)
  {
    constexpr T negone = static_cast<T>(-1);
    constexpr T one    = static_cast<T>(1);
    return Normalize(value, min, max, negone, one);
  }

  template<class T>
  T Denormalize11(T value, T min, T max)
  {
    constexpr T negone = static_cast<T>(-1);
    constexpr T one    = static_cast<T>(1);
    return Normalize(value, negone, one, min, max);
  }
} // namespace Math

#endif // __LIB_MATH__COMMON_HPP__
