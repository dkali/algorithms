// https://www.hackerrank.com/challenges/missing-numbers

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAX_VALUE 10000

void init_array(int &size, int array[]){
  string input_str;
  getline(cin, input_str);
  stringstream(input_str) >> size;

  string myline;
  getline(cin, myline);
  char *cstr = new char[myline.length()+1];
  strcpy(cstr, myline.c_str());

  char *pch = nullptr;
  pch = strtok(cstr, " ");
  while (pch != NULL){
    int digit;
    stringstream(pch) >> digit;
    array[digit]++;
    pch = strtok(NULL, " ");
  }

  delete[] cstr;
}

/*
void init_array(int &size, int array[]) {
	cin >> size;

	for (int i = 0; i < size; i++) {
		int val;
		cin >> val;
		array[val]++;
	}
}*/

int main () {
  int n, m;
  int indexing_n[MAX_VALUE] = {};
  int indexing_m[MAX_VALUE] = {};

  // input
  init_array(n, indexing_n);
  init_array(m, indexing_m);

  for (int i = 0; i < MAX_VALUE; i++){
    if (indexing_m[i] != indexing_n[i]){
      // print missed
      cout << i << " ";
    }
  }

  int fin;
  cin >> fin;
  return 0;
}