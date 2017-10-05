// https://leetcode.com/problems/maximum-subarray/description/

// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++){
            int tmp = max(nums[i], nums[i] + dp[i-1]);
            dp.push_back(tmp);
            if (tmp > res) res = tmp;
        }
        return res;
    }
};