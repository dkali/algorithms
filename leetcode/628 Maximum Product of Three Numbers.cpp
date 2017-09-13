// https://leetcode.com/problems/maximum-product-of-three-numbers

// Given an integer array, find three numbers whose product is maximum and output the maximum product.

// Example 1:
// Input: [1,2,3]
// Output: 6

// Example 2:
// Input: [1,2,3,4]
// Output: 24

// Note:
// The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
// Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.

#include <iostream>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mina = INT_MAX, minb = INT_MAX, maxa = INT_MIN, maxb = INT_MIN, maxc = INT_MIN;
        for (int n : nums){
            if (n < minb){
                minb = n;
                if (n < mina){
                    minb = mina;
                    mina = n;
                }
            }
            if (n > maxa){
                maxa = n;
                if (n > maxb){
                    maxa = maxb;
                    maxb = n;
                    if (n > maxc){
                        maxb = maxc;
                        maxc = n;
                    }
                }
            }
        }
        return max(mina * minb * maxc, maxa * maxb * maxc);
    }
};
