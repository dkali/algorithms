// https://leetcode.com/problems/reconstruct-original-digits-from-english/
// pronin: http://pastebin.com/Hg5kG9vx

// Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

// Note:
// Input contains only lowercase English letters.
// Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
// Input length is less than 50,000.
// Example 1:
// Input: "owoztneoer"

// Output: "012"
// Example 2:
// Input: "fviefuro"

// Output: "45"

#include "stdafx.h"

#include <iostream>
#include <string>
#include <array>

using namespace std;

//z	zero
//w	two
//u	four
//x	six
//g	eigth
//h	three	count[h] - count[eight]
//s	seven	count[s] - count[six]
//v	five	count[v] - count[seven]
//i	nine	count[i] - count[six, eight, five]
//n	one		count[n] - count[seven, 2*nine]

class Solution {
  array<int, 26> alphabet;
  array<int, 10> digits;

public:
  Solution() {
    this->alphabet.fill(0);
    this->digits.fill(0);
  }

  string originalDigits(string s) {
    string result = "";

    init_dictionary(s);

    digits[0] = alphabet['z' - 'a'];
    digits[2] = alphabet['w' - 'a'];
    digits[4] = alphabet['u' - 'a'];
    digits[6] = alphabet['x' - 'a'];
    digits[8] = alphabet['g' - 'a'];
    digits[3] = alphabet['h' - 'a'] - digits[8];
    digits[7] = alphabet['s' - 'a'] - digits[6];
    digits[5] = alphabet['v' - 'a'] - digits[7];
    digits[9] = alphabet['i' - 'a'] - digits[6] - digits[8] - digits[5];
    digits[1] = alphabet['n' - 'a'] - digits[7] - 2 * digits[9];

    //assemble string in ascending order
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < digits[i]; j++) {
        result += to_string(i);
      }
    }

    return result;
  }

private:
  void init_dictionary(string input) {
    for (char letter : input) {
      this->alphabet[letter - 'a']++;
    }
  }
};