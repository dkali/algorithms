// https://leetcode.com/problems/longest-palindrome

// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

// This is case sensitive, for example "Aa" is not considered a palindrome here.

// Note:
// Assume the length of given string will not exceed 1,010.

// Example:
// Input:
// "abccccdd"

// Output:
// 7

// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
  int longestPalindrome(string input) {
    int alph[127] = {0};
    int len = 0;
    bool bSingleChar = false;

    for (char c : input){
      alph[c]++;
    }

    for (int i = 65; i < 127; i++){
      if (alph[i] != 0){
        if (alph[i] % 2 == 0)
          len = len + alph[i];
        else{
          bSingleChar = true;
          len = len + alph[i] - 1;
        }
      }
    }

    if (bSingleChar == true)
      len++;

    return len;
  }
};