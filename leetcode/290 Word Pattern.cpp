// https://leetcode.com/problems/word-pattern

// Given a pattern and a string str, find if str follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.

// Notes:
// You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <set>
 
using namespace std;
 
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss;
    ss.str(s);
    string item;
 
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
 
    return elems;
}
 
map<char, vector<int>> processPattern(const string &s){
    map<char, vector<int>> lookUpMap;
 
    for (int i = 0; i < s.size(); i++){
        lookUpMap[s[i]].push_back(i);
    }
 
    return lookUpMap;
};
 
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words = split(str, ' ');
        map<char, vector<int>> lookUp = processPattern(pattern);
 
        if (words.size() != pattern.size())
            return false;
 
        set<string> unique_words;
        //check that words match at the right positions
        for (auto it = lookUp.begin(); it != lookUp.end(); ++it){
            string test_word = words[it->second[0]];
            if (it->second.size() > 1){
                for (int pos = it->second.size() - 1; pos >= 1; pos--){
                    if (test_word != words[it->second[pos]])
                        return false;
                }
            }
            //meake sure words are unique
            if ((unique_words.insert(test_word)).second == false )
                return false;
        }
 
        return true;
    }
};