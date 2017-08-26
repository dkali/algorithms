// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting

// Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

// Example 1:
// Input:
// s = "abpcplea", d = ["ale","apple","monkey","plea"]

// Output: 
// "apple"
// Example 2:
// Input:
// s = "abpcplea", d = ["a","b","c"]

// Output: 
// "a"
// Note:
// All the strings in the input will only contain lower-case letters.
// The size of the dictionary won't exceed 1,000.
// The length of all the strings in the input won't exceed 1,000.

#include <iostream>
#include <vector>
#include <string>
#include <map>
 
using namespace std;
 
class Solution {
public:
    string findLongestWord(string origin, vector<string>& d) {
        map<int, vector<string>> storage; //word length, word list
 
        // find all suitable words
        for (string str : d){
            if (str.size() > origin.size())
                continue; //doesn't match, go to the next word
 
            int cur = 0;
            for (char c : origin){
                if (cur < str.size() && str[cur] == c)
                    cur++;
            }
            if (cur == str.size()){
                //word found, save it
                if (storage.find(str.size()) == storage.end()){
                    vector<string> v;
                    v.push_back(str);
                    storage[str.size()] = v;
                }
                else{
                    storage[str.size()].push_back(str);
                }
            }
        }
 
        if (storage.size() == 0)
            return ""; //no suitable words found
 
        //find the longest word/words
        int maxLen = 0;
        vector<string> *longestWords = nullptr;
        for (auto it = storage.begin(); it != storage.end(); ++it){
            if (it->first > maxLen){
                longestWords = &(it->second);
            }
        }
 
        if (longestWords->size() == 1){
            //single word with max Length, return it
            return longestWords->at(0);
        }
 
        //sort the words in lexicographical order
        for (int i = 0; i < longestWords->size() - 1; i++){
            string s1 = (string)longestWords->at(i);
            string s2 = (string)longestWords->at(i+1);
            if (s1.compare(s2) < 0){
                longestWords->at(i+1) = s1;
            }
        }
 
        return longestWords->back();
    }
};