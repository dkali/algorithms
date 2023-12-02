// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/

// Given an array nums of integers, return how many of them contain an even number of digits.

// Example 1:
// Input: nums = [12,345,2,6,7896]
// Output: 2
// Explanation: 
// 12 contains 2 digits (even number of digits). 
// 345 contains 3 digits (odd number of digits). 
// 2 contains 1 digit (odd number of digits). 
// 6 contains 1 digit (odd number of digits). 
// 7896 contains 4 digits (even number of digits). 
// Therefore only 12 and 7896 contain an even number of digits.

// Example 2:
// Input: nums = [555,901,482,1771]
// Output: 1 
// Explanation: 
// Only 1771 contains an even number of digits.

class Solution {
    public int FindNumbers(int[] nums) {
        int count = 0;

        foreach (int num in nums) {
            if (estimateNumber(num))
                count += 1;
        }

        return count;
    }

    private bool estimateNumber(int num) {
        int digitCount = 0;
        while (num != 0) {
            num = num / 10;
            digitCount += 1;
        }

        return digitCount % 2 == 0;
    }
}