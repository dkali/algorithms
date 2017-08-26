// https://leetcode.com/problems/missing-number

// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

// For example,
// Given nums = [0, 1, 3] return 2.

// Note:
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    if (nums.empty())
      return 0;
    
    int missing_num = 0;
    int max = nums.at(0);
    // find max value
    for (vector<int>::iterator it=nums.begin(); it != nums.end(); ++it){
      if (max < *it)
        max = *it;
    }

    // create arr from 0 to max+1
    int *tmp_arr = new int[max+2];
    for (int i=0; i<= max+1; i++){
      tmp_arr[i]=i;
    }

    // replace every found entry with -1
    for (int i=0; i<nums.size(); i++){
      tmp_arr[nums[i]] = -1;
    }

    // find first none -1 entry
    for (int i=0; i<= max+1; i++){
      if (tmp_arr[i] != -1){
        missing_num = i;
        break;
      }
    }

    delete[] tmp_arr;
    return missing_num;
  }
};

//========================================

public class Solution {
   
    static int ariphmeticSequence(int n) {
        int result = 0;
        int prev = 0;
        while (prev < n) {
            result += prev + 1;
            prev += 1;
        }
        return result;
    }
   
    public int missingNumber(int[] nums) {
        int temp_summ = 0;
        boolean ifZero = false;
        for(int i: nums) {
            if (i == 0) ifZero = true;
            temp_summ += i;
        }
        if (ariphmeticSequence(nums.length) == temp_summ) {
            if (!ifZero) return 0;
            return nums.length + 1;
        } else {
            return ariphmeticSequence(nums.length) - temp_summ;
        }
    }
}