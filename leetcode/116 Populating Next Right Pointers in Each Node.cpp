// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

// Given a binary tree

//     struct TreeLinkNode {
//       TreeLinkNode *left;
//       TreeLinkNode *right;
//       TreeLinkNode *next;
//     }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

// Note:

// You may only use constant extra space.
// You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
// For example,
// Given the following perfect binary tree,
//          1
//        /  \
//       2    3
//      / \  / \
//     4  5  6  7

// After calling your function, the tree should look like:
//          1 -> NULL
//        /  \
//       2 -> 3 -> NULL
//      / \  / \
//     4->5->6->7 -> NULL

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
 
// Definition for a binary tree node.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) {
            return;
        }
 
        auto *currentLevel = new queue<TreeLinkNode *>, *nextLevel = new queue<TreeLinkNode *>;
        currentLevel->push(root);
 
        while (!currentLevel->empty()) {
            TreeLinkNode *rightNode = nullptr;
            while (!currentLevel->empty()) {
                TreeLinkNode *currentNode = currentLevel->front();
                currentLevel->pop();
                currentNode->next = rightNode;
                rightNode = currentNode;
 
                if (currentNode->right != nullptr) nextLevel->push(currentNode->right);
                if (currentNode->left != nullptr) nextLevel->push(currentNode->left);
            }
 
            if (!nextLevel->empty()) {
                delete currentLevel;
                currentLevel = nextLevel;
                nextLevel = new queue<TreeLinkNode *>;
            }
        }
 
        delete currentLevel;
        delete nextLevel;
        currentLevel = nullptr;
        nextLevel = nullptr;
    }
};