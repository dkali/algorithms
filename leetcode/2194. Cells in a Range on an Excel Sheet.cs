// https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/description/

// A cell (r, c) of an excel sheet is represented as a string "<col><row>" where:

// <col> denotes the column number c of the cell. It is represented by alphabetical letters.
// For example, the 1st column is denoted by 'A', the 2nd by 'B', the 3rd by 'C', and so on.
// <row> is the row number r of the cell. The rth row is represented by the integer r.
// You are given a string s in the format "<col1><row1>:<col2><row2>", where <col1> represents the column c1, <row1> represents the row r1, <col2> represents the column c2, and <row2> represents the row r2, such that r1 <= r2 and c1 <= c2.

// Return the list of cells (x, y) such that r1 <= x <= r2 and c1 <= y <= c2. The cells should be represented as strings in the format mentioned above and be sorted in non-decreasing order first by columns and then by rows.

// Example 1:
// Input: s = "K1:L2"
// Output: ["K1","K2","L1","L2"]

// Example 2:
// Input: s = "A1:F1"
// Output: ["A1","B1","C1","D1","E1","F1"]

// Constraints:
// s.length == 5
// 'A' <= s[0] <= s[3] <= 'Z'
// '1' <= s[1] <= s[4] <= '9'
// s consists of uppercase English letters, digits and ':'.

public class Solution
{
    public IList<string> CellsInRange(string input)
    {
        IList<string> ret = new List<string>();
        char c1 = input[0];
        char c2 = input[3];
        char r1 = input[1];
        char r2 = input[4];

        while (c1 <= c2)
        {
            char current_row = r1;
            while (current_row <= r2)
            {
                ret.Add($"{c1}{current_row}");
                current_row++;
            }
            c1++;
        }

        return ret;
    }
}