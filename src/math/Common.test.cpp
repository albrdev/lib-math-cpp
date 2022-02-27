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

  TEST(Math, IsPowerOfTwo)
  {
    std::uint32_t powerOfTwoList[std::numeric_limits<std::uint16_t>::digits];
    for(std::uint16_t i = 0u; i < std::numeric_limits<std::uint16_t>::digits; i++)
    {
      powerOfTwoList[i] = 1u << i;
    }

    std::size_t index = 0u;
    for(std::uint32_t i = 0u; i <= std::numeric_limits<uint16_t>::max(); i++)
    {
      if(i == powerOfTwoList[index])
      {
        ASSERT_TRUE(Math::IsPowerOfTwo(i));
        index++;
      }
      else
      {
        ASSERT_FALSE(Math::IsPowerOfTwo(i));
      }
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
