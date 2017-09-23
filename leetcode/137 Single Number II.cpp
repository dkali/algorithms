// https://leetcode.com/problems/single-number-ii/discuss/

// Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int bitpos = 0; bitpos < 32; bitpos++){
            int summ = 0;
            for (int i = 0; i < nums.size(); i++){
                if ((nums[i] >> bitpos) & 1 == 1){
                    summ++;
                    summ %= 3;
                }
            }
            if (summ != 0)
                result |= summ << bitpos;
        }
        return result;
    }
};
