// A pangram is a sentence where every letter of the English alphabet appears at least once.

// Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.
 
// Example 1:
// Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
// Output: true
// Explanation: sentence contains at least one of every letter of the English alphabet.

// Example 2:
// Input: sentence = "leetcode"
// Output: false
 
// Constraints:
// 1 <= sentence.length <= 1000
// sentence consists of lowercase English letters.

#include <iostream>
#include <set>

using namespace std;

// Option1: with Set
class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<int> chars;

        for (char c : sentence) {
            chars.insert(c);
        }

        return chars.size() == 26;
    }
};

// Option 2: int bits, less space used
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int seen = 0;
        
        for (char c : sentence) {
            int ci = c - 'a';
            seen |= 1 << ci;
        }
        
        return seen == (1 << 26) - 1;
    }
};