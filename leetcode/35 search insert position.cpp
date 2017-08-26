// https://leetcode.com/problems/search-insert-position

// Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You may assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

// ====== V1 RECURSION =====
#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
private:
  vector<int> arr;
  int target;

public:
  int searchInsert(vector<int>& nums, int t) {
    arr = nums;
    target = t;

    int position = bsearch(0, nums.size() - 1);
    return position;
  }

private:
  int bsearch(int l, int r) {
    int check_position = l + (r - l) / 2;

    if (arr[check_position] == target) {
      return check_position;
    }
    else {
      if (l == r) {
        if (arr[check_position] > target)
          return l;
        else
          return l + 1;
      }
        

      if (arr[check_position] > target) {
        r = check_position - 1;
        r = r < l ? l : r;
        return bsearch(l, r);
      }
      else {
        l = check_position + 1;
        return bsearch(l, r);
      }
    }
  }
};

// ====== V2 ITERATIVE =====
using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
      int mid_position = l + (r - l) / 2;

      if (nums[mid_position] < target)
        l = ++mid_position;
      else
        r = --mid_position;
    }

    return l;
  }
};