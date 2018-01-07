// https://leetcode.com/problems/replace-words/description/

// In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

// Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

// You need to output the sentence after the replacement.

// Example 1:
// Input: dict = ["cat", "bat", "rat"]
// sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
// Note:
// The input will only have lower-case letters.
// 1 <= dict words number <= 1000
// 1 <= sentence words number <= 1000
// 1 <= root length <= 100
// 1 <= sentence words length <= 1000

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class TrieNode {
public:
    bool is_word_end;
    map<char, TrieNode*> char_refs;
    
    TrieNode() : is_word_end(false) {};
    ~TrieNode() {
        for (map<char, TrieNode*>::iterator it = char_refs.begin(); it != char_refs.end(); ++it)
            delete it->second;
    }
};

class Solution {
private:
    TrieNode* buildTrie(vector<string> dict) {
        TrieNode *root = new TrieNode();
        
        for (string word : dict) {
            TrieNode *current_node = root;
            for (char c : word) {
                TrieNode *new_node;
                if (current_node->char_refs.find(c) == current_node->char_refs.end()) {
                    new_node = new TrieNode();
                    current_node->char_refs[c] = new_node;
                }
                else
                    new_node = current_node->char_refs[c];
                current_node = new_node;
            }
            current_node->is_word_end = true;
        }
        
        return root;
    }
    
    bool getNextWord(long &cursor, string &sentence, string &word) {
        word = "";
        
        while (cursor >= 0 && sentence[cursor] != ' ') {
            word = sentence[cursor] + word;
            cursor--;
        }
        cursor--;
        return word != "";
    }
    
    bool checkForRoot(TrieNode *root_node, string &word_to_find, string &word_root) {
        TrieNode *current_node = root_node;
        
        word_root = "";
        for (char c : word_to_find) {
            if (current_node->char_refs.find(c) == current_node->char_refs.end())
                break;
            else {
                word_root += c;
                current_node = current_node->char_refs[c];
                if (current_node->is_word_end) break;
            }
        }
        
        return current_node->is_word_end;
    }
    
public:
    string replaceWords(vector<string> &dict, string sentence) {
        if (dict.empty() || sentence.empty())
            return sentence;
        
        TrieNode *root_node = buildTrie(dict);
        
        long cursor = sentence.size() - 1;
        string tmp_word = "";
        while (getNextWord(cursor, sentence, tmp_word)) {
            string word_root = "";
            if (checkForRoot(root_node, tmp_word, word_root)) {
                sentence.replace(cursor + 2, tmp_word.size(), word_root);
            }
        }
        
        delete root_node;
        return sentence;
    }
};