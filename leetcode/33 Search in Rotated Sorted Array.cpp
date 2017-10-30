// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> vec;
    int target;
    
    long findMid(long left, long right){
        long midPos = (right - left) / 2 + left;
        
        if (vec[midPos] < vec[0]){
            if (vec[midPos - 1] > vec[midPos])
                return midPos;
            else
                return findMid(left, midPos - 1);
        }
        else
            return findMid(midPos + 1, right);
    }
    
    long binarySearch(long left, long right){
        long midPos = (right - left) / 2 + left;
        
        if (vec[midPos] == target)
            return midPos;
        else if (right - left == 0 || left > right)
            return - 1;
        else if (vec[midPos] > target)
            return binarySearch(left, midPos - 1);
        else
            return binarySearch(midPos + 1, right);
    }
    
public:
    int search(vector<int>& nums, int t) {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return nums[0] == t ? 0 : -1;
        
        vec = nums;
        target = t;
        long midPos = nums.size() - 1;
        bool straitgh = nums[0] < nums[nums.size() - 1];
        if (!straitgh)
            midPos = findMid(0, nums.size() - 1);
        
        long pos;
        if (straitgh)
            pos = binarySearch(0, midPos);
        else if (target >= nums[0])
            pos = binarySearch(0, midPos - 1);
        else
            pos = binarySearch(midPos, nums.size() - 1);
        
        return (int)pos;
    }
};
