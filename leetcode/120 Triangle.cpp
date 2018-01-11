// https://leetcode.com/problems/triangle/description/
// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> *prev_line = new vector<int>(triangle[0]), *cur_line = nullptr;
        
        for (int line_index = 1; line_index < triangle.size(); line_index++) {
            cur_line = new vector<int>();
            cur_line->resize(triangle[line_index].size());
            
            for (int i = 0; i < cur_line->size(); i++) {
                cur_line->at(i) = INT_MAX;
                if (i - 1 >= 0)
                    cur_line->at(i) = min(prev_line->at(i - 1) + triangle[line_index][i], cur_line->at(i));
                if (i < prev_line->size())
                    cur_line->at(i) = min(prev_line->at(i) + triangle[line_index][i], cur_line->at(i));
            }
            
            delete prev_line;
            prev_line = cur_line;
        }
        
        int ret = INT_MAX;
        for (int val : *prev_line)
            ret = min(ret, val);
        delete cur_line;
        
        return ret;
    }
};
