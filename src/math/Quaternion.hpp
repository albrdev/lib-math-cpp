#ifndef __MATH__QUATERNION_HPP__
#define __MATH__QUATERNION_HPP__

#include <cmath>
#include <type_traits>

template<class T, class = typename std::enable_if<std::is_arithmetic<T>::value && std::is_signed<T>::value>::type>
class Quaternion
{
  public:
  static constexpr Quaternion<T> Invalid  = Quaternion<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(0));
  static constexpr Quaternion<T> Identity = Quaternion<T>(static_cast<T>(0), static_cast<T>(0), static_cast<T>(0), static_cast<T>(1));

  operator bool() const { return (*this) != Quaternion<T>::Invalid; }

  bool operator==(const Quaternion<T>& rhs) const { return (m_W == rhs.m_W) && (m_X == rhs.m_X) && (m_Y == rhs.m_Y) && (m_Z == rhs.m_Z); }

  bool operator!=(const Quaternion<T>& rhs) const { return (m_W != rhs.m_W) || (m_X != rhs.m_X) || (m_Y != rhs.m_Y) || (m_Z != rhs.m_Z); }

  Quaternion<T> operator+(const Quaternion& rhs) const { return Quaternion<T>(m_W + rhs.m_W, m_X + rhs.m_X, m_Y + rhs.m_Y, m_Z + rhs.m_Z); }

  Quaternion<T> operator-(const Quaternion& rhs) const { return Quaternion<T>(m_W - rhs.m_W, m_X - rhs.m_X, m_Y - rhs.m_Y, m_Z - rhs.m_Z); }

  Quaternion<T> operator*(const Quaternion& rhs) const
  {
    return Quaternion<T>(m_W * rhs.m_W - m_X * rhs.m_X - m_Y * rhs.m_Y - m_Z * rhs.m_Z,
                         m_W * rhs.m_X + m_X * rhs.m_W + m_Y * rhs.m_Z - m_Z * rhs.m_Y,
                         m_W * rhs.m_Y - m_X * rhs.m_Z + m_Y * rhs.m_W + m_Z * rhs.m_X,
                         m_W * rhs.m_Z + m_X * rhs.m_Y - m_Y * rhs.m_X + m_Z * rhs.m_W);
  }

  Quaternion<T> operator/(const Quaternion& rhs) const { return ((*this) * rhs.Inverse()); }

  Quaternion<T>& operator+=(const Quaternion& rhs)
  {
    m_X += rhs.m_X;
    m_Y += rhs.m_Y;
    m_Z += rhs.m_Z;
    m_W += rhs.m_W;

    return *this;
  }

  Quaternion<T>& operator-=(const Quaternion& rhs)
  {
    m_X -= rhs.m_X;
    m_Y -= rhs.m_Y;
    m_Z -= rhs.m_Z;
    m_W -= rhs.m_W;

    return *this;
  }

  Quaternion<T>& operator*=(const Quaternion& rhs)
  {
    m_W = (m_W * rhs.m_W) - (m_X * rhs.m_X) - (m_Y * rhs.m_Y) - (m_Z * rhs.m_Z);
    m_X = (m_W * rhs.m_X) + (m_X * rhs.m_W) + (m_Y * rhs.m_Z) - (m_Z * rhs.m_Y);
    m_Y = (m_W * rhs.m_Y) - (m_X * rhs.m_Z) + (m_Y * rhs.m_W) + (m_Z * rhs.m_X);
    m_Z = (m_W * rhs.m_Z) + (m_X * rhs.m_Y) - (m_Y * rhs.m_X) + (m_Z * rhs.m_W);

    return *this;
  }

  Quaternion<T>& operator/=(const Quaternion& rhs)
  {
    (*this) *= rhs.Inverse();

    return *this;
  }

  Quaternion<T> Scale(T value) { return Quaternion(m_W * value, m_X * value, m_Y * value, m_Z * value); }

  T GetSquareMagnitude() const { return (m_W * m_W) + (m_X * m_X) + (m_Y * m_Y) + (m_Z * m_Z); }

  T GetMagnitude() const { return static_cast<T>(std::sqrt(GetSquareMagnitude())); }

  Quaternion<T> Inverse() const { return ToConjugate().Scale(static_cast<T>(1) / GetSquareMagnitude()); }

  Quaternion<T> ToNormalized() const
  {
    T magnitude = GetMagnitude();
    return (magnitude != static_cast<T>(0)) ? ((*this) / magnitude) : (*this);
  }

  Quaternion<T> ToConjugate() const { return Quaternion<T>(m_W, -m_X, -m_Y, -m_Z); }

  T GetW() const { return m_W; }
  T GetX() const { return m_X; }
  T GetY() const { return m_Y; }
  T GetZ() const { return m_Z; }

  constexpr Quaternion(const T x, const T y, const T z, const T w)
      : m_X(x)
      , m_Y(y)
      , m_Z(z)
      , m_W(w)
  {}

  ~Quaternion() = default;

  constexpr Quaternion()
      : m_X(static_cast<T>(0))
      , m_Y(static_cast<T>(0))
      , m_Z(static_cast<T>(0))
      , m_W(static_cast<T>(0))
  {}

  constexpr Quaternion(const Quaternion<T>& other)
      : m_X(other.m_X)
      , m_Y(other.m_Y)
      , m_Z(other.m_Z)
      , m_W(other.m_W)
  {}

  Quaternion(Quaternion<T>&& other)
      : m_X(std::move(other.m_X))
      , m_Y(std::move(other.m_Y))
      , m_Z(std::move(other.m_Z))
      , m_W(std::move(other.m_W))
  {}

  constexpr Quaternion& operator=(const Quaternion<T>& other)
  {
    m_X = other.m_X;
    m_Y = other.m_Y;
    m_Z = other.m_Z;
    m_W = other.m_W;
  }

  Quaternion& operator=(Quaternion<T>&& other)
  {
    m_X = std::move(other.m_X);
    m_Y = std::move(other.m_Y);
    m_Z = std::move(other.m_Z);
    m_W = std::move(other.m_W);
  }

  private:
  T m_X;
  T m_Y;
  T m_Z;
  T m_W;
};

#endif // __MATH__QUATERNION_HPP__
