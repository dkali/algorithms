//https://leetcode.com/problems/remove-k-digits/description/

// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size())
            return "0";
        
        stack<char> bucket;
        char last = '#';
        
        for (char c : num){
            if (last == '#'){
                if (c != '0') {
                    bucket.push(c);
                    last = c;
                }
                continue;
            }
            
            while (last > c && k > 0) {
                bucket.pop();
                k--;
                if (bucket.size() == 0)
                    last = '#';
                else
                    last = bucket.top();
            }
            
            if (c != '0' || bucket.size() != 0) {
                bucket.push(c);
                last = c;
            }
        }
        
        while (k-- > 0)
            bucket.pop();
        
        //reconstruct string from stack
        string ret = "";
        ret.resize(bucket.size(), '-');
        while (!bucket.empty()) {
            ret[bucket.size() - 1] = bucket.top();
            bucket.pop();
        }
        
        return ret == "" ? "0" : ret;
    }
};
