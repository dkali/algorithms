// https://www.hackerrank.com/challenges/pairs

#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int main() {
  long n, k;
  cin >> n >> k;

  map<long, int> digits;

  for (int i = 0; i < n; i++){
    long tmp;
    cin >> tmp;
    digits[tmp] = 1;
  }

  int pairs = 0;
  for (auto it = digits.begin(); it != digits.end(); ++it){
    long key = it->first;
    try {
      if (digits.at(key + k) == 1)
        pairs++;
    }
    catch(const std::out_of_range& e){
      printf("key %d is out of range\n", key + k);
    }
  }

  cout << pairs << endl;

  return 0;
}