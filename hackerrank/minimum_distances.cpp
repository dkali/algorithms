// https://www.hackerrank.com/challenges/minimum-distances

#include "stdafx.h"

#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

#define INT_MAX 32767;

using namespace std;

void initArray(int** arr, int& size) {
  *arr = new int[size];

  for (int i = 0; i < size; i++) {
    cin >> (*arr)[i];
  }
}

map<int, vector<int>> findFrequencyOfElements(int *arr, int n) {
  map<int, vector<int>> freq;

  for (int i = 0; i < n; i++) {
    if (freq.find(arr[i]) == freq.end()) {
      vector<int> positions;
      positions.push_back(i);
      freq[arr[i]] = positions;
    }
    else {
      freq[arr[i]].push_back(i);
    }
  }

  return freq;
}

int findMinAbs(vector<int> positions) {
  int minDist = INT_MAX;
  for (int i = 1; i < positions.size(); i++) {
    int dist = positions[i] - positions[i - 1];
    if (dist < minDist)
      minDist = dist;
  }

  return minDist;
}

int computeDistance(map<int, vector<int>> freq) {
  int min = -1;

  for (auto it = freq.begin(); it != freq.end(); ++it){
    if (it->second.size() != 1) {
      if (min == -1)
        min = INT_MAX;

      int val = findMinAbs(it->second);
      if (val < min)
        min = val;
    }
  }

  return min;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

  int n;
  cin >> n;

  int *arr;
  initArray(&arr, n);

  map<int, vector<int>> freq = findFrequencyOfElements(arr, n);
  cout << computeDistance(freq);

  delete[] arr;

  int fin;
  cin >> fin;

  return 0;
}