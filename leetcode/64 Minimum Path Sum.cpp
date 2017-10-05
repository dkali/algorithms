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

        helper[0] = 0;
        for (int row = 0; row < m; row++){
            helper[0] += grid[row][0];
            for (int col = 1; col < n; col++){
                if (row == 0)
                    helper[col] = grid[row][col] + helper[col - 1];
                else
                    helper[col] = grid[row][col] + min(helper[col - 1], helper[col]);
            }
        }

        int res = helper[n-1];
        delete[] helper;

        return res;
    }
};
