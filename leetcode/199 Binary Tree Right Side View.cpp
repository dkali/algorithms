// https://leetcode.com/problems/binary-tree-right-side-view

// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
 
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
 
        if (root == nullptr){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);
 
        while (!q.empty()){
            bool bRightNodeCounted = false;
            int rowSize = q.size();
 
            for (int i = 0; i < rowSize; i++){
                TreeNode *node = q.front();
                q.pop();
 
                if (!bRightNodeCounted){
                    result.push_back(node->val);
                    bRightNodeCounted = true;
                }
 
                if (node->right != nullptr){
                    q.push(node->right);
                }
                if (node->left != nullptr){
                    q.push(node->left);
                }
            }
        }
 
        return result;
    }
 
};