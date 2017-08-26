// https://leetcode.com/problems/summary-ranges

// Given a sorted integer array without duplicates, return the summary of its ranges.

// Example 1:
// Input: [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]

// Example 2:
// Input: [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    string token = "";

    if (nums.size() == 0) {
      return result;
    }

    int range_start = nums[0];
    token = to_string(nums[0]);

    if (nums.size() == 1) {
      result.push_back(token);
      return result;
    }

    for (int i = 1; i < nums.size(); i++) {
      if (!(nums[i] + 1 == nums[i - 1] || nums[i - 1] + 1 == nums[i])) {
        if (nums[i - 1] == range_start) {
          result.push_back(token);
        }
        else
        {
          token = token + "->" + to_string(nums[i - 1]);
          result.push_back(token);
        }

        range_start = nums[i];
        token = to_string(nums[i]);
        if (i == nums.size() - 1) {
          result.push_back(token);
        }
      }
      else if (i == nums.size() - 1) {
        token = token + "->" + to_string(nums[i]);
        result.push_back(token);
      }
    }

    return result;
  }
};