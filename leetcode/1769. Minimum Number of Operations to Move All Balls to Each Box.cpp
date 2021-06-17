// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/submissions/

// You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box is empty, and '1' if it contains one ball.

// In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may be more than one ball in some boxes.

// Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the balls to the ith box.

// Each answer[i] is calculated considering the initial state of the boxes.

 

// Example 1:
// Input: boxes = "110"
// Output: [1,1,3]
// Explanation: The answer for each box is as follows:
// 1) First box: you will have to move one ball from the second box to the first box in one operation.
// 2) Second box: you will have to move one ball from the first box to the second box in one operation.
// 3) Third box: you will have to move one ball from the first box to the third box in two operations, and move one ball from the second box to the third box in one operation.

// Example 2:
// Input: boxes = "001011"
// Output: [11,8,5,4,3,4]

// Constraints:
// n == boxes.length
// 1 <= n <= 2000
// boxes[i] is either '0' or '1'.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> result, summ;
        vector<int> left_to_right = {0}, right_to_left = {0};
        
        // first we go from left to right
        summ.push_back(boxes[0] - '0');
        // count summ of current and all previos one's for every cell
        for (int ind = 1; ind < boxes.size(); ind++) {
            summ.push_back(summ[ind - 1] + (boxes[ind] - '0'));
        }
        // count movements needed to shift the ones to every cell
        for (int ind = 1; ind < boxes.size(); ind++) {
            left_to_right.push_back(left_to_right[ind - 1] + summ[ind - 1]);
        }
        
        // no repeat from right to left
        summ.clear();
        summ.push_back(boxes[boxes.size() - 1] - '0');
        for (long ind = boxes.size() - 2; ind >= 0; ind--) {
            summ.push_back(summ.back() + (boxes[ind] - '0'));
        }
        // resulted summ needs to be reversed for straight calculations
        reverse(summ.begin(), summ.end());
        for (long ind = boxes.size() - 2; ind >= 0; ind--) {
            right_to_left.push_back(summ[ind + 1] + right_to_left.back());
        }
        // resulted right_to_left needs to be reversed for straight calculations
        reverse(right_to_left.begin(), right_to_left.end());
        
        //calculate movements for every cell
        for (int ind = 0; ind < boxes.size(); ind++) {
            result.push_back(left_to_right[ind] + right_to_left[ind]);
        }
        
        return result;
    }
};