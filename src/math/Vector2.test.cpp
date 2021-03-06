#include "Vector2.hpp"

#include <gtest/gtest.h>

using namespace ::testing;

namespace UnitTest
{
  TEST(Vector2, Constructor)
  {
    {
      Vector2<double> vector2;
      ASSERT_EQ(vector2.GetX(), 0.0);
      ASSERT_EQ(vector2.GetY(), 0.0);
    }
  }
} // namespace UnitTest
