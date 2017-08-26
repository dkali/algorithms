// https://www.hackerrank.com/challenges/the-grid-search

#include "stdafx.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> read_matrix() {
  int r, c;
  string tmp_str;

  cin >> r >> c;

  vector<string> grid;
  grid.resize(r);
  getline(cin, tmp_str); // avoid linebreak artefact after cin

  for (int row = 0; row < r; row++) {
    getline(cin, grid[row]);
  }

  return grid;
}

bool find_pattern(vector<string> &grid_g, vector<string> &pattern) {
  for (int cur_r = 0; cur_r <= grid_g.size() - pattern.size(); cur_r++) {
    for (int cur_c = 0; cur_c <= grid_g[0].size() - pattern[0].size(); cur_c++) {
      bool match = true;
      int start_r = cur_r, start_c = cur_c;

      for (auto pattern_line = pattern.begin(); pattern_line != pattern.end(); ++pattern_line) {
        if (grid_g[start_r].compare(start_c, (*pattern_line).size(), *pattern_line) != 0) {
          match = false;
          break;
        }
        start_r++;
      }

      if (match) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int t;

  cin >> t;

  while (t-- > 0) {
    // read input
    vector<string> grid_g = read_matrix();
    vector<string> pattern = read_matrix();

    // find pattern appearence
    if (find_pattern(grid_g, pattern)) {
      printf("YES\n");
    }
    else {
      printf("NO\n");
    }
  }
  
  cin >> t;
  return 0;
}