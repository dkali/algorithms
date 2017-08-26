// https://leetcode.com/problems/sort-characters-by-frequency/

// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:
// Input:
// "tree"

// Output:
// "eert"

// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// ------------

// Example 2:
// Input:
// "cccaaa"

// Output:
// "cccaaa"

// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// ------------

// Example 3:

// Input:
// "Aabb"

// Output:
// "bbAa"

// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

#include <iostream>
#include <string>
#include <queue>
#include <deque>

using namespace std;

class FPair {
public:
  char c;
  int freq;

  FPair(char ch, int f) {
    c = ch;
    freq = f;
  }
};

class MyComparision {
public:
  bool operator() (const FPair &lhs, const FPair &rhs) const {
    return lhs.freq < rhs.freq;
  }
};

class Solution {
public:
  string frequencySort(string s) {
    int arr[127] = {};
    for (char c : s) { arr[c]++; }

    typedef priority_queue<FPair, deque<FPair>, MyComparision> mypq_type;
    mypq_type mypq;
    for (int i = 0; i < 127; i++) {
      if (arr[i] != 0) {
        mypq.push(FPair((char)i, arr[i]));
      }
    }

    s = "";
    while (!mypq.empty()) {
      FPair fp = mypq.top();
      while (fp.freq-- > 0)
        s += fp.c;
      mypq.pop();
    }

    return s;
  }
};