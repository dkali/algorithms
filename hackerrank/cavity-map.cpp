// https://www.hackerrank.com/challenges/cavity-map

#include "stdafx.h"

#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  int n;
  string input_str;
  getline(cin, input_str);
  stringstream(input_str) >> n;

  //init
  string *arr;
  arr = new string [n];
  
  //read input
  for (int line = 0; line < n; line++) {
    getline(cin, arr[line]);
  }

  //process matrix
  for (int line = 1; line < n - 1; line++) {
    for (int column = 1; column < n - 1; column++) {
      char tmp = arr[line][column];
      if (arr[line-1][column] == 'X' ||
          arr[line+1][column] == 'X' ||
          arr[line][column-1] == 'X' ||
          arr[line][column+1] == 'X') {
        continue;
      }

      if (arr[line][column] > arr[line - 1][column] &&
          arr[line][column] > arr[line + 1][column] &&
          arr[line][column] > arr[line][column - 1] &&
          arr[line][column] > arr[line][column + 1]) {
        arr[line][column] = 'X';
      }
    }
  }

  //print
  for (int line = 0; line < n; line++) {
    for (int column = 0; column < n; column++) {
      cout << arr[line][column];
    }
    cout << endl;
  }

  //free
  delete[] arr;

  int fin;
  cin >> fin;

  return 0;
}