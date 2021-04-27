// https://leetcode.com/problems/subrectangle-queries/

// Implement the class SubrectangleQueries which receives a rows x cols rectangle as a matrix of integers in the constructor and supports two methods:

// 1. updateSubrectangle(int row1, int col1, int row2, int col2, int newValue)

// Updates all values with newValue in the subrectangle whose upper left coordinate is (row1,col1) and bottom right coordinate is (row2,col2).
// 2. getValue(int row, int col)

// Returns the current value of the coordinate (row,col) from the rectangle.


class SubrectangleQueries {
private:
    vector<vector<int>> rect;
    
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int row = row1; row <= row2; row++) {
            for (int col = col1; col <= col2; col++){
                rect[row][col] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return rect[row][col];
    }
};