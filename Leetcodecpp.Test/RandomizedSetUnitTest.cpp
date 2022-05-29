#include "pch.h"

#include "../Leetcodecpp/RandomizedSet.cpp"
#include "../Leetcodecpp/RandomizedSet.h"

TEST(RandomizedSetTest, OperationTest) {
  RandomizedSet randomizedSet;
  EXPECT_TRUE(randomizedSet.insert(1));
  EXPECT_FALSE(randomizedSet.remove(2));
  EXPECT_TRUE(randomizedSet.insert(2));
  int random1 = randomizedSet.getRandom();
  EXPECT_TRUE(random1 == 1 || random1 == 2);
  EXPECT_TRUE(randomizedSet.remove(1));
  EXPECT_FALSE(randomizedSet.insert(2));
  EXPECT_EQ(2, randomizedSet.getRandom());
}