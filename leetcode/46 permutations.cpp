// https://leetcode.com/problems/permutations

// Given a collection of distinct numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
  bool containDigit(vector<int> v, int n) {
    for (auto it = v.begin(); it != v.end(); ++it) {
      if (*it == n)
        return true;
    }
    return false;
  }

  void backtrack(vector<vector<int>> &result, vector<int> &line, vector<int> &nums) {
    if (line.size() == nums.size()) {
      result.push_back(line);
    }

    for (auto digit = nums.begin(); digit != nums.end(); ++digit) {
      if (containDigit(line, *digit)) {
        continue;
      }

      line.push_back(*digit);
      backtrack(result, line, nums);
      line.pop_back();
    }
  }

public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> line;
    backtrack(result, line, nums);

    return result;
  }
};