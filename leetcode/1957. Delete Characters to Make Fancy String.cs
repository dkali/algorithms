// https://leetcode.com/problems/delete-characters-to-make-fancy-string/

// A fancy string is a string where no three consecutive characters are equal.
// Given a string s, delete the minimum possible number of characters from s to make it fancy.
// Return the final string after the deletion. It can be shown that the answer will always be unique.

// Example 1:
// Input: s = "leeetcode"
// Output: "leetcode"
// Explanation:
// Remove an 'e' from the first group of 'e's to create "leetcode".
// No three consecutive characters are equal, so return "leetcode".

// Example 2:
// Input: s = "aaabaaaa"
// Output: "aabaa"
// Explanation:
// Remove an 'a' from the first group of 'a's to create "aabaaaa".
// Remove two 'a's from the second group of 'a's to create "aabaa".
// No three consecutive characters are equal, so return "aabaa".

// Example 3:
// Input: s = "aab"
// Output: "aab"
// Explanation: No three consecutive characters are equal, so return "aab".

public class Solution
{
    public string MakeFancyString(string str)
    {
        if (str.Length <= 2)
            return str;

        StringBuilder sb = new StringBuilder("", str.Length);
        sb.Append(new char[] { str[0], str[1] });

        for (int ind = 2; ind < str.Length; ind++)
        {
            if (str[ind] != sb[sb.Length - 1] ||
                str[ind] != sb[sb.Length - 2])
            {
                sb.Append(str[ind]);
            }
        }

        return sb.ToString();
    }
}