// https://leetcode.com/problems/target-sum

// You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

// Find out how many ways to assign symbols to make sum of integers equal to target S.

// Example 1:
// Input: nums is [1, 1, 1, 1, 1], S is 3. 
// Output: 5
// Explanation: 

// -1+1+1+1+1 = 3
// +1-1+1+1+1 = 3
// +1+1-1+1+1 = 3
// +1+1+1-1+1 = 3
// +1+1+1+1-1 = 3

// There are 5 ways to assign symbols to make the sum of nums be target 3.
// Note:
// The length of the given array is positive and will not exceed 20.
// The sum of elements in the given array will not exceed 1000.
// Your output answer is guaranteed to be fitted in a 32-bit integer.

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  void backtrack(int &counter, vector<int> &nums, int target, int index) {
    if (index == nums.size()) {
      if (0 == target)
        counter++;
    }
    else {
      backtrack(counter, nums, target + nums[index], index + 1);
      backtrack(counter, nums, target - nums[index], index + 1);
    }
  }

public:
  int findTargetSumWays(vector<int>& nums, int s) {
    int counter = 0;
    int pos = 0;
    backtrack(counter, nums, s, pos);

    return counter;
  }
};


////============================================
#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  void backtrack(int &counter, vector<int> &nums, int &target, int index) {
    if (index == nums.size()) {
      int summ = 0;
      for (auto it = nums.begin(); it != nums.end(); ++it) {
        summ += *it;
      }

      if (summ == target)
        counter++;
    }
    else {
      backtrack(counter, nums, target, index+1);
      nums[index] = -1 * nums[index];
      backtrack(counter, nums, target, index+1);
    }
  }

public:
  int findTargetSumWays(vector<int>& nums, int s) {
    int counter = 0;
    int pos = 0;
    backtrack(counter, nums, s, pos);

    return counter;
  }
};