// https://leetcode.com/problems/pascals-triangle

// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

#include "stdafx.h"

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>


//===================V1============================
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    triangle.resize(numRows);
    vector<int> line;

    if (numRows == 0)
      return triangle;

    line.push_back(1);
    triangle[0] = line;

    if (numRows == 1)
      return triangle;

    int prev_size = 1;
    for (int line_ind = 1; line_ind < numRows; line_ind++) {
      line.clear();

      // calculate line length
      vector<int> prev_line = triangle[line_ind - 1];
      int line_len = ++prev_size;
      line.resize(line_len);
      int half_len = floor(((float)line_len) / 2 + 0.5);

      // form first half of the line
      int index = 0;
      line[index++] = 1;
      for (int i = 1; i < half_len; i++) {
        int val = prev_line[i - 1];
        if (line_ind != 1) {
          val = val + prev_line[i];
        }
        line[index++] = val;
      }

      // copy the rest of the line
      bool parity = ((line_ind & 1) == 0);
      for (int i = (parity ? half_len - 2 : half_len - 1); i >= 0; i--) {
        line[index++] = line[i];
      }

      triangle[line_ind] = line;
    }

    return triangle;
  }
};

//===================V2============================
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    while (numRows-- > 0) {
      if (result.empty()) {
        vector<int> array;
        array.push_back(1);
        result.push_back(array);
        continue;
      }

      vector<int> previous = result[result.size() - 1];
      vector<int> current;
      current.push_back(1);
      for (int i = 1; i < previous.size(); i++) {
        current.push_back(previous[i - 1] + previous[i]);
      }
      current.push_back(1);
      result.push_back(current);
    }

    return result;
  }
};