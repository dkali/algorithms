// https://leetcode.com/problems/permutation-in-string

// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

// Example 1:
// Input:s1 = "ab" s2 = "eidbaooo"
// Output:True
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False

// Note:
// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].
 
#include <iostream>
#include <map>
 
using namespace std;
 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> charData;
        for (char c : s1){
            charData[c]++;
        }
 
        map<char, int> *tmp = nullptr;
        int target = s1.size(), cur = 0;
        for (int i = 0; i < s2.size(); i++){
            char c = s2[i];
 
            if (charData[c] != 0){
                if (tmp == nullptr)
                    tmp = new map<char, int>(charData);
                if (tmp->at(c) > 0){
                    tmp->at(c)--;
 
                    if (++cur == target){
                        return true;
                    }
                }
                else{
                    //go back;
                    int rewindCount = charData[c];
 
                    while (rewindCount > 0){
                        if (s2[--i] == c){
                            rewindCount--;
                        }
                    }
 
                    delete tmp;
                    tmp = new map<char, int>(charData);
                    cur = 0;
                }
 
            }
            else{
                if (tmp != nullptr){
                    delete tmp;
                    tmp = nullptr;
                }
                cur = 0;
            }
        }
 
        if (tmp != nullptr){
            delete tmp;
            tmp = nullptr;
        }
 
        return false;
    }
};