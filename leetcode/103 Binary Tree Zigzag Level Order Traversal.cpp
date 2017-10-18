// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back(root);
        
        vector<vector<int>> result;
        int dir = 1;
        while(!q.empty()){
            int qsize = (int)q.size();
            vector<int> line;
            for (int i = 0; i < qsize; i++){
                TreeNode *node;
                if (dir > 0){
                    node = q.back();
                    q.pop_back();
                }
                else{
                    node = q.front();
                    q.pop_front();
                }
                if (!node) continue;
                
                line.push_back(node->val);
                if (dir > 0){
                    q.push_front(node->left);
                    q.push_front(node->right);
                }
                else{
                    q.push_back(node->right);
                    q.push_back(node->left);
                }
            }
            if (!line.empty()) result.push_back(line);
            dir = -dir;
        }
        return result;
    }
};