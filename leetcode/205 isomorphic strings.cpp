// https://leetcode.com/problems/isomorphic-strings

// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

// For example,
// Given "egg", "add", return true.

// Given "foo", "bar", return false.

// Given "paper", "title", return true.

#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  void print_vector(char c, vector<int>& vec){
    // printf("vector for char '%c': ", c);
    // for (auto it = vec.begin(); it != vec.end(); ++it)
    //   cout << ' ' << *it;
    // cout << endl;
  }
  
  void build_map( string str, unordered_map<char, vector<int>> *map, vector<unordered_map<char, vector<int>>::const_iterator> *alphabet){
    for (int i = 0; i < str.size(); i++){
      char c = str.at(i);
      if (map->find(c) != map->end()){
        //add position to the existing character
        map->at(c).push_back(i);
        print_vector(c, map->at(c));
      }
      else{
        //new char
        vector<int> vec;
        vec.push_back(i);
        pair<char, vector<int>> char_data(c, vec);
        map->insert(char_data);

        unordered_map<char, vector<int>>::const_iterator pair = map->find(c);
        alphabet->push_back(pair);
        print_vector(c, vec);
      }
    }
  }


public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, vector<int>> map1, map2;
    vector<unordered_map<char, vector<int>>::const_iterator> alphabet1, alphabet2;

    if (s.size() != t.size())
      return false;

    if (s == "" || t == "")
      return true;

    build_map(s, &map1, &alphabet1);
    // printf("----\n");
    build_map(t, &map2, &alphabet2);
    // printf("----\n");

    if (map1.size() != map2.size()){
      //different amount of unique characters
      return false;
    }

    // for (auto pair1 = map1.begin(), pair2 = map2.begin(); pair1 != map1.end(), pair2 != map2.end(); pair1++, pair2++){
    for (auto pair1 = alphabet1.begin(), pair2 = alphabet2.begin();
              pair1 != alphabet1.end(), pair2 != alphabet2.end();
              pair1++, pair2++){
      vector<int> char_positions1 = (*pair1)->second;
      vector<int> char_positions2 = (*pair2)->second;
      // printf("compare positions for chars %c and %c\n", (*pair1)->first, (*pair2)->first );
      print_vector((*pair1)->first, char_positions1);
      print_vector((*pair2)->first, char_positions2);

      if (char_positions1.size() != char_positions2.size()){
        // different amount of possibly replaced character in strings
        return false;
      }

      for (auto pos1 = char_positions1.begin(), pos2 = char_positions2.begin(); pos1 != char_positions1.end(), pos2 != char_positions2.end(); pos1++, pos2++){
        // printf("pos1 = %d, pos2 = %d\n", *pos1, *pos2);
        if (*pos1 != *pos2){
          // possibly replaced character is located on different positions
          return false;
        }
      }
    }

    return true;
  }
};