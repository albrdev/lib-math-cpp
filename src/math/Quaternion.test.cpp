#include "Quaternion.hpp"

#include <gtest/gtest.h>

using namespace ::testing;

namespace UnitTest
{
  TEST(Quaternion, Constructor)
  {
    {
      Quaternion<double> quaternion;
      ASSERT_FALSE(quaternion);
    }

    {
      Quaternion<double> quaternion = Quaternion<double>::Invalid;
      ASSERT_FALSE(quaternion);
    }

    {
      Quaternion<double> quaternion = Quaternion<double>::Identity;
      ASSERT_TRUE(quaternion);
    }
  }
} // namespace UnitTest
