// Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

// The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

// Example 1:
// Input: "UD"
// Output: true
// Example 2:
// Input: "LL"
// Output: false

#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int horizont = 0, vertical = 0;
        
        for (char c : moves){
            switch (c){
                case 'R': horizont++; break;
                case 'L': horizont--; break;
                case 'D': vertical--; break;
                case 'U': vertical++; break;
            }
        }
            
        return horizont == 0 && vertical == 0;
    }
};
