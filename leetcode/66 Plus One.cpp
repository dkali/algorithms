// https://leetcode.com/problems/plus-one

// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

// You may assume the integer do not contain any leading zero, except the number 0 itself.

// The digits are stored such that the most significant digit is at the head of the list.

#include <iostream>
#include <vector>
 
using namespace std;
 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int remnant = 1;
        for (int i = digits.size() - 1; i >= 0; i--){
            int newD = digits[i] + remnant;
            if (newD - 10 >= 0){
                digits[i] = newD - 10;
            }
            else{
                digits[i] = newD;
                remnant = 0;
                break;
            }
        }
 
        if (remnant == 0){
            return digits;
        }
        else{
            vector<int> newV = {1};
            for (auto it = digits.begin(); it != digits.end(); ++it){
                newV.push_back(*it);
            }
            return newV;
        }
    }
};