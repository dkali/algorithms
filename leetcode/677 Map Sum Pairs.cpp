// https://leetcode.com/problems/map-sum-pairs/description/

// Implement a MapSum class with insert, and sum methods.

// For the method insert, you'll be given a pair of (string, integer). The string represents the key and the integer represents the value. If the key already existed, then the original key-value pair will be overridden to the new one.

// For the method sum, you'll be given a string representing the prefix, and you need to return the sum of all the pairs' value whose key starts with the prefix.

// Example 1:
// Input: insert("apple", 3), Output: Null
// Input: sum("ap"), Output: 3
// Input: insert("app", 2), Output: Null
// Input: sum("ap"), Output: 5

#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

class Node {
public:
    bool bTail;
    map<char, Node*> children;
    
    Node(){
        bTail = false;
    }
};

class MapSum {
public:
    /** Initialize your data structure here. */
    Node *trie;
    map<string, int> values;
    MapSum() {
        trie = new Node();
    }

    ~MapSum(){
        //delete trie
        queue<Node*> myTrash;
        myTrash.push(trie);
        
        while (myTrash.empty() != true) {
            Node *tmp = myTrash.front();
            myTrash.pop();
            for (map<char, Node*>::iterator it = tmp->children.begin(); it != tmp->children.end(); it++) {
                myTrash.push(it->second);
            }
            delete tmp;
        }
    }
    
    void insert(string key, int val) {
        Node *current = trie;
        
        pair<map<string,int>::iterator, bool> ret = values.insert(pair<string, int>(key, val));
        if (ret.second == false)
            values[key] = val;
        
        for (char c : key) {
            if (current->children.find(c) != current->children.end()) {
                current = current->children[c];
                continue;
            }
            
            Node *tail = new Node();
            current->children[c] = tail;
            current = tail;
        }
        current->bTail = true;
    }
    
    int sum(string prefix) {
        int sum = 0;
        Node *current = trie;
        
        for (char c : prefix) {
            if (current->children.find(c) != current->children.end()) {
                current = current->children[c];
                continue;
            }
            else {
                current = nullptr;
                break;
            }
        }
        
        string key = prefix;
        if (current != nullptr) {
            goDeeper(&sum, current, prefix);
        }
        
        return sum;
    }
    
    void goDeeper(int *sum, Node *current, string prefix) {
        if (current->bTail)
            *sum += values[prefix];
        
        for (auto it = current->children.begin(); it != current->children.end(); it++) {
            goDeeper(sum, it->second, prefix + it->first);
        }
    }
};
