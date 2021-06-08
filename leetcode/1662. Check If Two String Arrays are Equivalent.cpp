// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

// Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
// A string is represented by an array if the array elements concatenated in order forms the string.
 

// Example 1:
// Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
// Output: true
// Explanation:
// word1 represents string "ab" + "c" -> "abc"
// word2 represents string "a" + "bc" -> "abc"
// The strings are the same, so return true.

// Example 2:
// Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
// Output: false

// Example 3:
// Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
// Output: true
 
// Constraints:
// 1 <= word1.length, word2.length <= 103
// 1 <= word1[i].length, word2[i].length <= 103
// 1 <= sum(word1[i].length), sum(word2[i].length) <= 103
// word1[i] and word2[i] consist of lowercase letters.

class Solution {
    char getCurrentLetter(vector<string>& words, int& wordCounter, int& curLetter) {
        if (curLetter >= words[wordCounter].size()) {
            curLetter = 0;
            wordCounter++;
            if (wordCounter >= words.size()) {
                return 0;
            }
        }
        
        return words[wordCounter][curLetter++];
    }
    
public:
    bool arrayStringsAreEqual(vector<string>& words1, vector<string>& words2) {
        int wordCounter1 = 0, wordCounter2 = 0;
        int curLetter1 = 0, curLetter2 = 0;
        char ch1 = 0, ch2 = 0;
        
        do {
            ch1 = getCurrentLetter(words1, wordCounter1, curLetter1);
            ch2 = getCurrentLetter(words2, wordCounter2, curLetter2);
            if (ch1 != ch2)
                return false;
        }
        while (ch1 != 0 || ch2 != 0);
        
        return true;
    }
};