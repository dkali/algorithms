// https://leetcode.com/problems/solve-the-equation/description/

// Solve a given equation and return the value of x in the form of string "x=#value". The equation contains only '+', '-' operation, the variable x and its coefficient.

// If there is no solution for the equation, return "No solution".

// If there are infinite solutions for the equation, return "Infinite solutions".

// If there is exactly one solution for the equation, we ensure that the value of x is an integer.

// Example 1:
// Input: "x+5-3+x=6+x-2"
// Output: "x=2"

// Example 2:
// Input: "x=x"
// Output: "Infinite solutions"

// Example 3:
// Input: "2x=x"
// Output: "x=0"

// Example 4:
// Input: "2x+3x-6x=x+2"
// Output: "x=-1"

// Example 5:
// Input: "x=x+2"
// Output: "No solution"

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int dval = 0;
        int xval = 0;

        int sign = 1;
        int op = 1;
        string digit = "";
        for (int i = 0; i < equation.size(); i++){
            char c = equation[i];
            if (c >= '0' && c <= '9'){
                digit += c;
            }
            else if (c == 'x'){
                if (digit == "")
                    digit = "1";
                xval += stoi(digit.c_str(), 0, 10) * sign * op;
                digit = "";
            }
            else if (c != '='){
                if (digit != ""){
                    dval += stoi(digit.c_str(), 0, 10) * sign * op;
                    digit = "";
                }
                if (c == '-')
                    op = -1;
                else
                    op = 1;
            }
            else if (c == '='){
                if (digit != ""){
                    dval += stoi(digit.c_str(), 0, 10) * sign * op;
                    digit = "";
                }
                sign = -1;
                op = 1;
            }
        }
        if (equation[equation.size()-1] != 'x')
            dval += stoi(digit.c_str(), 0, 10) * sign * op;

        //form results
        if (xval == 0 && dval != 0)
            return "No solution";
        else if (xval == 0 && dval == 0)
            return "Infinite solutions";
        else{
            string res = "x=";
            res += to_string(-1*dval/xval);
            return res;
        }
    }
};