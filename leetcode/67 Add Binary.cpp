// https://leetcode.com/problems/add-binary

// Given two binary strings, return their sum (also a binary string).

// For example,
// a = "11"
// b = "1"
// Return "100".

#include <iostream>
#include <algorithm>
 
using namespace std;
 
class Solution {
public:
    string addBinary(string a, string b) {
        int posA, posB, posR;
 
        posA = (int)(a.size() - 1);
        posB = (int)(b.size() - 1);
        int resSize = max(posA, posB);
        posR = resSize;
        string result = "";
        for (int i = 0; i <= posR; i++) result += "0";
        int remnant = 0;
 
        while (posA >= 0 || posB >= 0){
            int tmp = 0;
            if (posA >= 0)
                tmp += a[posA] - '0';
            if (posB >= 0)
                tmp += b[posB] - '0';
            tmp += remnant;
 
            if (tmp == 2){
                result[posR] = '0';
                remnant = 1;
            }
            else if (tmp == 3){
                result[posR] = '1';
                remnant = 1;
            }
            else{
                result[posR] = '0' + tmp;
                remnant = 0;
            }
 
            posA--;
            posB--;
            posR--;
        }
 
        string res;
        if (remnant == 1)
            res = "1";
        else
            res = "";
 
            res += result;
 
        return res;
    }
};