#include "Common.hpp"

#include <unordered_set>

#include <gtest/gtest.h>

using namespace ::testing;

namespace UnitTest
{
  TEST(Math, Sign)
  {
    ASSERT_EQ(Math::Sign(0), 0);
    ASSERT_EQ(Math::Sign(-1), -1);
    ASSERT_EQ(Math::Sign(1), 1);
    ASSERT_EQ(Math::Sign(-10), -1);
    ASSERT_EQ(Math::Sign(10), 1);

    ASSERT_DOUBLE_EQ(Math::Sign(0.0), 0.0);
    ASSERT_DOUBLE_EQ(Math::Sign(-1.0), -1.0);
    ASSERT_DOUBLE_EQ(Math::Sign(1.0), 1.0);
    ASSERT_DOUBLE_EQ(Math::Sign(-10.0), -1.0);
    ASSERT_DOUBLE_EQ(Math::Sign(10.0), 1.0);
  }

  TEST(Math, FloatCompare)
  {
    ASSERT_TRUE(Math::FloatCompare(0.5f, 0.5f + std::numeric_limits<float>::epsilon()));
    ASSERT_TRUE(Math::FloatCompare(0.5f, 0.25f, 0.25f));
    ASSERT_TRUE(Math::FloatCompare(0.5f, 0.75f, 0.25f));
  }

  TEST(Math, IsPowerOfTwo)
  {
    const std::unordered_set<std::uint32_t> powerOfTwoList = {1u << 0u,
                                                              1u << 1u,
                                                              1u << 2u,
                                                              1u << 3u,
                                                              1u << 4u,
                                                              1u << 5u,
                                                              1u << 6u,
                                                              1u << 7u,
                                                              1u << 8u,
                                                              1u << 9u,
                                                              1u << 10u,
                                                              1u << 11u,
                                                              1u << 12u,
                                                              1u << 13u,
                                                              1u << 14u,
                                                              1u << 15u};

    for(std::uint32_t i = 0u; i <= std::numeric_limits<std::uint16_t>::max(); i++)
    {
      const bool actual   = Math::IsPowerOfTwo(i);
      const bool expected = powerOfTwoList.find(i) != powerOfTwoList.cend();
      ASSERT_EQ(actual, expected);
    }
  }

  TEST(Math, NumericLength)
  {
    ASSERT_EQ(Math::NumericLength(0), 1u);

    ASSERT_EQ(Math::NumericLength(1), 1u);
    ASSERT_EQ(Math::NumericLength(10), 2u);
    ASSERT_EQ(Math::NumericLength(100), 3u);
    ASSERT_EQ(Math::NumericLength(1000), 4u);

    ASSERT_EQ(Math::NumericLength(-1), 1u);
    ASSERT_EQ(Math::NumericLength(-10), 2u);
    ASSERT_EQ(Math::NumericLength(-100), 3u);
    ASSERT_EQ(Math::NumericLength(-1000), 4u);

    ASSERT_EQ(Math::NumericLength(0.0), 1u);

    ASSERT_EQ(Math::NumericLength(1.5), 2u);
    ASSERT_EQ(Math::NumericLength(0.15), 3u);
    ASSERT_EQ(Math::NumericLength(0.015), 4u);

    ASSERT_EQ(Math::NumericLength(-1.5), 2u);
    ASSERT_EQ(Math::NumericLength(-0.15), 3u);
    ASSERT_EQ(Math::NumericLength(-0.015), 4u);
  }

  TEST(Math, Distance)
  {
    ASSERT_EQ(Math::Distance(5, 10), 5);
    ASSERT_EQ(Math::Distance(10, 5), 5);

    ASSERT_EQ(Math::Distance(-5, -10), 5);
    ASSERT_EQ(Math::Distance(-10, -5), 5);

    ASSERT_EQ(Math::Distance(5, -10), 15);
    ASSERT_EQ(Math::Distance(10, -5), 15);

    ASSERT_EQ(Math::Distance(-5, 10), 15);
    ASSERT_EQ(Math::Distance(-10, 5), 15);
  }

  TEST(Math, Reverse)
  {
    ASSERT_DOUBLE_EQ(Math::Reverse(25.0, 0.0, 100.0), 75.0);
    ASSERT_DOUBLE_EQ(Math::Reverse(75.0, 0.0, 100.0), 25.0);

    ASSERT_DOUBLE_EQ(Math::Reverse(-70.0, -100.0, -50.0), -80.0);
    ASSERT_DOUBLE_EQ(Math::Reverse(-80.0, -100.0, -50.0), -70.0);

    ASSERT_DOUBLE_EQ(Math::Reverse(50.0, -100.0, 100.0), -50.0);
    ASSERT_DOUBLE_EQ(Math::Reverse(-50.0, -100.0, 100.0), 50.0);
  }

  TEST(Math, Midpoint)
  {
    ASSERT_EQ(Math::Midpoint(0, 100), 50);
    ASSERT_EQ(Math::Midpoint(100, 0), 50);
    ASSERT_EQ(Math::Midpoint(-100, 100), 0);
    ASSERT_EQ(Math::Midpoint(100, -100), 0);
    ASSERT_EQ(Math::Midpoint(10, 80), 45);
    ASSERT_EQ(Math::Midpoint(80, 10), 45);
    ASSERT_EQ(Math::Midpoint(-10, -80), -45);
    ASSERT_EQ(Math::Midpoint(-80, -10), -45);

    ASSERT_DOUBLE_EQ(Math::Midpoint(0.0, 1.0), 0.5);
    ASSERT_DOUBLE_EQ(Math::Midpoint(1.0, 0.0), 0.5);
    ASSERT_DOUBLE_EQ(Math::Midpoint(-1.0, 1.0), 0.0);
    ASSERT_DOUBLE_EQ(Math::Midpoint(1.0, -1.0), 0.0);
    ASSERT_DOUBLE_EQ(Math::Midpoint(0.1, 0.8), 0.45);
    ASSERT_DOUBLE_EQ(Math::Midpoint(0.8, 0.1), 0.45);
    ASSERT_DOUBLE_EQ(Math::Midpoint(-0.1, -0.8), -0.45);
    ASSERT_DOUBLE_EQ(Math::Midpoint(-0.8, -0.1), -0.45);
  }

  TEST(Math, Clamp)
  {
    ASSERT_DOUBLE_EQ(Math::Clamp(1.0, 0.0, 100.0), 1.0);
    ASSERT_DOUBLE_EQ(Math::Clamp(-1.0, 0.0, 100.0), 0.0);

    ASSERT_DOUBLE_EQ(Math::Clamp(99.0, 0.0, 100.0), 99.0);
    ASSERT_DOUBLE_EQ(Math::Clamp(101.0, 0.0, 100.0), 100.0);

    ASSERT_DOUBLE_EQ(Math::Clamp(-99.0, -100.0, 100.0), -99.0);
    ASSERT_DOUBLE_EQ(Math::Clamp(-101.0, -100.0, 100.0), -100.0);
  }

  TEST(Math, Normalize)
  {
    ASSERT_DOUBLE_EQ(Math::Normalize(50.0, 0.0, 100.0, 0.0, 1.0), 0.5);
    ASSERT_DOUBLE_EQ(Math::Normalize(0.5, 0.0, 1.0, 0.0, 100.0), 50.0);

    ASSERT_DOUBLE_EQ(Math::Normalize(0.0, -100.0, 100.0, 0.0, 1.0), 0.5);
    ASSERT_DOUBLE_EQ(Math::Normalize(0.5, 0.0, 1.0, -100.0, 100.0), 0.0);

    ASSERT_DOUBLE_EQ(Math::Normalize(50.0, 0.0, 100.0, -1.0, 1.0), 0.0);
    ASSERT_DOUBLE_EQ(Math::Normalize(0.0, -1.0, 1.0, 0.0, 100.0), 50.0);

    ASSERT_DOUBLE_EQ(Math::Normalize(0.0, -100.0, 100.0, -1.0, 1.0), 0.0);
    ASSERT_DOUBLE_EQ(Math::Normalize(0.0, -1.0, 1.0, -100.0, 100.0), 0.0);
  }

  TEST(Math, Lerp)
  {
    ASSERT_DOUBLE_EQ(Math::Lerp(0.0, 1.0, 0.0), 0.0);
    ASSERT_DOUBLE_EQ(Math::Lerp(0.0, 1.0, 0.5), 0.5);
    ASSERT_DOUBLE_EQ(Math::Lerp(0.0, 1.0, 1.0), 1.0);

    ASSERT_EQ(Math::Lerp(0, 100, 0.0), 0);
    ASSERT_EQ(Math::Lerp(0, 100, 0.5), 50);
    ASSERT_EQ(Math::Lerp(0, 100, 1.0), 100);

    ASSERT_DOUBLE_EQ(Math::Lerp(1.0, 0.0, 0.0), 1.0);
    ASSERT_DOUBLE_EQ(Math::Lerp(1.0, 0.0, 0.5), 0.5);
    ASSERT_DOUBLE_EQ(Math::Lerp(1.0, 0.0, 1.0), 0.0);

    ASSERT_EQ(Math::Lerp(100, 0, 0.0), 100);
    ASSERT_EQ(Math::Lerp(100, 0, 0.5), 50);
    ASSERT_EQ(Math::Lerp(100, 0, 1.0), 0);
  }

  TEST(Math, IsPrime)
  {
    const std::unordered_set<std::uint32_t> primeNumbers = {2u,  3u,  5u,  7u,  11u, 13u, 17u, 19u, 23u, 29u, 31u, 37u, 41u,
                                                            43u, 47u, 53u, 59u, 61u, 67u, 71u, 73u, 79u, 83u, 89u, 97u};

    for(std::uint32_t i = 0u; i <= 100u; i++)
    {
      const bool actual   = Math::IsPrime(i);
      const bool expected = primeNumbers.find(i) != primeNumbers.cend();
      ASSERT_EQ(actual, expected);
    }
  }

  TEST(Math, IsPerfect)
  {
    const std::unordered_set<std::uint32_t> perfectNumbers = {6u, 28u, 496u, 8128u};

    for(std::uint32_t i = 0u; i <= 10000u; i++)
    {
      const bool actual   = Math::IsPerfect(i);
      const bool expected = perfectNumbers.find(i) != perfectNumbers.cend();
      ASSERT_EQ(actual, expected);
    }
  }
} // namespace UnitTest
