// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array nums = [1,1,1,2,2,3],

// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int limit = 2;
        int current_limit = limit - 1;
        int counter = 0;
        
        for (int i = 1, pos = 0; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                current_limit--;
                if (current_limit >= 0)
                    pos++;
                else
                    counter++;
            }
            else {
                current_limit = limit - 1;
                pos++;
            }
            if (pos < i)
                nums[pos] = nums[i];
        }
        
        return (int)(nums.size() - counter);
    }
};