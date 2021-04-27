// https://leetcode.com/problems/reverse-integer/

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example 1:
// Input: x = 123
// Output: 321

// Example 2:
// Input: x = -123
// Output: -321

// Example 3:
// Input: x = 120
// Output: 21

// Example 4:
// Input: x = 0
// Output: 0
 
// Constraints:
// -2^31 <= x <= 2^31 - 1

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        bool negative = x < 0;
        
        if (x == INT_MIN)
            return 0;
        
        if (negative)
            x = x * (-1);
        while (x != 0) {
            int num = x % 10;
            x = x / 10;
//            2 147 483 647
//            -2 147 483 648
            if (result >= 214748364) {
                if ((num > 7) && !negative ||
                    (num > 8) && negative ||
                    (result > 214748364))
                    return 0;
            }
            result = result * 10 + num;
        }
        
        if (negative)
            result *= -1;
        
        return result;
    }
};