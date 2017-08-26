// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its bottom-up level order traversal as:
// [
//   [15,7],
//   [9,20],
//   [3]
// ]

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
 
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        stack<vector<int>> preResult;
 
        if(!root)
            return result;
        queue<TreeNode*> *q1 = new queue<TreeNode*>, *q2 = new queue<TreeNode*>;
        q1->push(root);
 
        while (!q1->empty()){
            vector<int> treeLevel;
            while (!q1->empty()){
                TreeNode *current = q1->front();
                q1->pop();
                treeLevel.push_back(current->val);
 
                if (current->left != nullptr) q2->push(current->left);
                if (current->right != nullptr) q2->push(current->right);
            }
            preResult.push(treeLevel);
 
            if (!q2->empty()){
                delete q1;
                q1 = q2;
                q2 = new queue<TreeNode*>;
            }
        }
 
        while(!preResult.empty()){
            result.push_back(preResult.top());
            preResult.pop();
        }
 
        if (q1) delete q1;
        if (q2) delete q2;
        return result;
    }
};
