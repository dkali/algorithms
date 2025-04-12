// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

// We repeatedly make k duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

// Example 1:
// Input: s = "abcd", k = 2
// Output: "abcd"
// Explanation: There's nothing to delete.

// Example 2:
// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation: 
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"

// Example 3:
// Input: s = "pbbcggttciiippooaais", k = 2
// Output: "ps"

// Constraints:
// 1 <= s.length <= 105
// 2 <= k <= 104
// s only contains lowercase English letters.

using System.Text;

public class Solution {
    public string RemoveDuplicates(string s, int k) {
        Stack<char> stackChar = new Stack<char>();
        LinkedList<int> dupLen = new LinkedList<int>();

        for (int ind = 0; ind < s.Length; ind++) {
            char curChar = s[ind];
            if (stackChar.Count == 0) {
                stackChar.Push(curChar);
                dupLen.AddLast(1);
                continue;
            }

            if (curChar == stackChar.Peek()) {
                if (dupLen.Last.Value == k - 1) {
                    // pop k-1 elements from the stack
                    for (int i = 0; i < k - 1; i++) {
                        stackChar.Pop();
                    }
                    dupLen.RemoveLast();
                }
                else {
                    stackChar.Push(curChar);
                    dupLen.Last.Value++;
                }
            } else {
                stackChar.Push(curChar);
                dupLen.AddLast(1);
            }
        }

        // pop all elements from the stack
        char[] arr = stackChar.ToArray();
        StringBuilder sb = new StringBuilder("", stackChar.Count);
        for (int i = arr.Length - 1; i >= 0; i--) {
            sb.Append(arr[i]);
        }
        return sb.ToString();
    }
}