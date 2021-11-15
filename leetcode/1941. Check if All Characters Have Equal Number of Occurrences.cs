// https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/

// Given a string s, return true if s is a good string, or false otherwise.

// A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

// Example 1:
// Input: s = "abacbc"
// Output: true
// Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

// Example 2:
// Input: s = "aaabb"
// Output: false
// Explanation: The characters that appear in s are 'a' and 'b'.
// 'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.

// Constraints:
// 1 <= s.length <= 1000
// s consists of lowercase English letters.

public class Solution
{
    public bool AreOccurrencesEqual(string str)
    {
        int[] freq = new int[32];

        foreach (char c in str)
        {
            freq[c - 'a']++;
        }

        int tmp = freq[str[0] - 'a'];
        foreach (int num in freq)
        {
            if (num != 0)
            {
                if (num != tmp)
                    return false;
            }
        }

        return true;
    }
}