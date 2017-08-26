// https://leetcode.com/problems/counting-bits/

// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Example:
// For num = 5 you should return [0,1,1,2,1,2].

// Follow up:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> myvector;

    for (int i=0; i<=num; i++){
      myvector.push_back(bits_summ(i));
    }

    return myvector;
  }

  int bits_summ(int num){
    int summ = 0;
    while(num>0){
      if ((num & 1) == 1)
        summ++;
      num = num >> 1;
    }
    return summ;
  }
};