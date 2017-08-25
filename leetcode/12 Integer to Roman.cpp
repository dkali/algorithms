// https://leetcode.com/problems/integer-to-roman

// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <map>
#include <string>
 
using namespace std;
 
class Solution {
private:
    map<int, string> alphabet;
   
    void lookFor(string &result, int &num, int digit, int pre){
        int count = 0;
       
        while (num >= digit) {
            count++;
            num -= digit;
        }
        while (count-- > 0){
            result += alphabet[digit];
        }
       
        if (num >= digit - pre) {
            num -= digit - pre;
            result += alphabet[pre] + alphabet[digit];
        }
    }
   
public:
    Solution(){
        alphabet = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}};
    }
   
    string intToRoman(int num) {
        string result = "";
       
        lookFor(result, num, 1000, 100);
        lookFor(result, num, 500, 100);
        lookFor(result, num, 100, 10);
        lookFor(result, num, 50, 10);
        lookFor(result, num, 10, 1);
        lookFor(result, num, 5, 1);
        lookFor(result, num, 1, 0);
       
        return result;
    }
};