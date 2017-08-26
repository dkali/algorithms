// https://www.hackerrank.com/challenges/caesar-cipher-1

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;
char shift_char(char c, int offset);
char encrypt_char(char c, int offset, char min, char max);

char shift_char(char c, int offset){
  char min, max;

  while (offset >= 26)
    offset = offset - 26;

  while (offset <= -26)
    offset = offset + 26;

  min = 'a';
  max = 'z';
  c = encrypt_char(c, offset, min, max);

  min = 'A';
  max = 'Z';
  c = encrypt_char(c, offset, min, max);

  return c;
}

char encrypt_char(char c, int offset, char min, char max){
  if (c >= min && c <= max){
    if (c + offset > max) 
      c = min + (offset - (max - c)) - 1;
    else if (c + offset < min)
      c = max + (offset + (c - min)) + 1;
    else
      c = c + offset;
  }
  return c;
}

int main() {
  int n, key;
  string input_str, source;
  
  getline(cin, input_str);
  stringstream(input_str) >> n;
  getline(cin, input_str);
  source = input_str;
  getline(cin, input_str);
  stringstream(input_str) >> key;

  for (char c : source){
    cout << shift_char(c, key);
  }

  // int fin;
  // cin >> fin;
  return 0;
}