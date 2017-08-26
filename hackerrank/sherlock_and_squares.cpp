//https://www.hackerrank.com/challenges/sherlock-and-squares

#include <stdio.h>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
void check_full_square(int a, int b)
{
  int full_square = 0;
  int r = ceil(sqrt(a));
  while(r*r <= b){
    full_square++;
    r++;
  }
  cout << full_square << endl;
}
 
int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
  string input_str;
  int tests;
  int a, b;
 
  getline(cin, input_str);
  stringstream(input_str) >> tests;
 
  for (int test_num=0; test_num<tests; test_num++)
  {
    cin >> a >> b;
    check_full_square(a, b);
  }
 
  return 0;
}