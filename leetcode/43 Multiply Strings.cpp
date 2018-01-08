// https://leetcode.com/problems/multiply-strings/description/

// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

// Note:

// The length of both num1 and num2 is < 110.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        vector<queue<int>> layers;
        
        //perform calculations
        long offset = 0;
        for (long i = num1.size() - 1; i >= 0; i--) {
            offset = num1.size() - 1 - i;
            queue<int> product;
            
            while (offset-- > 0) product.push(0);
            
            int d1 = num1[i] - '0';
            int residue = 0;
            for (long j = num2.size() - 1; j >= 0; j--) {
                int prod = d1 * (num2[j] - '0') + residue;
                if (prod > 9) {
                    product.push(prod % 10);
                    residue = prod / 10;
                }
                else {
                    product.push(prod);
                    residue = 0;
                }
            }
            
            if (residue != 0)
                product.push(residue);
            
            layers.push_back(product);
        }
        
        //construct resulting string
        bool go_on = true;
        int residue = 0;
        while (go_on) {
            int summ = 0;
            go_on = false;
            for (int ind = 0; ind < layers.size(); ind++) {
                if (!layers[ind].empty()) {
                    summ += layers[ind].front();
                    layers[ind].pop();
                    go_on = true;
                }
            }
            summ += residue;
            
            if (!go_on) break;
            
            if (summ > 9) {
                res = char('0' + summ % 10) + res;
                residue = summ / 10;
            }
            else{
                res = char('0' + summ) + res;
                residue = 0;
            }
        }
        
        if (residue != 0)
            res = char('0' + residue) + res;
        while (res[0] == '0' && res.size() > 1)
            res.erase(0, 1);
        return res;
    }
};