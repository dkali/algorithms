// https://www.hackerrank.com/challenges/beautiful-binary-string

#include "stdafx.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  // read inout
  int n;
  string str;
  string pattern = "010";

  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    str = str + c;
  }

  // analyze
  string tmp = "";
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == '0') {
      if (str.compare(i, pattern.size(), pattern) == 0){
        str[i + pattern.size() - 1] = '1';
        i = i + pattern.size() - 1;
        count++;
      }
    }
  }

  cout << count;

  return 0;
}