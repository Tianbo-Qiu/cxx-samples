#include "nogp.h"
#include <gtest/gtest.h>

TEST(lt1512, nogp) {
  EXPECT_EQ(nogp({1, 2, 3, 1, 1, 3}), 4);
  EXPECT_EQ(nogp({1, 1, 1, 1}), 6);
  EXPECT_EQ(nogp({1, 2, 3}), 0);
}

TEST(lt1512, nogp2) {
  EXPECT_EQ(nogp2({1, 2, 3, 1, 1, 3}), 4);
  EXPECT_EQ(nogp2({1, 1, 1, 1}), 6);
  EXPECT_EQ(nogp2({1, 2, 3}), 0);
}
