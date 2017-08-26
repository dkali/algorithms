// https://leetcode.com/problems/detect-capital

// Given a word, you need to judge whether the usage of capitals in it is right or not.

// We define the usage of capitals in a word to be right when one of the following cases holds:

// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital if it has more than one letter, like "Google".
// Otherwise, we define that this word doesn't use capitals in a right way.

// Example 1:
// Input: "USA"
// Output: True

// Example 2:
// Input: "FlaG"
// Output: False

// Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int LETTERS_START = 97;

    bool detectCapitalUse(string word) {
        bool bCorrect = false;

        if (word.size() > 0){
            bool bFirstCapital = word[0] < LETTERS_START;
            bool bFoundCapital = false, bFoundSmall = false;
            for (int i = 1; i < word.size(); i++){
                if (word[i] < LETTERS_START)
                    bFoundCapital |= true;
                else
                    bFoundSmall |= true;
            }

            if (bFirstCapital && !bFoundSmall || //USA
                bFirstCapital && !bFoundCapital || //Google
                !bFirstCapital && !bFoundCapital) { // small
                bCorrect = true;
            }
        }

        return bCorrect;
    }
};