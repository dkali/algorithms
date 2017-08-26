// https://www.hackerrank.com/challenges/connected-cell-in-a-grid

#include "stdafx.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define CELL_EXIST(row, col) ((row >= 0) && (row < rows_num) && (col >= 0) && (col < columns_num))
#define CHECK_CELL(row, col) (matrix[row][col].visited == false && matrix[row][col].value == 1)

class Node {
public:
  bool visited;
  int value, row, col;
  Node() {
    visited = false;
  }
};

int main() {
  int rows_num, columns_num;

  //read input
  cin >> rows_num;
  cin >> columns_num;

  vector<vector<Node>> matrix;
  for (int r = 0; r < rows_num; r++) {
    vector<Node> line;
    line.resize(columns_num);
    for (int c = 0; c < columns_num; c++) {
      Node node;
      node.row = r;
      node.col = c;
      cin >> node.value;
      line[c] = node;
    }

    matrix.push_back(line);
  }
  
  //do some magic
  int max_region_size = 0;

  for (int row = 0; row < rows_num; row++) {
    for (int col = 0; col < columns_num; col++) {
      Node node = matrix[row][col];
      if (node.visited == false && node.value == 1) {
        matrix[row][col].visited = true;
        int connected_cells = 1;
        stack<Node> st;

        st.push(node);

        auto look_at = [&connected_cells, &st, &matrix, &rows_num, &columns_num](int r, int c) {
          if (CELL_EXIST(r, c)) {
            if (CHECK_CELL(r, c)) {
              connected_cells++;
              st.push(matrix[r][c]);
            }
            matrix[r][c].visited = true;
          }
        };

        while (!st.empty()) {
          node = st.top();
          st.pop();

          //look around
          look_at(node.row - 1, node.col - 1);
          look_at(node.row - 1, node.col);
          look_at(node.row - 1, node.col + 1);
          look_at(node.row, node.col - 1);
          look_at(node.row, node.col + 1);
          look_at(node.row + 1, node.col - 1);
          look_at(node.row + 1, node.col);
          look_at(node.row + 1, node.col + 1);
        }

        if (max_region_size < connected_cells)
          max_region_size = connected_cells;
      }
    }
  }

  cout << max_region_size << endl;

  cin >> rows_num;
  return 0;
}