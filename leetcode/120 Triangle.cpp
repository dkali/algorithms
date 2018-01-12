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
        vector<int> moves_sum(triangle[triangle.size() - 1].size(), INT_MAX);
        moves_sum[0] = triangle[0][0];

        for (long line_index = 1; line_index < triangle.size(); line_index++) {
            for (long i = triangle[line_index].size() - 1; i >= 0; i--) {
                int tmp = INT_MAX;
                if (moves_sum[i] != INT_MAX)
                    tmp = min(tmp, triangle[line_index][i] + moves_sum[i]);
                if (i - 1 >= 0)
                    tmp = min(tmp, triangle[line_index][i] + moves_sum[i - 1]);
                moves_sum[i] = tmp;
            }
        }
        
        int ret = INT_MAX;
        for (int val : moves_sum)
            ret = min(ret, val);
        
        return ret;
    }
};