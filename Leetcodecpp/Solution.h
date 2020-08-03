#pragma once

#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <mutex>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Node {
public:
  int val;
  std::vector<Node *> children;
  Node() {}
  Node(int _val, std::vector<Node *> _children)
      : val(_val), children(_children) {}
};

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator {
private:
  std::stack<TreeNode *> nodes;

public:
  BSTIterator(TreeNode *root) {
    while (root) {
      nodes.push(root);
      root = root->left;
    }
  }
  /// <summary>
  /// return the next smallest number 
  /// </summary>
  int next() {
    TreeNode *tmp = nodes.top();
    nodes.pop();
    TreeNode *right = tmp->right;
    while (right) {
      nodes.push(right);
      right = right->left;
    }
    return tmp->val;
  }
  /// <summary> 
  /// whether we have a next smallest number
  /// <returns></returns>
  /// </summary>
  bool hasNext() { return !nodes.empty(); }
};

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Foo {
private:
  std::mutex m1, m2;

public:
  Foo() { m1.lock(), m2.lock(); }

  void first(std::function<void()> printFirst) {
    printFirst();
    m1.unlock();
  }
  void second(std::function<void()> printSecond) {
    m1.lock();
    printSecond();
    m1.unlock();
    m2.unlock();
  }
  void third(std::function<void()> printThird) {
    m2.lock();
    printThird();
    m2.unlock();
  }
};

class Solution {
public:
  /// <summary>
  /// 1. Two Sum
  /// </summary>
  static std::vector<int> twoSum(std::vector<int> &nums, int target);

  /// <summary>
  /// 2. Add Two Numbers
  /// </summary>
  static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);

  /// <summary>
  /// 3. Longest Substring Without Repeating Characters
  /// </summary>
  static int lengthOfLongestSubstring(std::string s);

  /// <summary>
  /// 4. Median of Two Sorted Arrays
  /// </summary>
  static double findMedianSortedArrays(std::vector<int> &nums1,
                                       std::vector<int> &nums2);

  /// <summary>
  /// 5. Longest Palindromic Substring
  /// </summary>
  static std::string longestPalindrome(std::string s);

  /// <summary>
  /// 6. ZigZag Conversion
  /// </summary>
  static std::string convert(std::string s, int numRows);

  /// <summary>
  /// 7. Reverse Integer
  /// </summary>
  static int Reverse(int x);

  /// <summary>
  /// 8. String to Integer(atoi)
  /// </summary>
  static int Atoi(std::string str);

  /// <summary>
  /// 9. Palindrome Number
  /// </summary>
  static bool IsPalindrome(int x);

  /// <summary>
  /// 10. Regular Expression Matching
  /// </summary>
  static bool IsMatch(std::string s, std::string p);

  /// <summary>
  /// 11. Container With Most Water
  /// </summary>
  static int maxArea(std::vector<int> &height);

  /// <summary>
  /// 12. Integer to Roman
  /// </summary>
  static std::string intToRoman(int num);

  /// <summary>
  /// 13. Roman to Integer
  /// </summary>
  static int romanToInteger(std::string s);

  /// <summary>
  /// 14. Longest Common Prefix
  /// </summary>
  static std::string longestCommonPrefix(std::vector<std::string> &strs);

  /// <summary>
  /// 15. 3Sum
  /// </summary>
  static std::vector<std::vector<int>> threeSum(std::vector<int> &nums);

  /// <summary>
  /// 16. 3Sum Closest
  /// </summary>
  static int threeSumClosest(std::vector<int> &nums, int target);

  /// <summary>
  /// 17. Letter Combinations of a Phone Number
  /// </summary>
  static std::vector<std::string> letterCombinations(std::string digits);

  /// <summary>
  /// 18. 4Sum
  /// </summary>
  static std::vector<std::vector<int>> fourSum(std::vector<int> &nums,
                                               int target);
  /// <summary>
  /// 19. Remove Nth Node From End of List
  /// </summary>
  static ListNode *removeNthFromEnd(ListNode *head, int n);

  /// <summary>
  /// 20. Valid Parentheses
  /// </summary>
  static bool isValid(std::string s);

  /// <summary>
  /// 21. Merge Two Sorted Lists
  /// </summary>
  static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);

  /// <summary>
  /// 22. Generate Parentheses
  /// </summary>
  static std::vector<std::string> generateParenthesis(int n);

  /// <summary>
  /// 23. Merge K Sorted Lists
  /// </summary>
  static ListNode *mergeKLists(std::vector<ListNode *> &lists);

  /// <summary>
  /// 24. Swap Node in Pairs
  /// </summary>
  static ListNode *swapPairs(ListNode *head);

  /// <summary>
  /// 25. Reverse Nodes in k - Group
  /// </summary>
  static ListNode *reverseKGroup(ListNode *head, int k);

  /// <summary>
  /// 26. Remove Duplicates from Sorted Array
  /// </summary>
  static int removeDuplicates(std::vector<int> &nums);

  /// <summary>
  /// 27. Remove Element
  /// </summary>
  static int removeElement(std::vector<int> &nums, int val);

  /// <summary>
  /// 28. Implement strStr()
  /// </summary>
  static int strStr(std::string haystack, std::string needle);

  /// <summary>
  /// 29. Divide Two Integers
  /// </summary>
  static int divide(int dividend, int divisor);

  /// <summary>
  /// 30. Substring with Concatenation of All Words
  /// </summary>
  static std::vector<int> findSubstring(std::string s,
                                        std::vector<std::string> &words);

  /// <summary>
  /// 31. Next Permutation
  /// </summary>
  static void nextPermutation(std::vector<int> &nums);

  /// <summary>
  /// 33. Search in Rotated Sorted Array
  /// </summary>
  static int search(std::vector<int> &nums, int target);

  /// <summary>
  /// 34. Find First and Last Position of Element in Sorted Array
  /// </summary>
  static std::vector<int> searchRange(std::vector<int> &nums, int target);

  /// <summary>
  /// 35. Search Insert Position
  /// </summary>
  static int searchInsert(std::vector<int> &nums, int target);

  /// <summary>
  /// 36. Valid Sudoku
  /// </summary>
  static bool isValidSudoku(std::vector<std::vector<char>> &board);

  /// <summary>
  /// 37. Sudoku Solver
  /// </summary>
  static void solveSudoku(std::vector<std::vector<char>> &board);

  /// <summary>
  /// 38. Count and Say
  /// </summary>
  std::string countAndSay(int n);

  /// <summary>
  /// 39. Combination Sum
  /// </summary>
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target);

  /// <summary>
  /// 40. Combination Sum II
  /// </summary>
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int target);

  /// <summary>
  /// 41. First Missing Positive
  /// </summary>
  static int firstMissingPositive(std::vector<int> &nums);

  ///< summary>
  /// 43. Multiply String
  /// </summary>
  static std::string multiply(std::string num1, std::string num2);

  /// <summary>
  /// 50. Power(x, n)
  /// </summary>
  static double myPower(double x, int n);

  /// <summary>
  // 51. N - Queens
  /// </summary>
  static std::vector<std::vector<std::string>> solveNQueens(int n);

  /// <summary>
  /// 54. Spiral Matrix
  /// </summary>
  static std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix);

  /// <summary>
  /// 55. Jump Game
  /// <summary>
  static bool canJump(std::vector<int> &nums);

  /// <summary>
  /// 58. Length of Last Word
  /// </summary>
  static int lengthOfLastWord(std::string s);

  /// <summary>
  /// 59. Spiral Matrix II
  /// </summary>
  static std::vector<std::vector<int>> generateMatrix(int n);

  /// <summary>
  /// 61. Rotate List
  /// </summary>
  static ListNode *rotateRight(ListNode *head, int k);

  /// <summary>
  /// 62. Unique Paths
  /// </summary>
  static int uniquePaths(int m, int n);

  /// <summary>
  // 63. Unique Paths II
  /// </summary>
  static int
  uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid);

  /// <summary>
  /// <summary> 64. Minimum Path Sum
  /// </summary>
  static int minPathSum(std::vector<std::vector<int>> &grid);

  /// <summary>
  /// 66. Plus One
  /// </summary>
  static std::vector<int> plusOne(std::vector<int> &digits);

  /// <summary>
  /// 67. Add Binary
  /// </summary>
  static std::string addBinary(std::string a, std::string b);

  /// <summary>
  /// 69. Sqrt(x)
  /// </summary>
  static int mySqrt(int x);

  /// <summary>
  /// 70. Climb Stairs
  /// </summary>
  static int climbStairs(int n);

  /// <summary>
  /// 74. Search a 2D Matrix
  /// </summary>
  static bool searchMatrix(std::vector<std::vector<int>> &nums, int target);

  /// <summary>
  /// 77. Combinations
  /// </summary>
  static std::vector<std::vector<int>> combine(int n, int k);

  /// <summary>
  /// 94. Binary Tree Inorder Traversal
  /// </summary>
  static std::vector<int> inorderTraversal(TreeNode *root);

  /// <summary>
  /// 100. Same Tree
  /// </summary>
  static bool isSameTree(TreeNode *p, TreeNode *q);

  /// <summary>
  /// 101. Symmetric Tree
  /// </summary>
  static bool isSymmetric(TreeNode *root);

  /// <summary>
  /// 104. Maximum Depth of Binary Tree
  /// </summary>
  static int maxDepth(TreeNode *root);

  /// <summary>
  /// 107. Binary Tree Level Order Traversal II
  /// </summary>
  static std::vector<std::vector<int>> levelOrderBottom(TreeNode *root);

  /// <summary>
  /// 111. Minimum Depth of Binary Tree
  /// </summary>
  static int minDepth(TreeNode *root);

  /// <summary>
  /// 112. Path Sum
  /// </summary>
  static bool hasPathSum(TreeNode *root, int sum);

  /// <summary>
  /// 118. Pascal's Triangle
  /// </summary>
  static std::vector<std::vector<int>> generate(int numRows);

  /// <summary>
  /// 125. Valid Palindrome
  /// </summary>
  static bool isPalindrome(std::string s);

  /// <summary>
  /// 136. Single Number
  /// </summary>
  static int singleNumber(std::vector<int> &nums);

  /// <summary>
  /// 141. Linked List Cycle
  /// </summary>
  static bool hasCycle(ListNode *head);

  /// <summary>
  /// 144. Binary Tree Preorder Traversal
  /// </summary>
  static std::vector<int> preorderTraversal(TreeNode *root);

  /// <summary>
  /// 145. Binary Tree Postorder Traversal
  /// </summary>
  static std::vector<int> postorderTraversal(TreeNode *root);

  /// <summary>
  /// 148. Sort List
  /// </summary>
  static ListNode *sortList(ListNode *head);

  /// <summary>
  /// 169. Majority Element
  /// </summary>
  static int majorityElement(std::vector<int> &nums);

  /// <summary>
  /// 190. Reverse Bits
  /// </summary>
  static uint32_t reverseBits(uint32_t n);

  /// <summary>
  /// 198. House Robber
  /// </summary>
  static int rob(std::vector<int> &nums);

  /// <summary>
  /// 242. Valid Anagram
  /// </summary>
  static bool isAnagram(std::string s, std::string t);

  /// <summary>
  /// 268. Missing Number
  /// </summary>
  static int missingNumber(std::vector<int> &nums);

  /// <summary>
  /// 283. Move Zeroes
  /// </summary>
  static void moveZeroes(std::vector<int> &nums);

  /// <summary>
  /// 287. Find the Duplicate Number
  /// </summary>
  static int findDuplicate(std::vector<int> &nums);

  /// <summary>
  /// 344. Reverse String
  /// </summary>
  static void reverseString(std::vector<char> &s);

  /// <summary>
  /// 401. Binary Watch
  /// </summary>
  static std::vector<std::string> readBinaryWatch(int num);

  /// <summary>
  /// 415. Add Strings
  /// </summary>
  /// <param name="num1"></param>
  /// <param name="num2"></param>
  /// <returns></returns>
  static std::string addStrings(std::string &num1, std::string &num2);

  /// <summary>
  /// 429. N - ary Tree Level Order Traversal
  /// </summary>
  static std::vector<std::vector<int>> levelOrder(Node *root);

  /// <summary>
  /// 509. Fibonacci Number
  /// </summary>
  static int fib(int N);

  /// <summary>
  /// 617. Merge Two Binary Trees
  /// </summary>
  static TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2);

  /// <summary>
  /// 669. Trim a Binary Search Tree
  /// </summary>
  static TreeNode *trimBST(TreeNode *root, int L, int R);

  /// <summary>
  /// 700. Search in a Binary Search Tree
  /// </summary>
  static TreeNode *searchBST(TreeNode *root, int val);

  /// <summary>
  /// 701. Insert into a Binary Search Tree
  /// </summary>
  static TreeNode *insertIntoBST(TreeNode *root, int val);

  /// <summary>
  /// 709. To Lower Case
  /// </summary>
  static std::string toLowerCase(std::string str);

  /// <summary>
  /// 739. Daily Temperatures
  /// </summary>
  static std::vector<int> dailyTemperatures(std::vector<int> &T);

  /// <summary>
  /// 821. Shortest Distance to a Character
  /// </summary>
  static std::vector<int> shortestToChar(std::string S, char C);

  /// <summary>
  /// 852. Peak Index in a Mountain Array
  /// </summary>
  static int peakIndexInMountainArray(std::vector<int> &A);

  /// <summary>
  /// 876. Middle of the Linked List
  /// </summary>
  static ListNode *middleNode(ListNode *head);

  /// <summary>
  /// 883. Projection Area of 3D Shapes
  /// </summary>
  static int projectionArea(std::vector<std::vector<int>> &grid);

  /// <summary>
  /// 884. Uncommon Words from Two Sentences
  /// </summary>
  static std::vector<std::string> uncommonFromSentences(std::string A,
                                                        std::string B);

  /// <summary>
  /// 892. Surface Area of 3D Shapes
  /// </summary>
  static int surfaceArea(std::vector<std::vector<int>> &grid);

  /// <summary>
  /// 905. Sort Array By Parity
  /// </summary>
  static std::vector<int> sortArrayByParity(std::vector<int> &A);

  /// <summary>
  /// 938. Range Sum of BST
  /// </summary>
  static int rangeSumBST(TreeNode *root, int L, int R);

  /// <summary>
  /// 1260. Shift 2D Grid
  /// </summary>
  static std::vector<std::vector<int>>
  shiftGrid(std::vector<std::vector<int>> &grid, int k);

  /// <summary>
  /// 1263. Minimum Moves to Move a Box to Their Target Location
  /// </summary>
  static int minPushBox(std::vector<std::vector<char>> &grid);

private:
  static bool isMirror(TreeNode *l1, TreeNode *l2);

  static bool doSolve(std::vector<std::vector<char>> &board, int row, int col);
  static bool isValid(std::vector<std::vector<char>> &board, int row, int col,
                      char num);

  static ListNode *split(ListNode *head, int n);
  static ListNode *merge(ListNode *l1, ListNode *l2, ListNode *head);
  static std::string preProcess(std::string s);

  static bool isValid(std::vector<std::string> &nQueens, int row, int col,
                      int &n);
  static void solveNQueens(std::vector<std::vector<std::string>> &res,
                           std::vector<std::string> nQueens,
                           std::vector<int> &flag, int row, int &n);

  static std::vector<int> kmpProcess(std::string &needle);
};