#ifndef __VECTOR3_HPP__
#define __VECTOR3_HPP__

#include <cmath>
#include <type_traits>
#include "Vector2.hpp"

template<class T, class = typename std::enable_if<std::is_arithmetic<T>::value && std::is_signed<T>::value>::type>
class Vector3
{
  public:
  static constexpr Vector3<T> Zero = Vector3<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
  static constexpr Vector3<T> One  = Vector3<T>(static_cast<T>(1), static_cast<T>(1), static_cast<T>(1));

  static constexpr Vector3<T> Left    = Vector3<T>(static_cast<T>(-1), static_cast<T>(0), static_cast<T>(0));
  static constexpr Vector3<T> Right   = Vector3<T>(static_cast<T>(1), static_cast<T>(0), static_cast<T>(0));
  static constexpr Vector3<T> Up      = Vector3<T>(static_cast<T>(0), static_cast<T>(1), static_cast<T>(0));
  static constexpr Vector3<T> Down    = Vector3<T>(static_cast<T>(0), static_cast<T>(-1), static_cast<T>(0));
  static constexpr Vector3<T> Forward = Vector3<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));
  static constexpr Vector3<T> Back    = Vector3<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(-1));

  static T Distance(const Vector3<T>& a, const Vector3<T>& b) { return static_cast<T>(std::sqrt((a - b).GetMagnitude())); }

  static T DotProduct(const Vector3<T>& a, const Vector3<T>& b) { return (a.m_X * b.m_X) + (a.m_Y * b.m_Y) + (a.m_Z * b.m_Z); }

  static Vector3 CrossProduct(const Vector3<T>& a, const Vector3<T>& b)
  {
    return Vector3((a.m_Y * b.m_Z) - (a.m_Z * b.m_Y), (a.m_Z * b.m_X) - (a.m_X * b.m_Z), (a.m_X * b.m_Y) - (a.m_Y * b.m_X));
  }

  bool operator==(const Vector3<T>& rhs) { return (m_X == rhs.m_X) && (m_Y == rhs.m_Y) && (m_Z == rhs.m_Z); }

  bool operator!=(const Vector3<T>& rhs) { return (m_X != rhs.m_X) || (m_Y != rhs.m_Y) || (m_Z != rhs.m_Z); }

  Vector3<T> operator+() const { return Vector3<T>(+m_X, +m_Y, +m_Z); }

  Vector3<T> operator-() const { return Vector3<T>(-m_X, -m_Y, -m_Z); }

  Vector3<T> operator+(const Vector3& rhs) const { return Vector3<T>(m_X + rhs.m_X, m_Y + rhs.m_Y, m_Z + rhs.m_Z); }

  Vector3<T> operator-(const Vector3& rhs) const { return Vector3<T>(m_X - rhs.m_X, m_Y - rhs.m_Y, m_Z - rhs.m_Z); }

  Vector3<T> operator*(const Vector3& rhs) const { return Vector3<T>(m_X * rhs.m_X, m_Y * rhs.m_Y, m_Z * rhs.m_Z); }

  Vector3<T> operator/(const Vector3& rhs) const { return Vector3<T>(m_X / rhs.m_X, m_Y / rhs.m_Y, m_Z / rhs.m_Z); }

  Vector3<T> operator+(T rhs) const { return Vector3<T>(m_X + rhs, m_Y + rhs, m_Z + rhs); }

  Vector3<T> operator-(T rhs) const { return Vector3<T>(m_X - rhs, m_Y - rhs, m_Z - rhs); }

  Vector3<T> operator*(T rhs) const { return Vector3<T>(m_X * rhs, m_Y * rhs, m_Z * rhs); }

  Vector3<T> operator/(T rhs) const { return Vector3<T>(m_X / rhs, m_Y / rhs, m_Z / rhs); }

  Vector3<T>& operator+=(const Vector3& rhs)
  {
    m_X += rhs.m_X;
    m_Y += rhs.m_Y;
    m_Z += rhs.m_Z;

    return *this;
  }

  Vector3<T>& operator-=(const Vector3& rhs)
  {
    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;
    m_Z -= rhs.m_Z;

    return *this;
  }

  Vector3<T>& operator*=(const Vector3& rhs)
  {
    m_X *= rhs.m_X;
    m_Y *= rhs.m_Y;
    m_Z *= rhs.m_Z;

    return *this;
  }

  Vector3<T>& operator/=(const Vector3& rhs)
  {
    m_X /= rhs.m_X;
    m_Y /= rhs.m_Y;
    m_Z /= rhs.m_Z;

    return *this;
  }

  Vector3<T>& operator+=(T rhs)
  {
    m_X += rhs;
    m_Y += rhs;
    m_Z += rhs;

    return *this;
  }

  Vector3<T>& operator-=(T rhs)
  {
    m_X -= rhs;
    m_Y -= rhs;
    m_Z -= rhs;

    return *this;
  }

  Vector3<T>& operator*=(T rhs)
  {
    m_X *= rhs;
    m_Y *= rhs;
    m_Z *= rhs;

    return *this;
  }

  Vector3<T>& operator/=(T rhs)
  {
    m_X /= rhs;
    m_Y /= rhs;
    m_Z /= rhs;

    return *this;
  }

  operator Vector2<T>() const { return Vector2<T>(m_X, m_Y); }

  T GetSquareMagnitude() const { return (m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z); }

  T GetMagnitude() const { return static_cast<T>(std::sqrt(GetSquareMagnitude())); }

  Vector3<T> ToNormalized() const
  {
    T magnitude = GetMagnitude();
    return (magnitude != static_cast<T>(0)) ? ((*this) / magnitude) : (*this);
  }

  T GetX() const { return m_X; }
  T GetY() const { return m_Y; }
  T GetZ() const { return m_Z; }

  constexpr Vector3(T x, T y, T z)
      : m_X(x)
      , m_Y(y)
      , m_Z(z)
  {}

  constexpr Vector3(const Vector2<T>& other)
      : m_X(other.m_X)
      , m_Y(other.m_Y)
      , m_Z(static_cast<T>(0))
  {}

  ~Vector3() = default;

  constexpr Vector3()
      : m_X(static_cast<T>(0))
      , m_Y(static_cast<T>(0))
      , m_Z(static_cast<T>(0))
  {}

  constexpr Vector3(const Vector3<T>& other)
      : m_X(other.m_X)
      , m_Y(other.m_Y)
      , m_Z(other.m_Z)
  {}

  Vector3(Vector3<T>&& other)
      : m_X(std::move(other.m_X))
      , m_Y(std::move(other.m_Y))
      , m_Z(std::move(other.m_Z))
  {}

  constexpr Vector3& operator=(const Vector3<T>& other)
  {
    m_X = other.m_X;
    m_Y = other.m_Y;
    m_Z = other.m_Z;
  }

  Vector3& operator=(Vector3<T>&& other)
  {
    m_X = std::move(other.m_X);
    m_Y = std::move(other.m_Y);
    m_Z = std::move(other.m_Z);
  }

  private:
  T m_X;
  T m_Y;
  T m_Z;
};

#endif // __VECTOR3_HPP__
