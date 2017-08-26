https://www.hackerrank.com/challenges/maximizing-xor/submissions/code/39052415

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int l, r;
  cin >> l >> r;
  
  int max = 0;
  for (int a = l; a < r; a++){
    for (int b = l+1; b <= r; b++){
      int x = a^b;
      if (x > max)
        max = x;
    }
  }
  
  cout << max << endl;
  
  return 0;
}

///////////////////

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
 
public class Solution {
/*
 * Complete the function below.
 */
 
    static int maxXor(int l, int r) {
        int result = 0;
        for (int i = r; i >= l; i--) {
            int temp = i ^ r;
            if (result < temp) {
                result = temp;
            }
            temp = i ^ l;
            if (result < temp) {
                result = temp;
            }
        }
        return result;
    }
 
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int res;
        int _l;
        _l = Integer.parseInt(in.nextLine());
       
        int _r;
        _r = Integer.parseInt(in.nextLine());
       
        res = maxXor(_l, _r);
        System.out.println(res);
       
    }
}