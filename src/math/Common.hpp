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
    constexpr T zero = static_cast<T>(0);
    return static_cast<T>((value > zero) - (value < zero));
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

  template<class T, std::enable_if_t<std::is_unsigned_v<T>, bool> = true>
  constexpr bool IsPowerOfTwo(T value)
  {
    constexpr T zero = static_cast<T>(0u);
    constexpr T one  = static_cast<T>(1u);

    return value > zero ? ((value & (value - one)) == zero) : false;
  }

  template<class T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
  std::size_t NumericLength(T value, int base = 10)
  {
    constexpr T zero = static_cast<T>(0);

    std::size_t result = 0u;
    if(value == zero)
    {
      return 1u;
    }

    while(value != zero)
    {
      value /= base;
      result++;
    }

    return result;
  }

  template<class T, std::enable_if_t<std::is_floating_point_v<T>, bool> = true>
  std::size_t NumericLength(T value)
  {
    constexpr T zero = static_cast<T>(0);
    constexpr T ten  = static_cast<T>(10);

    std::size_t result = 0u;
    if(std::trunc(value) == zero)
    {
      result++;
    }

    T tmpValue = value - std::trunc(value);
    while(tmpValue != std::trunc(tmpValue))
    {
      tmpValue *= ten;
      result++;
    }

    while(std::trunc(value) != zero)
    {
      value /= ten;
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
    constexpr T two = static_cast<T>(2);
    return min + ((max - min) / two);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Clamp(T value, T min, T max)
  {
    return std::max(min, std::min(value, max));
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Clamp01(T value)
  {
    constexpr T zero = static_cast<T>(0);
    constexpr T one  = static_cast<T>(1);
    return Clamp(value, zero, one);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Clamp11(T value)
  {
    constexpr T negone = static_cast<T>(-1);
    constexpr T one    = static_cast<T>(1);
    return Clamp(value, negone, one);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Normalize(T value, T inMin, T inMax, T outMin, T outMax)
  {
    return (((value - inMin) * (outMax - outMin)) / (inMax - inMin)) + outMin;
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Normalize01(T value, T min, T max)
  {
    constexpr T zero = static_cast<T>(0);
    constexpr T one  = static_cast<T>(1);
    return Normalize(value, min, max, zero, one);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Denormalize01(T value, T min, T max)
  {
    constexpr T zero = static_cast<T>(0);
    constexpr T one  = static_cast<T>(1);
    return Normalize(value, zero, one, min, max);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Normalize11(T value, T min, T max)
  {
    constexpr T negone = static_cast<T>(-1);
    constexpr T one    = static_cast<T>(1);
    return Normalize(value, min, max, negone, one);
  }

  template<class T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
  constexpr T Denormalize11(T value, T min, T max)
  {
    constexpr T negone = static_cast<T>(-1);
    constexpr T one    = static_cast<T>(1);
    return Normalize(value, negone, one, min, max);
  }

  template<class T, class U, std::enable_if_t<std::is_arithmetic_v<T> && std::is_floating_point_v<U>, bool> = true>
  T Lerp(T min, T max, U fraction)
  {
    constexpr U one    = static_cast<U>(1);
    return static_cast<T>((static_cast<U>(min) * (one - fraction)) + (static_cast<U>(max) * fraction));
  }

  template<class T, std::enable_if_t<std::is_unsigned_v<T>, bool> = true>
  bool IsPrime(T value)
  {
    constexpr T two   = static_cast<T>(2);
    constexpr T three = static_cast<T>(3);
    constexpr T zero  = static_cast<T>(0);

    if(value == two)
    {
      return true;
    }
    else if((value < two) || ((value % two) == zero))
    {
      return false;
    }

    const T max = static_cast<T>(std::sqrt(value));
    for(T i = three; i <= max; i += two)
    {
      if(value % i == zero)
      {
        return false;
      }
    }

    return true;
  }

  template<class T, std::enable_if_t<std::is_unsigned_v<T>, bool> = true>
  bool IsPerfect(T value)
  {
    constexpr T zero  = static_cast<T>(0);
    constexpr T two   = static_cast<T>(2);
    constexpr T three = static_cast<T>(3);
    constexpr T six   = static_cast<T>(6);

    if(((value % two) != zero) && value < six)
    {
      return false;
    }

    const T max = value / two;
    T sum       = three;
    for(T i = three; i <= max; i++)
    {
      if((value % i) == zero)
      {
        sum += i;
      }
    }

    return sum == value;
  }
} // namespace Math

#endif // __MATH__COMMON_HPP__
