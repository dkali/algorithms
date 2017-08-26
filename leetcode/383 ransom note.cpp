// https://leetcode.com/problems/ransom-note

// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

// Each letter in the magazine string can only be used once in your ransom note.

// Note:
// You may assume that both strings contain only lowercase letters.

// canConstruct("a", "b") -> false
// canConstruct("aa", "ab") -> false
// canConstruct("aa", "aab") -> true

#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      bool match = true;
      int map1[127] = {0};
      int map2[127] = {0};

      construct_map(ransomNote, map1);
      construct_map(magazine, map2);

      for (int i = 97; i < 123; i++) {
        if (map1[i] != 0){
          if (map1[i] > map2[i]){
            match = false;
            break;
          }
        }
      }

      return match;
    }

    void construct_map(string str, int map[]){
      for (char c : str){
        map[c]++;
      }
    }
};