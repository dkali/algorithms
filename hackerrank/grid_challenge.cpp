// https://www.hackerrank.com/challenges/grid-challenge

#include "stdafx.h"

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

class Testcase{
private:
  char **m_matrix;
  int m_dimension;

  // test
  void print_matrix() {
    for (int l = 0; l < m_dimension; l++) {
      for (int c = 0; c < m_dimension; c++) {
        cout << m_matrix[l][c] << " ";
      }
      cout << endl;
    }
  }

  void sort_line(char arr[], int sz) {
    for (int cycle = 0; cycle < sz - 1; cycle++) {
      bool bsorted = true;
      for (int pos = 0; pos < sz - 1; pos++) {
        if (arr[pos] > arr[pos + 1]) {
          char tmp = arr[pos];
          arr[pos] = arr[pos + 1];
          arr[pos + 1] = tmp;
          bsorted = false;
        }
      }

      if (bsorted == true)
        break;
    }
  }

public:
  Testcase(int dim) {
    m_dimension = dim;
    m_matrix = new char*[m_dimension];
    for (int i = 0; i < m_dimension; i++) {
      m_matrix[i] = new char[m_dimension]();
    }
  }

  ~Testcase() {
    // free data
    for (int i = 0; i < m_dimension; i++) {
      delete[] m_matrix[i];
    }
    delete[] m_matrix;
  }

  bool run() {
    string temp_str;

    // read input
    for (int i = 0; i < m_dimension; i++) {
      getline(cin, temp_str);
      memcpy(m_matrix[i], temp_str.c_str(), sizeof(char)*m_dimension);
    }

    // sort
    for (int line = 0; line < m_dimension; line++) {
      sort_line(m_matrix[line], m_dimension);

      if (line == 0)
        continue;

      for (int pos = 0; pos < m_dimension; pos++) {
        if (m_matrix[line][pos] < m_matrix[line - 1][pos])
          return false;
      }
    }

    //print_matrix();
    return true;
  }
};

int main() {
  int num_tests;
  string temp_str;

  getline(cin, temp_str);
  stringstream(temp_str) >> num_tests;

  while (num_tests--) {
    // read input
    int dim;
    getline(cin, temp_str);
    stringstream(temp_str) >> dim;

    Testcase t(dim);
    if (t.run() == true)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  int fin;
  cin >> fin;

  return 0;
}