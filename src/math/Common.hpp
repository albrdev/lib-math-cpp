#ifndef __MATH__COMMON_HPP__
#define __MATH__COMMON_HPP__

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <type_traits>

namespace Math
{
  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Sign(T value)
  {
    constexpr T kZero = static_cast<T>(0);
    return static_cast<T>((value > kZero) - (value < kZero));
  }

  template<class T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
  bool Equals(T a, T b, T tolerance = static_cast<T>(0))
  {
    return (a > b ? (a - b) : (b - a)) <= tolerance;
  }

  template<class T, std::enable_if_t<std::is_floating_point_v<T>, bool> = true>
  bool Equals(T a, T b, T tolerance = std::numeric_limits<T>::epsilon())
  {
    return std::fabs(a - b) <= tolerance;
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Delta(T a, T b)
  {
    constexpr auto kMax = std::numeric_limits<T>::max();
    constexpr T kOne    = static_cast<T>(1);

    return (a < b) ? (((kMax - b) + a) + kOne) : (a - b);
  }

  template<class T, std::enable_if_t<std::is_unsigned_v<T>, bool> = true>
  constexpr bool IsPowerOfTwo(T value)
  {
    constexpr T kZero = static_cast<T>(0u);
    constexpr T kOne  = static_cast<T>(1u);

    return value > kZero ? ((value & (value - kOne)) == kZero) : false;
  }

  template<class T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
  std::size_t NumericLength(T value, int base = 10)
  {
    constexpr T kZero = static_cast<T>(0);

    std::size_t result = 0u;
    if(value == kZero)
    {
      return 1u;
    }

    while(value != kZero)
    {
      value /= base;
      result++;
    }

    return result;
  }

  template<class T, std::enable_if_t<std::is_floating_point_v<T>, bool> = true>
  std::size_t NumericLength(T value)
  {
    constexpr T kZero = static_cast<T>(0);
    constexpr T kTen  = static_cast<T>(10);

    std::size_t result = 0u;
    if(std::trunc(value) == kZero)
    {
      result++;
    }

    T tmpValue = value - std::trunc(value);
    while(tmpValue != std::trunc(tmpValue))
    {
      tmpValue *= kTen;
      result++;
    }

    while(std::trunc(value) != kZero)
    {
      value /= kTen;
      result++;
    }

    return result;
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Distance(T a, T b)
  {
    return static_cast<T>(::abs(a - b));
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Reverse(T value, T min, T max)
  {
    return (max + min) - value;
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Midpoint(T min, T max)
  {
    constexpr T kTwo = static_cast<T>(2);
    return min + ((max - min) / kTwo);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Clamp(T value, T min, T max)
  {
    return std::max(min, std::min(value, max));
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Clamp01(T value)
  {
    constexpr T kZero = static_cast<T>(0);
    constexpr T kOne  = static_cast<T>(1);
    return Clamp(value, kZero, kOne);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Clamp11(T value)
  {
    constexpr T kNegOne = static_cast<T>(-1);
    constexpr T kOne    = static_cast<T>(1);
    return Clamp(value, kNegOne, kOne);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Normalize(T value, T inMin, T inMax, T outMin, T outMax)
  {
    return (((value - inMin) * (outMax - outMin)) / (inMax - inMin)) + outMin;
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Normalize01(T value, T min, T max)
  {
    constexpr T kZero = static_cast<T>(0);
    constexpr T kOne  = static_cast<T>(1);
    return Normalize(value, min, max, kZero, kOne);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Denormalize01(T value, T min, T max)
  {
    constexpr T kZero = static_cast<T>(0);
    constexpr T kOne  = static_cast<T>(1);
    return Normalize(value, kZero, kOne, min, max);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Normalize11(T value, T min, T max)
  {
    constexpr T kNegOne = static_cast<T>(-1);
    constexpr T kOne    = static_cast<T>(1);
    return Normalize(value, min, max, kNegOne, kOne);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Denormalize11(T value, T min, T max)
  {
    constexpr T kNegOne = static_cast<T>(-1);
    constexpr T kOne    = static_cast<T>(1);
    return Normalize(value, kNegOne, kOne, min, max);
  }

  template<class T, class U, std::enable_if_t<std::is_arithmetic_v<T> && std::is_floating_point_v<U>, bool> = true>
  T Lerp(T min, T max, U fraction)
  {
    constexpr U kOne = static_cast<U>(1);
    return static_cast<T>((static_cast<U>(min) * (kOne - fraction)) + (static_cast<U>(max) * fraction));
  }

  template<class T, std::enable_if_t<std::is_unsigned_v<T>, bool> = true>
  bool IsPrime(T value)
  {
    constexpr T kTwo   = static_cast<T>(2);
    constexpr T kThree = static_cast<T>(3);
    constexpr T kZero  = static_cast<T>(0);

    if(value == kTwo)
    {
      return true;
    }
    else if((value < kTwo) || ((value % kTwo) == kZero))
    {
      return false;
    }

    const T max = static_cast<T>(std::sqrt(value));
    for(T i = kThree; i <= max; i += kTwo)
    {
      if(value % i == kZero)
      {
        return false;
      }
    }

    return true;
  }

  template<class T, std::enable_if_t<std::is_unsigned_v<T>, bool> = true>
  bool IsPerfect(T value)
  {
    constexpr T kZero  = static_cast<T>(0);
    constexpr T kTwo   = static_cast<T>(2);
    constexpr T kThree = static_cast<T>(3);

    if((value % kTwo) != kZero)
    {
      return false;
    }

    const T max = value / kTwo;
    T sum       = kThree;
    for(T i = kThree; i <= max; i++)
    {
      if((value % i) == kZero)
      {
        sum += i;
      }
    }

    return sum == value;
  }
} // namespace Math

#endif // __MATH__COMMON_HPP__
