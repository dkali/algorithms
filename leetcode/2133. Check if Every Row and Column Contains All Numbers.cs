// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers/

// An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).
// Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

// Example 1:
// Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
// Output: true
// Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
// Hence, we return true.

// Example 2:
// Input: matrix = [[1,1,1],[1,2,3],[1,2,3]]
// Output: false
// Explanation: In this case, n = 3, but the first row and the first column do not contain the numbers 2 or 3.
// Hence, we return false.
 
// Constraints:
// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// 1 <= matrix[i][j] <= n

public class Solution
{
    public bool CheckValid(int[][] matrix)
    {
        int len = matrix.Length;

        for (int line = 0; line < len; line++)
        {
            HashSet<int> hst = new HashSet<int>();
            for (int col = 0; col < len; col++)
            {
                if (matrix[line][col] <= 0 || matrix[line][col] > len)
                    return false;

                if (hst.Add(matrix[line][col]) == false)
                    return false;
            }
        }

        for (int col = 0; col < len; col++)
        {
            HashSet<int> hst = new HashSet<int>();
            for (int line = 0; line < len; line++)
            {
                if (matrix[line][col] <= 0 || matrix[line][col] > len)
                    return false;

                if (hst.Add(matrix[line][col]) == false)
                    return false;
            }
        }

        return true;
    }
}