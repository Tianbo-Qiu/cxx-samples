#include "adder.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(TestExample, TestAdder) { EXPECT_EQ(adder(1, 2, 3), 6); }
