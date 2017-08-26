// https://leetcode.com/problems/substring-with-concatenation-of-all-words

// You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

// For example, given:
// s: "barfoothefoobarman"
// words: ["foo", "bar"]

// You should return the indices: [0,9].
// (order does not matter).
 
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
 
using namespace std;
 
class WordTail {
public:
  int wordsLeft, backup;
  WordTail() {
    wordsLeft = 0;
    backup = wordsLeft;
  }
};
 
class Node {
public:
  unordered_map<char, Node*> *leafs;
  WordTail *tail; // workaround to eleminate sequential duplicated words
 
  Node() {
    leafs = nullptr;
    tail = new WordTail();
  }
 
  ~Node() {
    if (leafs != nullptr) {
      for (auto it = leafs->begin(); it != leafs->end(); ++it) {
        delete it->second;
      }
      delete leafs;
    }
    delete tail;
  }
};
 
class Solution {
private:
  Node *trie;
  set<WordTail *> tails; //used to make sure the word was found only once
 
  void buildTrie(vector<string>& words) {
    trie = new Node;
 
    for (int i = 0; i < words.size(); i++) {
      insertWord(words[i]);
    }
  }
 
  void insertWord(string w) {
    Node *current = trie;
    for (char c : w) {
      if (current->leafs == nullptr)
        current->leafs = new unordered_map<char, Node*>;
 
      if (current->leafs->find(c) == current->leafs->end()) {
        Node *leaf = new Node;
        (*current->leafs)[c] = leaf;
        current = leaf;
      }
      else {
        current = current->leafs->at(c);
      }
    }
 
    // add word's last symbol into vector
    current->tail->wordsLeft++;
    current->tail->backup = current->tail->wordsLeft;
    tails.insert(current->tail);
  }
 
  void restoreTrieState() {
    for (auto it = tails.begin(); it != tails.end(); ++it) {
      (*it)->wordsLeft = (*it)->backup;
    }
  }
 
  int startSearch(int pos, string &s, long wordSize, long wordsCount) {
    int foundPos = pos;
    int wordNotFound = -1;
 
    while (wordsCount-- > 0) {
      Node *current = trie;
      long charCount = wordSize;
 
      while (charCount-- > 0) {
        char c = s[pos++];
        if (current->leafs == nullptr) {
          //no more letters at this level
          return wordNotFound;
        }
 
        if (current->leafs->find(c) == current->leafs->end()) {
          //word not found in dictionary
          return wordNotFound;
        }
 
        current = current->leafs->at(c);
      }
 
      // we have found the word, make sure it is the exact word, not just a prefix
      if (current->leafs != nullptr) {
        return wordNotFound;
      }
 
      if (current->tail->wordsLeft == 0) {
        //same word was already found in this search iteration
        return wordNotFound;
      }
      else {
        current->tail->wordsLeft--;
      }
    }
 
    return foundPos;
  }
 
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> result;
 
    buildTrie(words);
 
    long str_size = s.size();
    long all_words_size = words[0].size()*words.size();
    for (int pos = 0; pos <= str_size - all_words_size; pos++) {
      int foundPos = startSearch(pos, s, words[0].size(), words.size());
      restoreTrieState();
      if (foundPos >= 0) {
        result.push_back(foundPos);
      }
    }
 
    return result;
  }
 
  ~Solution() {
    delete trie;
  }
};