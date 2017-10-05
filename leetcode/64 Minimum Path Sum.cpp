// https://leetcode.com/problems/minimum-path-sum/description/

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int *helper = new int[n];

        helper[0] = grid[0][0];
        for (int line = 1; line < n; line++) {
            helper[line] = grid[0][line] + helper[line - 1];
        }

        for (int row = 1; row < m; row++){
            for (int col = 0; col < n; col++){
                helper[col] = grid[row][col] + (col - 1 >= 0 ? min(helper[col - 1], helper[col]) : helper[col]);
            }
        }

        int res = helper[n-1];
        delete[] helper;

        return res;
    }
};
