// https://leetcode.com/problems/island-perimeter

// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Example:

// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]

// Answer: 16

#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
#define KNOWN_CELL 2
 
class Solution {
private:
    unsigned long rowNum, colNum;
 
    bool cell_is_water(int row, int col, vector<vector<int>>& grid, queue<pair<int,int>>& land){
        if (row < 0 || row >= rowNum || col < 0 || col >= colNum || //out of boundaries
            grid[row][col] == 0){ //water found
            return true;
        }
 
        if (grid[row][col] == 1){
            pair<int,int> new_cell(row, col);
            land.push(new_cell);
        }
 
        return false;
    }
 
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int,int>> land;
 
        //find first cell for Land
        rowNum = grid.size();
        colNum = grid[0].size();
        for (int row = 0; row < rowNum; row++){
            bool bfound = false;
            for (int col = 0; col < colNum; col++){
                if (grid[row][col] == 1){
                    pair<int, int> cell(row, col);
                    land.push(cell);
                    bfound = true;
                    break;
                }
            }
            if (bfound) break;
        }
 
        int perimeter = 0;
        //calculate perimeter
        while (!land.empty()){
            pair<int, int> cell = land.front();
            land.pop();
 
            if (grid[cell.first][cell.second] == KNOWN_CELL) continue;
            if (cell_is_water(cell.first - 1, cell.second, grid, land)) perimeter++;
            if (cell_is_water(cell.first + 1, cell.second, grid, land)) perimeter++;
            if (cell_is_water(cell.first, cell.second - 1, grid, land)) perimeter++;
            if (cell_is_water(cell.first, cell.second + 1, grid, land)) perimeter++;
            grid[cell.first][cell.second] = KNOWN_CELL; //known cell
        }
 
        return perimeter;
    }
};