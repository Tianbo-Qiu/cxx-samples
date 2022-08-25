#include "vec.h"
#include <gtest/gtest.h>

TEST(vec1, constructor_size) {
  vec1 v(12);
  EXPECT_EQ(v.size(), 12);
}

TEST(vec1, constructor_initializer_list) {
  vec1 v1 = {1, 2, 3};
  vec1 v2{1, 2, 3};
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v2.size(), 3);
}

TEST(vec1, copy_constructor) {
  vec1 v1 = {1, 2, 3};
  vec1 v2 = v1;
  vec1 v3{v2};
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_EQ(v3.size(), 3);
}

TEST(vec1, assignment) {
  vec1 v1 = {1, 2, 3};
  vec1 v2 = {4, 5};
  v1 = v1;
  v2 = v1;
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1[0], 1);
  EXPECT_EQ(v1[1], 2);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[1], 2);
}

TEST(vec1, accessors_get) {
  vec1 v1 = {1, 2, 3};
  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v1[0], 1);
  EXPECT_EQ(v1[1], 2);
  EXPECT_EQ(v1[2], 3);
}

TEST(vec1, accessors_set) {
  vec1 v1 = {1, 2, 3};
  EXPECT_EQ(v1.size(), 3);
  v1[1] = 11;
  EXPECT_EQ(v1[0], 1);
  EXPECT_EQ(v1[1], 11);
  EXPECT_EQ(v1[2], 3);
}
