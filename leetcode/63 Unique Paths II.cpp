// https://leetcode.com/problems/unique-paths-ii

// Follow up for "Unique Paths":

// Now consider if some obstacles are added to the grids. How many unique paths would there be?

// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// For example,
// There is one obstacle in the middle of a 3x3 grid as illustrated below.

// [
//   [0,0,0],
//   [0,1,0],
//   [0,0,0]
// ]
// The total number of unique paths is 2.

// Note: m and n will be at most 100.

#include <iostream>
#include <vector>
 
using namespace std;
 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int result = 0;
        int m, n;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
 
        //create helper
        int **ptrArray = new int*[m];
        for (int i = 0; i < m; i++){
            ptrArray[i] = new int[n];
        }
 
        //init helper
        bool bFoundObstacle = false;
        for (int row = 0; row < m; row++){
            if (obstacleGrid[row][0] == 1)
                bFoundObstacle = true;
            ptrArray[row][0] = bFoundObstacle ? 0 : 1;
        }
        bFoundObstacle = false;
        for (int col = 0; col < n; col++){
            if (obstacleGrid[0][col] == 1)
                bFoundObstacle = true;
            ptrArray[0][col] = bFoundObstacle ? 0 : 1;
        }
 
        //perform calculation
        for (int row = 1; row < m; row++){
            for (int col = 1; col < n; col++){
                if (obstacleGrid[row][col] == 1){
                    ptrArray[row][col] = 0;
                }
                else{
                    int leftCell = 0, upCell = 0;
                    if (col - 1 >= 0){
                        leftCell = obstacleGrid[row][col - 1] == 1 ? 0 : ptrArray[row][col - 1];
                    }
                    if (row - 1 >= 0){
                        upCell = obstacleGrid[row - 1][col] == 1 ? 0 : ptrArray[row - 1][col];
                    }
                    ptrArray[row][col] = leftCell + upCell;
                }
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