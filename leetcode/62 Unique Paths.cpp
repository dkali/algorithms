// https://leetcode.com/problems/unique-paths

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

// How many possible unique paths are there?

// s . . . . . .
// . . . . . . .
// . . . . . . f

// Above is a 3 x 7 grid. How many possible unique paths are there?

// Note: m and n will be at most 100.

#include <iostream>
 
using namespace std;
 
class Solution {
public:
    int uniquePaths(int m, int n) {
        int result = 0;
 
        //create helper
        int **ptrArray = new int*[m];
        for (int i = 0; i < m; i++){
            ptrArray[i] = new int[n];
        }
 
        //init helper
        for (int row = 0; row < m; row++){
            ptrArray[row][0] = 1;
        }
        for (int col = 0; col < n; col++){
            ptrArray[0][col] = 1;
        }
 
        //perform calculation
        for (int row = 1; row < m; row++){
            for (int col = 1; col < n; col++){
                ptrArray[row][col] = ptrArray[row][col - 1] + ptrArray[row - 1][col];
            }
        }
 
        result = ptrArray[m - 1][n - 1];
 
        //destroy helper
        for (int i = 0; i < m; i++){
            delete[] ptrArray[i];
        }
        delete[] ptrArray;
 
        return result;
    }
};