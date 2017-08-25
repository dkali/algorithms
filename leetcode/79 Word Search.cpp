// https://leetcode.com/problems/word-search

// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.

#include <iostream>
#include <vector>
 
using namespace std;
 
class Solution {
private:
    int rowNum, colNum;
 
    bool startSearch(vector<vector<char>>& board, int row, int col, const string &word, int pos){
        if (pos == word.size()) return true;
        if (row < 0 || row >= rowNum || col < 0 || col >= colNum) return false;
 
        bool res = false;
 
        if (board[row][col] == word[pos]){
            board[row][col] ^= 333;
 
            res = startSearch(board, row + 1, col, word, pos + 1);
            if (!res) res = startSearch(board, row - 1, col, word, pos + 1);
            if (!res) res = startSearch(board, row, col + 1, word, pos + 1);
            if (!res) res = startSearch(board, row, col - 1, word, pos + 1);
 
            board[row][col] ^= 333;
        }
 
        return res;
    };
 
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0)
            return false;
 
        rowNum = board.size();
        colNum = board[0].size();
 
        for (int row = 0; row < rowNum; row++){
            for (int col = 0; col < colNum; col++){
                if (startSearch(board, row, col, word, 0))
                    return true;
            }
        }
 
        return false;
    }
};