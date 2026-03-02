// Given an integer x, return true if x is a palindrome, and false otherwise.

// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

// Example 2:
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

// Example 3:
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 
// Constraints:
// -231 <= x <= 231 - 1

package task9

class Solution {
    fun isPalindrome(x: Int): Boolean {
        if (x < 0) return false
        if (x < 10) return true

        val deque = ArrayDeque<Char>()
        val str = x.toString()
        val centerIndex: Int = str.length / 2
        val evenLength = str.length % 2 == 0

        for (i in 0..<str.length) {
            if (i < centerIndex) {
                deque.addLast(str[i])
            }
            if (i > centerIndex || (i == centerIndex && evenLength)) {
                val digit = deque.removeLast()
                if (digit != str[i]) {
                    return false
                }
            }
        }
        return true
    }
}