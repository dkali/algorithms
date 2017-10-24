// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

// Note: 
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int dfs(TreeNode *node, int &k){
        int ret = INT_MIN;
        
        if (node->left && ret == INT_MIN){
            ret = dfs(node->left, k);
        }
        
        k--;
        if (k == 0)
            return node->val;
        
        if (node->right && ret == INT_MIN){
            ret = dfs(node->right, k);
        }
        
        return ret;
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }
};
