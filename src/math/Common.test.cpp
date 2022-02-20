#include <gtest/gtest.h>
#include "Common.hpp"

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

    ASSERT_EQ(Math::Sign(0.0), 0.0);
    ASSERT_EQ(Math::Sign(-1.0), -1.0);
    ASSERT_EQ(Math::Sign(1.0), 1.0);
    ASSERT_EQ(Math::Sign(-10.0), -1.0);
    ASSERT_EQ(Math::Sign(10.0), 1.0);
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
    ASSERT_EQ(Math::Reverse(25.0, 0.0, 100.0), 75.0);
    ASSERT_EQ(Math::Reverse(75.0, 0.0, 100.0), 25.0);

    ASSERT_EQ(Math::Reverse(-70.0, -100.0, -50.0), -80.0);
    ASSERT_EQ(Math::Reverse(-80.0, -100.0, -50.0), -70.0);

    ASSERT_EQ(Math::Reverse(50.0, -100.0, 100.0), -50.0);
    ASSERT_EQ(Math::Reverse(-50.0, -100.0, 100.0), 50.0);
  }

  TEST(Math, Clamp)
  {
    ASSERT_EQ(Math::Clamp(1.0, 0.0, 100.0), 1.0);
    ASSERT_EQ(Math::Clamp(-1.0, 0.0, 100.0), 0.0);

    ASSERT_EQ(Math::Clamp(99.0, 0.0, 100.0), 99.0);
    ASSERT_EQ(Math::Clamp(101.0, 0.0, 100.0), 100.0);

    ASSERT_EQ(Math::Clamp(-99.0, -100.0, 100.0), -99.0);
    ASSERT_EQ(Math::Clamp(-101.0, -100.0, 100.0), -100.0);
  }

  TEST(Math, Normalize)
  {
    ASSERT_EQ(Math::Normalize(50.0, 0.0, 100.0, 0.0, 1.0), 0.5);
    ASSERT_EQ(Math::Normalize(0.5, 0.0, 1.0, 0.0, 100.0), 50.0);

    ASSERT_EQ(Math::Normalize(0.0, -100.0, 100.0, 0.0, 1.0), 0.5);
    ASSERT_EQ(Math::Normalize(0.5, 0.0, 1.0, -100.0, 100.0), 0.0);

    ASSERT_EQ(Math::Normalize(50.0, 0.0, 100.0, -1.0, 1.0), 0.0);
    ASSERT_EQ(Math::Normalize(0.0, -1.0, 1.0, 0.0, 100.0), 50.0);

    ASSERT_EQ(Math::Normalize(0.0, -100.0, 100.0, -1.0, 1.0), 0.0);
    ASSERT_EQ(Math::Normalize(0.0, -1.0, 1.0, -100.0, 100.0), 0.0);
  }
} // namespace UnitTest
