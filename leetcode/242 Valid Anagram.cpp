// https://leetcode.com/problems/valid-anagram/

// Given two strings s and t, write a function to determine if t is an anagram of s.

// For example,
// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "car", return false.

// Note:
// You may assume the string contains only lowercase alphabets.

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int sum[26] = {};

    if (s.size() != t.size())
      return false;
    
    for (int i=0; i<s.size(); i++)
      sum[s.at(i)-'a']++;

    for (int i=0; i<s.size(); i++)
      sum[t.at(i)-'a']--;

    for (int i=0; i<26; i++){
      if (sum[i] != 0)
        return false;
    }
    return true;
  }

};