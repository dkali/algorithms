// https://www.hackerrank.com/challenges/manasa-and-stones?h_r=next-challenge&h_v=zen

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  int test_num = 0;
  cin >> test_num;

  for (int test = 0; test < test_num; test++){
    int numbers_amount, a, b;
    cin >> numbers_amount;
    cin >> a;
    cin >> b;

    if (a > b){
      a = a + b;
      b = a - b;
      a = a - b;
    }

    if (a == b)
      printf("%d", a*(numbers_amount - 1));
    else
      for (int i=0; i < numbers_amount; i++){
        printf("%d ", b*i + a*(numbers_amount - i - 1));
      }
    printf("\n");
  }

  int fin;
  cin >> fin;
  return 0;
}