// https://leetcode.com/problems/push-dominoes/submissions/

// There are N dominoes in a line, and we place each domino vertically upright.
// In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

// After each second, each domino that is falling to the left pushes the adjacent domino on the left.
// Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
// When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
// For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
// Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not been pushed.
// Return a string representing the final state. 

// Example 1:
// Input: ".L.R...LR..L.."
// Output: "LL.RR.LLRRLL.."

// Example 2:
// Input: "RR.L"
// Output: "RR.L"

// Explanation: The first domino expends no additional force on the second domino.
// Note:
// 0 <= N <= 10^5
// String dominoes contains only 'L', 'R' and '.'

#include <iostream>
#include <string>
#include <queue>

#define Right 'R'
#define Left 'L'
#define FallingLeft 'l'
#define FallingRight 'r'
#define Still 's'
#define Initial '.'

using namespace std;

class Solution {
private:
    long str_size;
    
    void apply_force_left(string &dominoes, queue<int> &active_cells, int cell_id) {
        if (cell_id - 1 >= 0) {
            if (dominoes[cell_id - 1] == Initial) {
                dominoes[cell_id - 1] = FallingLeft;
                active_cells.push(cell_id - 1);
            }
            if (dominoes[cell_id - 1] == FallingRight)
                dominoes[cell_id - 1] = Still;
        }
    }
    
    void apply_force_right(string &dominoes, queue<int> &active_cells, int cell_id) {
        if (cell_id + 1 < str_size) {
            if (dominoes[cell_id + 1] == Initial) {
                dominoes[cell_id + 1] = FallingRight;
                active_cells.push(cell_id + 1);
            }
        }
    }
    
public:
    string pushDominoes(string dominoes) {
        queue<int> active_cells;
        str_size = dominoes.size();
        
        // init queue
        for (int i = 0; i < str_size; i++) {
            if (dominoes[i] == Right)
                active_cells.push(i);
            if (dominoes[i] == Left)
                active_cells.push(i);
        }
        
        while (!active_cells.empty()) {
            int cell_id = active_cells.front();
            active_cells.pop();
            
            switch (dominoes[cell_id]) {
                case Left:
                    apply_force_left(dominoes, active_cells, cell_id);
                    break;
                    
                case Right:
                    apply_force_right(dominoes, active_cells, cell_id);
                    break;
                    
                case FallingLeft:
                    dominoes[cell_id] = Left;
                    apply_force_left(dominoes, active_cells, cell_id);
                    break;
                    
                case FallingRight:
                    dominoes[cell_id] = Right;
                    apply_force_right(dominoes, active_cells, cell_id);
                    break;
            }
        }
        
        //restore string
        for (int i = 0; i < dominoes.length(); i++) {
            if (dominoes[i] == Still)
                dominoes[i] = Initial;
        }
        
        return dominoes;
    }
};
