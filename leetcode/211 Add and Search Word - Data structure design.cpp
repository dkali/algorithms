// https://leetcode.com/problems/add-and-search-word-data-structure-design/description/

// Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

// For example:

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true

// Note:
// You may assume that all words are consist of lowercase letters a-z.

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */


// ====== fastest solution 62ms ===========

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class WordDictionary {
private:
    unordered_map<int, vector<string>> words;

    bool wordMatch(string &pattern, string &word){
        for (int i = 0; i < word.size(); i++){
            if (pattern[i] == '.') continue;
            if (pattern[i] != word[i]) return false;
        }
        return true;
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() {}

    /** Adds a word into the data structure. */
    void addWord(string word) {
        words[word.size()].push_back(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        vector<string> v = words[word.size()];
        for (string w : words[word.size()])
            if (wordMatch(word, w)) return true;
        return false;
    }
};



// ====== using Trie algorithm, works slow, 142ms =========
#include <iostream>
#include <map>

using namespace std;

class WordDictionary {
public:
    map<char, WordDictionary*> *wd;
    bool lastChar;

    void printMap(){
        printf("-------\n");
        for (auto it = wd->begin(); it != wd->end(); ++it){
            printf("key: %c, dict size %d, empty? %d\n", it->first, it->second->wd->size(), it->second->wd->empty());
        }
    }


    /** Initialize your data structure here. */
    WordDictionary() {
        lastChar = false;
        wd = new map<char, WordDictionary*>;
    }

    ~WordDictionary() {
        for (auto it = wd->begin(); it != wd->end(); ++it)
            delete it->second;
        delete wd;
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (word.size() > 0)
            insertWord(word, 0);
    }

    void insertWord(string &str, int index){
        char ch = str[index];
        if (wd->find(ch) == wd->end()){
            WordDictionary *d = new WordDictionary;
            wd->insert(pair<char, WordDictionary*>(ch, d));
        }
        if (index < str.size() - 1)
            wd->at(ch)->insertWord(str, ++index);
        else
            lastChar = true; // mark the end of the word
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(word, 0);
    }

    bool isEmpty(){
        return wd->empty();
    }

    bool searchWord(string &word, int index){
        char ch = word[index];
        if (ch != '.'){
            if (wd->find(ch) == wd->end())
                return false;
            else if (index == word.size() - 1 && (wd->at(ch)->isEmpty() || lastChar))
                return true;
            else
               return wd->at(ch)->searchWord(word, ++index);
        }
        else{
            if (index == word.size() - 1){
                if (lastChar)
                    return true;
                if (wd->empty())
                    return false;
                bool hasNext = false;
                for (auto it = wd->begin(); it != wd->end(); ++it)
                    hasNext |= !(it->second->isEmpty());
                return !hasNext;
            }
            else{
                bool match = false;
                for (auto it = wd->begin(); it != wd->end(); ++it){
                    if (!it->second->isEmpty())
                        match |= it->second->searchWord(word, index + 1);
                    if (match) break;
                }
                return match;
            }
        }
    }
};

