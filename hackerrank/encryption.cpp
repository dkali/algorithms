// https://www.hackerrank.com/challenges/encryption

#include "stdafx.h"

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

void calculate_boundaries(int &rows, int &columns, int len) {
  float sq = sqrt(len);
  rows = floor(sq);
  columns = ceil(sq);

  while (rows * columns < len) {
    rows++;
  }
}

int main() {
  string input_str;
  getline(cin, input_str);

  int rows = 0, columns = 0;
  calculate_boundaries(rows, columns, input_str.length());

  //construct matrix
  vector<char> *matrix = new vector<char>[rows];
  int row = 0, column = 0;
  for (char c : input_str) {
    matrix[row].push_back(c);
    column++;

    if (column >= columns) {
      column = 0;
      row++;
    }
  }

  //encode message
  input_str = "";
  for (int column = 0; column < columns; column++) {
    for (int row = 0; row < rows; row++) {
      if (matrix[row].size() > column) {
        input_str = input_str + matrix[row][column];
      }
    }
    input_str = input_str + " ";
  }

  cout << input_str << endl;

  //free data
  delete[] matrix;

  int fin;
  cin >> fin;

  return 0;
}