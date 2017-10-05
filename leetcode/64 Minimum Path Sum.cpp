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

        //init
        int **helper = new int* [m];
        for (int i = 0; i < m; i++) helper[i] = new int[n];

        //calculate
        for (int row = 0; row < m; row++) {
            int prev = row - 1 >= 0 ? helper[row - 1][0] : 0;
            helper[row][0] = grid[row][0] + prev;
        }
        for (int line = 0; line < n; line++) {
            int prev = line - 1 >= 0 ? helper[0][line - 1] : 0;
            helper[0][line] = grid[0][line] + prev;
        }
        for (int row = 1; row < m; row++){
            for (int col = 1; col < n; col++){
                int tmp = grid[row][col] + min(helper[row][col - 1], helper[row - 1][col]);
                helper[row][col] = tmp;
            }
        }

        int res = helper[m-1][n-1];
        //destroy
        for (int i = 0; i < m; i++) delete[] helper[i];
        delete[] helper;

        return res;
    }
};
