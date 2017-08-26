// https://leetcode.com/problems/sum-of-left-leaves

// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

#include <iostream>
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        stack<TreeNode *> st;
        if (root)
            st.push(root);
 
        while (!st.empty()){
            TreeNode *cur = st.top();
            st.pop();
 
            if (cur->left){
                if (cur->left->left || cur->left->right)
                    st.push(cur->left);
                else
                    sum += cur->left->val;
            }
            if (cur->right){
                st.push(cur->right);
            }
        }
 
        return sum;
    }
};