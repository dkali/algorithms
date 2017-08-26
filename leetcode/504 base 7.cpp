// https://leetcode.com/problems/base-7

// Given an integer, return its base 7 string representation.

// Example 1:
// Input: 100
// Output: "202"

// Example 2:
// Input: -7
// Output: "-10"

// Note: The input will be in range of [-1e7, 1e7].

#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;
int ASCII_NUMERIC_START = 48;

class Solution {
        public:
        string convertToBase7(int num) {
            int base = 7;
            stack<int> cache;
            string result = num >= 0 ? "" : "-";
            num = abs(num);

            do {
                cache.push(num % base);
                num = num / base;;
            }while(num != 0);

            while(!cache.empty()){
                result += (char)(cache.top() + ASCII_NUMERIC_START);
                cache.pop();
            }

            return result;
        }
};