// https://leetcode.com/problems/valid-palindrome-ii/description/

// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

// Example 1:
// Input: "aba"
// Output: True

// Example 2:
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.

// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

#include <iostream>

using namespace std;

class Solution {
private:
    bool searchSubString(string &s, int i, int k, int spareLetters) {
        while (i < k) {
            if (s[i] == s[k]) {
                i++;
                k--;
            }
            else if (spareLetters > 0) {
                bool ret = false;
                if (s[i+1] == s[k])
                    ret = searchSubString(s, i + 1, k, spareLetters - 1);
                
                if (!ret && s[i] == s[k-1])
                    ret = searchSubString(s, i, k - 1, spareLetters - 1);
                
                return ret;
            }
            else
                return false;
        }
        
        return true;
    }
    
public:
    bool validPalindrome(string s) {
        int spareLetters = 1;
        return searchSubString(s, 0, (int)s.size() - 1, spareLetters);
    }
};