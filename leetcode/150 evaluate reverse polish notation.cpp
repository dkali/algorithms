// https://leetcode.com/problems/evaluate-reverse-polish-notation

// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, /. Each operand may be an integer or another expression.

// Some examples:
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
  
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <functional>

using namespace std;

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    int result = 0;

    for (auto it = tokens.begin(); it != tokens.end(); ++it) {
      if (*it != "*" && *it != "/" && *it != "+" && *it != "-") {
        st.push(stoi(*it, NULL, 10));
        continue;
      }
      
      function<int(int, int)> op;
      switch ((*it)[0]) {
      case '*':
        op = multiplies<int>();
        break;
      case '+':
        op = plus<int>();
        break;
      case '-':
        op = minus<int>();
        break;
      case '/':
        op = divides<int>();
        break;
      }

      int left_operand, right_operand;
      right_operand = st.top();
      st.pop();
      left_operand = st.top();
      st.pop();

      st.push(op(left_operand, right_operand));
    }

    return st.top();
  }
};