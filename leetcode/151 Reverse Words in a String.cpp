// https://leetcode.com/problems/reverse-words-in-a-string

// Given an input string, reverse the string word by word.

// For example,
// Given s = "the sky is blue",
// return "blue is sky the".

// Update (2015-02-12):
// For C programmers: Try to solve it in-place in O(1) space.

// click to show clarification.

// Clarification:
// - What constitutes a word?
//   A sequence of non-space characters constitutes a word.
// - Could the input string contain leading or trailing spaces?
//   Yes. However, your reversed string should not contain leading or trailing spaces.
// - How about multiple spaces between two words?
//   Reduce them to a single space in the reversed string.

#include <iostream>
#include <string>
#include <stack>
 
using namespace std;
 
class Solution {
public:
    void reverseWords(string &s) {
        stack<string> st;
 
        int SPACE = 32;
        string tmp = "";
        for (char c : s){
            if (c == SPACE){
                if (!tmp.empty()){
                    st.push(tmp);
                    tmp = "";
                }
            }
            else{
                tmp += c;
            }
        }
 
        // for last word
        if (!tmp.empty()){
            st.push(tmp);
        }
 
        s = "";
        while (!st.empty()){
            if (!s.empty())
                s += SPACE;
            s += st.top();
            st.pop();
        }
    }
};