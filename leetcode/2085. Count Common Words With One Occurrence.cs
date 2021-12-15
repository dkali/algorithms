// https://leetcode.com/problems/count-common-words-with-one-occurrence/

// Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two arrays.

// Example 1:
// Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
// Output: 2
// Explanation:
// - "leetcode" appears exactly once in each of the two arrays. We count this string.
// - "amazing" appears exactly once in each of the two arrays. We count this string.
// - "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
// - "as" appears once in words1, but does not appear in words2. We do not count this string.
// Thus, there are 2 strings that appear exactly once in each of the two arrays.

// Example 2:
// Input: words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
// Output: 0
// Explanation: There are no strings that appear in each of the two arrays.

// Example 3:
// Input: words1 = ["a","ab"], words2 = ["a","a","a","ab"]
// Output: 1
// Explanation: The only string that appears exactly once in each of the two arrays is "ab".
 

// Constraints:
// 1 <= words1.length, words2.length <= 1000
// 1 <= words1[i].length, words2[j].length <= 30
// words1[i] and words2[j] consists only of lowercase English letters.

public class Solution
{
    public int CountWords(string[] words1, string[] words2)
    {
        int count = 0;
        Dictionary<int, int> myDict1 = new Dictionary<int, int>();
        Dictionary<int, int> myDict2 = new Dictionary<int, int>();

        foreach (string word in words1)
        {
            int hsh = word.GetHashCode();
            if (myDict1.ContainsKey(hsh))
            {
                myDict1[hsh]++;
            }
            else
            {
                myDict1[hsh] = 1;
            }
        }

        foreach (string word in words2)
        {
            int hsh = word.GetHashCode();
            if (myDict2.ContainsKey(hsh))
            {
                myDict2[hsh]++;
            }
            else
            {
                myDict2[hsh] = 1;
            }
        }

        foreach (KeyValuePair<int, int> item in myDict1)
        {
            if (item.Value == 1 && myDict2.ContainsKey(item.Key) && myDict2[item.Key] == 1)
            { 
                count++;
            }
        }

        return count;
    }

}