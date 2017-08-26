// https://leetcode.com/problems/happy-number/

// Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

// Example: 19 is a happy number

// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int depth;

  Solution(){
    depth = 10;
  }

  bool isHappy(int n) {
    int summ = 0;
    bool result = false;
    while (n>0){
      summ = summ + (n%10)*(n%10);
      n = n/10;
    }

    if (summ != 1){
      if (depth > 0){
        depth--;
        result = isHappy(summ);
      }
      else
        result = false;
    }
    else{
      result = true;
    }
    return result;
  }
};