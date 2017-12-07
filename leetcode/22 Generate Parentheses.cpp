// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// For example, given n = 3, a solution set is:

// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int pairs_num;
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        pairs_num = n;
        string str = "";
        bt(str, vec, n);
        return vec;
    }
    
    void bt(string str, vector<string> &v, int limit){
        if (limit == 0){
            v.push_back(reconstruct_brackets(str));
        }
        else{
            bt(str + '(', v, limit - 1);
            long brackets_opened = (pairs_num - limit);
            long brackets_closed = str.size() - brackets_opened;
            if (str != "" && (brackets_opened > brackets_closed)){
                bt(str + ')', v, limit);
            }
        }
    }
    
    string reconstruct_brackets(string str){
        long count = pairs_num * 2 - str.size();
        if (count > 0){
            string tail = string(count, ')');
            str += tail;
        }
        return str;
    }
};
