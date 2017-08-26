// https://leetcode.com/problems/reverse-vowels-of-a-string

// Write a function that takes a string as input and reverse only the vowels of a string.

// Example 1:
// Given s = "hello", return "holle".

// Example 2:
// Given s = "leetcode", return "leotcede".

// Note:
// The vowels does not include the letter "y".

#include "stdafx.h"

#include <iostream>
#include <string>
#include <math.h>
#include <set>

using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
    //find all vowels positions
    int i = 0, k = s.size() - 1;
    while (i < k) {
      if (isVowel(s[i]) && isVowel(s[k])) {
        swap(s, i, k);
        i++;
        k--;
      }
      else {
        if (!isVowel(s[i]))
          i++;

        if (!isVowel(s[k]))
          k--;
      }
    }

    return s;
  }

  Solution() {
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');

    vowels.insert('A');
    vowels.insert('E');
    vowels.insert('I');
    vowels.insert('O');
    vowels.insert('U');
  }

private:

  set<char> vowels;

  void swap(string &s, int i, int k) {
    char tmp = s[i];
    s[i] = s[k];
    s[k] = tmp;
  }

  bool isVowel(char c) {
    if (vowels.find(c) == vowels.end())
      return false;
    else
      return true;
  };

};