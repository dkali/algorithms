// https://leetcode.com/problems/merge-two-binary-trees/description/

// Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

// You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

// Example 1:
// Input: 
// 	Tree 1                     Tree 2                  
//           1                         2                             
//          / \                       / \                            
//         3   2                     1   3                        
//        /                           \   \                      
//       5                             4   7                  
// Output: 
// Merged tree:
// 	     3
// 	    / \
// 	   4   5
// 	  / \   \ 
// 	 5   4   7
// Note: The merging process must start from the root nodes of both trees.


// ==========  V1 recursively ==========
#include <iostream>
#include <deque>
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *node = nullptr;
        int val = 0;

        if (t1 == nullptr && t2 == nullptr) return node;
        if (t1 != nullptr) val += t1->val;
        if (t2 != nullptr) val += t2->val;

        node = new TreeNode(val);
        node->left = mergeTrees(t1 == nullptr ? nullptr : t1->left,
                                t2 == nullptr ? nullptr : t2->left);
        node->right = mergeTrees(t1 == nullptr ? nullptr : t1->right,
                                 t2 == nullptr ? nullptr : t2->right);
        return node;
    }
};

// ==========  V1 iteratively ==========
#include <iostream>
#include <stack>
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
private:
    TreeNode* dfs_copy(TreeNode *node){
        TreeNode *cur = nullptr;

        if (node == nullptr) return cur;
        cur = new TreeNode(node->val);
        cur->left = dfs_copy(node->left);
        cur->right = dfs_copy(node->right);
        return cur;
    }

public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *root = nullptr;
        stack<TreeNode*> st_left, st_right;
        stack<TreeNode**> st_res;
        st_left.push(t1);
        st_right.push(t2);
        st_res.push(&root);

        while(!st_left.empty()){
            TreeNode *n1, *n2;
            TreeNode **r;
            n1 = st_left.top();
            n2 = st_right.top();
            r = st_res.top();
            st_left.pop();
            st_right.pop();
            st_res.pop();

            if (n1 == nullptr && n2 == nullptr)
                continue;
            else if (n1 && n2){
                int val = 0;
                *r = new TreeNode(n1->val + n2->val);
                st_left.push(n1->left);
                st_right.push(n2->left);
                st_res.push(&(*r)->left);
                st_left.push(n1->right);
                st_right.push(n2->right);
                st_res.push(&(*r)->right);
            }
            else{
                if (n1 == nullptr)
                    *r = dfs_copy(n2);
                if (n2 == nullptr)
                    *r = dfs_copy(n1);
            }
        }

        return root;
    }
};
