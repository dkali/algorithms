// https://www.hackerrank.com/challenges/anagram

#include "stdafx.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void process_string(string input_str, int size) {
  int dict1[127] = { 0 };
  int dict2[127] = { 0 };

  for (int i = 0; i < size; i++){
    if (i < size / 2) {
      dict1[input_str.at(i)]++;
    }
    else {
      dict2[input_str.at(i)]++;
    }
  }

  int summ = 0;
  for (int i = 64; i < 127; i++) {
    if (dict1[i] != dict2[i]) {
      summ = summ + abs(dict1[i] - dict2[i]);
    }
  }

  cout << summ / 2 << endl;
}

int main() {
  // read inout
  int t;
  string input_str;
  getline(cin, input_str);
  stringstream(input_str) >> t;

  while (t > 0) {
    getline(cin, input_str);
    int sz = input_str.size();
    t--;

    if (sz % 2 != 0) {
      cout << -1 << endl;
      continue;
    }

    process_string(input_str, sz);
  }
  
  int fin;
  cin >> fin;

  return 0;
}


/////////// JAVA version
public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        while(t-- > 0) {
            String a = scan.next();
            if (a.length() % 2 != 0) {
                System.out.println(-1);
                continue;
            }
            int left = 0;
            int right = a.length() - 1;
            List<Character> set = new ArrayList<>();
            while (left < a.length() / 2) {
                set.add(a.charAt(left));
                left++;
            }
            while (right >= a.length() / 2) {
                set.remove(Character.valueOf(a.charAt(right)));
                right--;
            }
            System.out.println(set.size());
        }
    }