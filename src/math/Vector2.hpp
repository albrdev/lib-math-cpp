#ifndef __VECTOR2_HPP__
#define __VECTOR2_HPP__

#include <cmath>
#include <type_traits>

template<class T, class U>
class Vector3;

template<class T, class = typename std::enable_if<std::is_arithmetic<T>::value && std::is_signed<T>::value>::type>
class Vector2
{
  public:
  friend class Vector3<T, T>;

  static constexpr Vector2<T> Zero = Vector2<T>(static_cast<T>(0), static_cast<T>(0));
  static constexpr Vector2<T> One  = Vector2<T>(static_cast<T>(1), static_cast<T>(1));

  static constexpr Vector2<T> Left  = Vector2<T>(static_cast<T>(-1), static_cast<T>(0));
  static constexpr Vector2<T> Right = Vector2<T>(static_cast<T>(1), static_cast<T>(0));
  static constexpr Vector2<T> Up    = Vector2<T>(static_cast<T>(0), static_cast<T>(1));
  static constexpr Vector2<T> Down  = Vector2<T>(static_cast<T>(0), static_cast<T>(-1));

  static T Distance(const Vector2<T>& a, const Vector2<T>& b) { return static_cast<T>(std::sqrt((a - b).GetMagnitude())); }

  static T DotProduct(const Vector2<T>& a, const Vector2<T>& b) { return (a.m_X * b.m_X) + (a.m_Y * b.m_Y); }

  static T CrossProduct(const Vector2<T>& a, const Vector2<T>& b) { return (a.m_X * b.m_Y) - (a.m_Y * b.m_X); }

  static Vector2<T> PerpendicularCW(const Vector2<T>& value) { return Vector2<T>(value.m_Y, -value.m_X); }

  static Vector2<T> PerpendicularCCW(const Vector2<T>& value) { return Vector2<T>(-value.m_Y, value.m_X); }

  bool operator==(const Vector2<T>& rhs) { return (m_X == rhs.m_X) && (m_Y == rhs.m_Y); }

  bool operator!=(const Vector2<T>& rhs) { return (m_X != rhs.m_X) || (m_Y != rhs.m_Y); }

  Vector2<T> operator+() const { return Vector2<T>(+m_X, +m_Y); }

  Vector2<T> operator-() const { return Vector2<T>(-m_X, -m_Y); }

  Vector2<T> operator+(const Vector2& rhs) const { return Vector2<T>(m_X + rhs.m_X, m_Y + rhs.m_Y); }

  Vector2<T> operator-(const Vector2& rhs) const { return Vector2<T>(m_X - rhs.m_X, m_Y - rhs.m_Y); }

  Vector2<T> operator*(const Vector2& rhs) const { return Vector2<T>(m_X * rhs.m_X, m_Y * rhs.m_Y); }

  Vector2<T> operator/(const Vector2& rhs) const { return Vector2<T>(m_X / rhs.m_X, m_Y / rhs.m_Y); }

  Vector2<T> operator+(T rhs) const { return Vector2<T>(m_X + rhs, m_Y + rhs); }

  Vector2<T> operator-(T rhs) const { return Vector2<T>(m_X - rhs, m_Y - rhs); }

  Vector2<T> operator*(T rhs) const { return Vector2<T>(m_X * rhs, m_Y * rhs); }

  Vector2<T> operator/(T rhs) const { return Vector2<T>(m_X / rhs, m_Y / rhs); }

  Vector2<T>& operator+=(const Vector2& rhs)
  {
    m_X += rhs.m_X;
    m_Y += rhs.m_Y;

    return *this;
  }

  Vector2<T>& operator-=(const Vector2& rhs)
  {
    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;

    return *this;
  }

  Vector2<T>& operator*=(const Vector2& rhs)
  {
    m_X *= rhs.m_X;
    m_Y *= rhs.m_Y;

    return *this;
  }

  Vector2<T>& operator/=(const Vector2& rhs)
  {
    m_X /= rhs.m_X;
    m_Y /= rhs.m_Y;

    return *this;
  }

  Vector2<T>& operator+=(T rhs)
  {
    m_X += rhs;
    m_Y += rhs;

    return *this;
  }

  Vector2<T>& operator-=(T rhs)
  {
    m_X -= rhs;
    m_Y -= rhs;

    return *this;
  }

  Vector2<T>& operator*=(T rhs)
  {
    m_X *= rhs;
    m_Y *= rhs;

    return *this;
  }

  Vector2<T>& operator/=(T rhs)
  {
    m_X /= rhs;
    m_Y /= rhs;

    return *this;
  }

  T GetSquareMagnitude() const { return (m_X * m_X) + (m_Y * m_Y); }

  T GetMagnitude() const { return static_cast<T>(std::sqrt(GetSquareMagnitude())); }

  Vector2<T> ToNormalized() const
  {
    T magnitude = GetMagnitude();
    return (magnitude != static_cast<T>(0)) ? ((*this) / magnitude) : (*this);
  }

  T GetX() const { return m_X; }
  T GetY() const { return m_Y; }

  constexpr Vector2(T x, T y)
      : m_X(x)
      , m_Y(y)
  {}

  ~Vector2() = default;

  constexpr Vector2()
      : m_X(static_cast<T>(0))
      , m_Y(static_cast<T>(0))
  {}

  constexpr Vector2(const Vector2<T>& other)
      : m_X(other.m_X)
      , m_Y(other.m_Y)
  {}

  Vector2(Vector2<T>&& other)
      : m_X(std::move(other.m_X))
      , m_Y(std::move(other.m_Y))
  {}

  constexpr Vector2& operator=(const Vector2<T>& other)
  {
    m_X = other.m_X;
    m_Y = other.m_Y;
  }

  Vector2& operator=(Vector2<T>&& other)
  {
    m_X = std::move(other.m_X);
    m_Y = std::move(other.m_Y);
  }

  private:
  T m_X;
  T m_Y;
};

#endif // __VECTOR2_HPP__
