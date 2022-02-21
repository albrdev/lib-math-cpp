#include <gtest/gtest.h>
#include "Vector3.hpp"

using namespace ::testing;

namespace UnitTest
{
  TEST(Vector3, Constructor)
  {
    {
      Vector3<double> vector3;
      ASSERT_EQ(vector3.GetX(), 0.0);
      ASSERT_EQ(vector3.GetY(), 0.0);
      ASSERT_EQ(vector3.GetZ(), 0.0);
    }
  }
} // namespace UnitTest
