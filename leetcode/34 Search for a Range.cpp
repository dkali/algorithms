// https://leetcode.com/problems/search-for-a-range/description/

// Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lc = 0, rc = nums.size() - 1, tpos = -1;
        vector<int> result;

        while (lc <= rc){
            int mid = (rc - lc)/2 + lc;
            if (nums[mid] == target){
                tpos = mid;
                break;
            }

            if (nums[mid] < target)
                lc = mid + 1;
            else
                rc = mid - 1;
        }

        if (tpos == -1){
            result = {-1, -1};
            return result;
        }

        int tmp = tpos;
        while (nums[tmp] == target && tmp >= 0){
            lc = tmp;
            tmp--;
        }
        while (nums[tpos] == target && tpos < nums.size()){
            rc = tpos;
            tpos++;
        }

        result = {lc, rc};
        return result;
    }
};