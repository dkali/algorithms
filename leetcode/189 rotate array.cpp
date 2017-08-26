// https://leetcode.com/problems/rotate-array

// Rotate an array of n elements to the right by k steps.

// For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

// Note:
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

// Hint:
// Could you do it in-place with O(1) extra space?
// Related problem: Reverse Words in a String II

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    if (k > nums.size())
      k = k % nums.size();

    if (k == 0)
      return;

    vector<int> new_v;
    int pos = nums.size() - k;
    for (int i = 0; i < nums.size(); i++) {
      new_v.push_back(nums[pos]);
      pos++;

      if (pos >= nums.size())
        pos = 0;
    }

    nums = new_v;
  }
};