// https://leetcode.com/problems/letter-combinations-of-a-phone-number

// Given a digit string, return all possible letter combinations that the number could represent.

// A mapping of digit to letters (just like on the telephone buttons) is given below.

// 1/     2/abc  3/def
// 4/ghi  5/jki  6/mno
// 7/pqrs 8/tuv  9/wxyz

// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.

#include <iostream>
#include <vector>
#include <map>
#include <string>
 
using namespace std;
 
class Solution {
private:
    map<int, vector<char>> alphabet = {{2, {'a', 'b', 'c'}},
                                       {3, {'d', 'e', 'f'}},
                                       {4, {'g', 'h', 'i'}},
                                       {5, {'j', 'k', 'l'}},
                                       {6, {'m', 'n', 'o'}},
                                       {7, {'p', 'q', 'r', 's'}},
                                       {8, {'t', 'u', 'v'}},
                                       {9, {'w', 'x', 'y', 'z'}}};
    vector<string> res;
 
    void backtrack(string digits, int digit_pos, string tmp_str){
        if (tmp_str.size() == digits.size()){
            res.push_back(tmp_str);
        }
 
        vector<char> letters = alphabet[digits[digit_pos] - 48];
        int next_digit_pos = digit_pos + 1;
        for (auto it = letters.begin(); it != letters.end(); ++ it){
            tmp_str.push_back(*it);
            backtrack(digits, next_digit_pos, tmp_str);
            tmp_str.pop_back();
        }
    }
 
public:
    vector<string> letterCombinations(string digits) {
        int digit_pos = 0;
        if (digits != ""){
            string tmp_str = "";
            backtrack(digits, digit_pos, tmp_str);
        }
 
        return res;
    }
};