#include "pch.h"

#include "../Leetcodecpp/Solution.cpp"
#include "../Leetcodecpp/Solution.h"

#include <string>
#include <vector>

using namespace std;

TEST(SolutionTest, TwoSumTest) {
  vector<int> expected1 = {0, 1};
  vector<int> input1 = {2, 7, 11, 15};
  vector<int> actual1 = Solution::twoSum(input1, 9);
  EXPECT_EQ(expected1, actual1);

  vector<int> expected2 = {1, 2};
  vector<int> input2 = {3, 2, 4};
  vector<int> actual2 = Solution::twoSum(input2, 6);
  EXPECT_EQ(expected2, actual2);

  vector<int> expected3 = {0, 1};
  vector<int> input3 = {3, 3};
  vector<int> actual3 = Solution::twoSum(input3, 6);
  EXPECT_EQ(expected3, actual3);
}

TEST(SolutionTest, LengthOfLongestSubstring) {
  EXPECT_EQ(3, Solution::lengthOfLongestSubstring("abcabcbb"));
  EXPECT_EQ(1, Solution::lengthOfLongestSubstring("bbbbb"));
  EXPECT_EQ(3, Solution::lengthOfLongestSubstring("pwwkew"));
}

TEST(SolutionTest, LengthOfLongestSubstringTest) {
  EXPECT_EQ(3, Solution::lengthOfLongestSubstring("pwwkew"));
  EXPECT_EQ(1, Solution::lengthOfLongestSubstring("bbbbb"));
  EXPECT_EQ(3, Solution::lengthOfLongestSubstring("abcabcbb"));
}

TEST(SolutionTest, IntToRomanTest) {
  EXPECT_EQ("I", Solution::intToRoman(1));
  EXPECT_EQ("X", Solution::intToRoman(10));
  EXPECT_EQ("VI", Solution::intToRoman(6));
}

TEST(SolutionTest, SearchInsertTest) {
  vector<int> nums1 = {1, 3, 5, 6};
  vector<int> nums2 = {1, 3, 5, 6};
  vector<int> nums3 = {1, 3, 5, 6};
  vector<int> nums4 = {1, 3, 5, 6};
  vector<int> nums5 = {1};
  EXPECT_EQ(2, Solution::searchInsert(nums1, 5));
  EXPECT_EQ(1, Solution::searchInsert(nums2, 2));
  EXPECT_EQ(4, Solution::searchInsert(nums3, 7));
  EXPECT_EQ(0, Solution::searchInsert(nums4, 0));
  EXPECT_EQ(0, Solution::searchInsert(nums5, 0));
}

TEST(SolutionTest, ConvertToBase7Test) {
  EXPECT_EQ("202", Solution::convertToBase7(100));
  EXPECT_EQ("-10", Solution::convertToBase7(-7));
}

TEST(SolutionTest, PivotIndexTest) {

  vector<int> nums1 = {2, 3, -1, 8, 4};
  vector<int> nums2 = {1, -1, 4};
  vector<int> nums3 = {2, 5};
  EXPECT_EQ(3, Solution::pivotIndex(nums1));
  EXPECT_EQ(2, Solution::pivotIndex(nums2));
  EXPECT_EQ(-1, Solution::pivotIndex(nums3));
}
