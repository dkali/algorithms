#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void check_for_prime(int var) {
  if (var == 0 || var == 1) {
    cout << "Not prime" << endl;
    return;
  }

  if (var == 2) {
    cout << "Prime" << endl;
    return;
  }

  if (var % 2 == 0) {
    cout << "Not prime" << endl;
    return;
  }

  bool bIsPrime = true;
  for (int i = 3; i <= ceil(sqrt(var)); i++) {
    if (var % i == 0)
      bIsPrime = false;
  }

  if (bIsPrime == false)
    cout << "Not prime" << endl;
  else
    cout << "Prime" << endl;
}

int main() {
  int n;
  cin >> n;

  while (n > 0) {
    int var;
    cin >> var;
    check_for_prime(var);
    n--;
  }

  return 0;
}