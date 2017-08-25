
// https://leetcode.com/problems/basic-calculator-ii

// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

// You may assume that the given expression is always valid.

// Some examples:
// "3+2*2" = 7
// " 3/2 " = 1
// " 3+5 / 2 " = 5
// Note: Do not use the eval built-in library function.
 
#include <iostream>
#include <string>
#include <stack>
 
using namespace std;
 
class Solution {
private:
    int build_digit(string &str, int &pos){
        int start_pos = pos;
        int len = 1;
 
        while (pos + 1 < str.size() && str[pos + 1] >= '0' && str[pos + 1] <= '9'){
            len++;
            pos++;
        }
 
        string tmp = string(str, start_pos, len);
        return stoi(tmp);
    }
 
public:
    int calculate(string str) {
        int res = 0;
        stack<int> st;
 
        int sign = 1;
        int digit = 0;
        for (int pos = 0; pos < str.size(); pos++){
            char ch = str[pos];
            if (ch == ' ' || ch == '+') continue;
 
            switch (ch){
                case '-':
                    sign = -1;
                    break;
 
                case '*':
                    digit = build_digit(str, ++pos);
                    digit *= sign * st.top();
                    st.pop();
                    st.push(digit);
                    sign = 1;
                    break;
 
                case '/':
                    digit = build_digit(str, ++pos);
                    digit = sign * st.top() / digit;
                    st.pop();
                    st.push(digit);
                    sign = 1;
                    break;
 
                default:
                    digit = build_digit(str, pos);
                    digit *= sign;
                    st.push(digit);
                    sign = 1;
                    break;
            }
        }
 
        while (!st.empty()){
            res += st.top();
            st.pop();
        }
 
        return res;
    }
};