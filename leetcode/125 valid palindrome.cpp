// https://leetcode.com/problems/valid-palindrome/

// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.

// For the purpose of this problem, we define empty string as valid palindrome.

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctype.h>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    if (s.empty())
      return true;

    bool result = true;
    for (int lc=0, rc=s.length()-1; (lc != rc)&&(lc<rc); lc++, rc--){
      while (!((s.at(lc)>='a' && s.at(lc)<='z') || (s.at(lc)>='A' && s.at(lc)<='Z') || (s.at(lc)>='0' && s.at(lc)<='9')) && lc<rc){
        lc++;
      }
      while(!((s.at(rc)>='a' && s.at(rc)<='z') || (s.at(rc)>='A' && s.at(rc)<='Z') || (s.at(rc)>='0' && s.at(rc)<='9')) && lc<rc){
        rc--;
      }
      if (tolower(s.at(lc)) != tolower(s.at(rc))){
        result = false;
        break;
      }
    }

    return result;
  }
};