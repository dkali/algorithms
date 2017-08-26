// https://leetcode.com/problems/surrounded-regions

// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// For example,
// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
private:
    vector<vector<char>> *board;
    vector<vector<char>*> *knownCells;
    queue<pair<int,int>*> *cellsToInvestigate;

    void addStartingPoint(int row, int col){
        pair<int,int> *p = new pair<int,int>(row, col);
        cellsToInvestigate->push(p);
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0){
            return;
        }

        knownCells = new vector<vector<char>*>;

        //init helper board
        cellsToInvestigate = new queue<pair<int,int>*>;
        long rowsNum, columnsNum;
        rowsNum = board.size();
        columnsNum = board[0].size();
        for (int i = 0; i < rowsNum; i++){
            vector<char> *v = new vector<char>;
            v->resize(columnsNum);
            knownCells->push_back(v);
        }

        //look for the border-region start points
        for (int line = 0; line < rowsNum; line++){
            if (board[line][0] == 'O'){
                addStartingPoint(line, 0);
            }
            if (board[line][columnsNum-1] == 'O'){
                addStartingPoint(line, columnsNum - 1);
            }
        }

        for (int column = 0; column < columnsNum; column++){
            if (board[0][column] == 'O'){
                addStartingPoint(0, column);
            }
            if (board[rowsNum - 1][column] == 'O'){
                addStartingPoint(rowsNum - 1, column);
            }
        }

        //mark all the regions started from matrix border
        while(!cellsToInvestigate->empty()){
            pair<int,int> *p = cellsToInvestigate->front();
            cellsToInvestigate->pop();

            int row = p->first;
            int column = p->second;

            //lookAround
            if (column - 1 >= 0 && board[row][column - 1] == 'O' && (*(*knownCells)[row])[column - 1] != 'O') {
                addStartingPoint(row, column - 1);
            }

            if (row - 1 >= 0 && board[row - 1][column] == 'O' && (*(*knownCells)[row - 1])[column] != 'O'){
                addStartingPoint(row -1, column);
            }

            if (column + 1 < columnsNum && board[row][column + 1] == 'O' && (*(*knownCells)[row])[column + 1] != 'O'){
                addStartingPoint(row, column + 1);
            }

            if (row + 1 < rowsNum && board[row + 1][column] == 'O' && (*(*knownCells)[row + 1])[column] != 'O'){
                addStartingPoint(row + 1, column);
            }

            (*(*knownCells)[row])[column] = 'O';
            delete p;
        }

        // flip all the 'O' in matrix, if they are not aligh to our known mask of border-regions
        for (int line = 1; line < rowsNum - 1; line++){
            for (int column = 1; column < columnsNum - 1; column++){
                if (board[line][column] == 'O' && (*(*knownCells)[line])[column] != 'O'){
                    board[line][column] = 'X';
                }
            }
        }

        //free allocations
        for (auto it = knownCells->begin(); it != knownCells->end(); ++it){
            delete (*it);
        }
        delete knownCells;
        delete cellsToInvestigate;
    }
};