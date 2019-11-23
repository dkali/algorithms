// Given n and m which are the dimensions of a matrix initialized by zeros and given an array indices where indices[i] = [ri, ci]. For each pair of [ri, ci] you have to increment all cells in row ri and column ci by 1.
// Return the number of cells with odd values in the matrix after applying the increment to all indices. 

// Example 1:
// [0,0,0] -> [1,2,1] -> [1,3,1]
// [0,0,0]    [0,1,0]    [1,3,1]
// Input: n = 2, m = 3, indices = [[0,1],[1,1]]
// Output: 6
// Explanation: Initial matrix = [[0,0,0],[0,0,0]].
// After applying first increment it becomes [[1,2,1],[0,1,0]].
// The final matrix will be [[1,3,1],[1,3,1]] which contains 6 odd numbers.

// Example 2:
// [0,0] -> [0,1] -> [2,2]
// [0,0]    [1,2]    [2,2]
// Input: n = 2, m = 2, indices = [[1,1],[0,0]]
// Output: 0
// Explanation: Final matrix = [[2,2],[2,2]]. There is no odd number in the final matrix.
 
// Constraints:
// 1 <= n <= 50
// 1 <= m <= 50
// 1 <= indices.length <= 100
// 0 <= indices[i][0] < n
// 0 <= indices[i][1] < m

#include <iostream>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

class Solution {
public:
    long oddCells(int n, int m, vector<vector<int>>& indices) {
        set<int> cells;
        int len = calculate_length(m);
        
        for (vector<int> index : indices) {
            // set row
            for (int row = 0; row < n; row++) {
                int id = build_id(row, index[1], len);
                update_cell_value(cells, id);
            }

            // set column
            for (int column = 0; column < m; column++) {
                int id = build_id(index[0], column, len);
                update_cell_value(cells, id);
            }
        }
        
        return cells.size();
    }
    
private:
    void update_cell_value(set<int> &cells, int id) {
        if (cells.find(id) == cells.end())
            cells.insert(id);
        else
            cells.erase(cells.find(id));
    }
    
    int build_id(int n, int m, int len) {
        return n * pow(10, len) + m;
    }
    
    int calculate_length(int n) {
        int len = 0;
        while (n > 0) {
            len++;
            n /= 10;
        }
        return len;
    }
};