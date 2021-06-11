// // https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/

// You are given a string s that contains some bracket pairs, with each pair containing a non-empty key.

// For example, in the string "(name)is(age)yearsold", there are two bracket pairs that contain the keys "name" and "age".
// You know the values of a wide range of keys. This is represented by a 2D string array knowledge where each knowledge[i] = [keyi, valuei] indicates that key keyi has a value of valuei.

// You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair that contains some key keyi, you will:

// Replace keyi and the bracket pair with the key's corresponding valuei.
// If you do not know the value of the key, you will replace keyi and the bracket pair with a question mark "?" (without the quotation marks).
// Each key will appear at most once in your knowledge. There will not be any nested brackets in s.

// Return the resulting string after evaluating all of the bracket pairs.

// Example 1:
// Input: s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
// Output: "bobistwoyearsold"
// Explanation:
// The key "name" has a value of "bob", so replace "(name)" with "bob".
// The key "age" has a value of "two", so replace "(age)" with "two".

// Example 2:
// Input: s = "hi(name)", knowledge = [["a","b"]]
// Output: "hi?"
// Explanation: As you do not know the value of the key "name", replace "(name)" with "?".

// Example 3:
// Input: s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
// Output: "yesyesyesaaa"
// Explanation: The same key can appear multiple times.
// The key "a" has a value of "yes", so replace all occurrences of "(a)" with "yes".
// Notice that the "a"s not in a bracket pair are not evaluated.

// Example 4:
// Input: s = "(a)(b)", knowledge = [["a","b"],["b","a"]]
// Output: "ba"

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string str, vector<vector<string>>& knowledge) {
        unordered_map<string, string> db;
        for (vector<string> vect : knowledge) {
            db.insert( pair<string,string>(vect[0], vect[1]) );
        }
        
        string result = "";
        string key = "";
        bool keyFound = false;
        for (char c : str) {
            if (keyFound) {
                if (c == ')') {
                    keyFound = false;
                    if (db.find(key) == db.end()) {
                        result += '?';
                    }
                    else {
                        result += db[key];
                    }
                    key = "";
                }
                else {
                    key += c;
                }
            }
            else {
                if (c == '(') {
                    keyFound = true;
                }
                else {
                    result += c;
                }
            }
                
        }
        
        return result;
    }
};