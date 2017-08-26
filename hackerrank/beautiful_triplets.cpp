// https://www.hackerrank.com/challenges/beautiful-triplets?h_r=next-challenge&h_v=zen

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

int main() {
  int n, d, triplets_count;
  triplets_count = 0;

  cin >> n >> d;

  int *arr = new int[n];
  for (int i = 0; i < n; i++){
    int var;
    cin >> var;
    arr[i] = var;
  }

  for (int i = 0; i < n - 2; i++){
    for (int j = i + 1; j < n - 1; j++){
      for (int k = j + 1; k < n; k++){
        if ((arr[j] - arr[i] == d) && (arr[k] - arr[j] == d)){
          triplets_count++;
        }
      }
    }
  }

  cout << triplets_count << endl;
  delete[] arr;

  int fin;
  cin >> fin;
  return 0;
}