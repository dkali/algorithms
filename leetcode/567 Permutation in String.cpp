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
        for (char c : s1){charData[c]++;}
 
        int wstart = -1;
        int win_len = 0;
        for (int i = 0; i < s2.size(); i++){
            if (charData[s2[i]] > 0){
                if (wstart == -1)
                    wstart = i;
                charData[s2[i]]--;
                win_len++;
 
                if (win_len == s1.size())
                    return true;
            }
            else if (wstart != -1){
                //we are inside sliding window
                bool waiting = true;
                while (wstart != i && waiting){
                    charData[s2[wstart]]++;
                    wstart++;
                    win_len--;
 
                    //re-evaluate
                    if (charData[s2[i]] > 0){
                        charData[s2[i]]--;
                        waiting = false;
                        win_len++;
                    }
                }
 
                if (waiting == true){
                    //move outside of sliding window
                    wstart = -1;
                }
            }
        }
 
        return false;
    }
};

// ========= V2 =======
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int bucket1[26] = {}, bucket2[26] = {};
        if (s2.size() < s1.size())
            return false;

        for (char c : s1){bucket1[c - 'a']++;}
        for (int i = 0; i < s1.size(); i++){bucket2[s2[i] - 'a']++;}

        int left_pos = 0, right_pos = s1.size() - 1;
        while (right_pos < s2.size()){
            bool bmatch = true;
            for (int i = 0; i < 26; i++){
                if (bucket1[i] != bucket2[i]){
                    bmatch = false;
                    break;
                }
            }
            if (bmatch) return true;

            bucket2[s2[left_pos] - 'a']--;
            left_pos++;
            right_pos++;
            if (right_pos < s2.size()){
                bucket2[s2[right_pos] - 'a']++;
            }
        }

        return false;
    }
};