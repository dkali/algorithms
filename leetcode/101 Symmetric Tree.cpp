// https://leetcode.com/problems/symmetric-tree/description/

// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.

#include <iostream>
#include <deque>

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        deque<TreeNode*> dq;
        dq.push_front(root->left);
        dq.push_back(root->right);

        while (!dq.empty()) {
            if (dq.front() == nullptr && dq.back() == nullptr) {
                dq.pop_front();
                dq.pop_back();
                continue;
            }
            TreeNode *left, *right;
            left = dq.front();
            right = dq.back();

            dq.pop_front();
            dq.pop_back();
            if ((!left && right) || (left && !right) || (left->val != right->val)) {
                return false;
            }
            dq.push_front(left->right);
            dq.push_front(left->left);
            dq.push_back(right->left);
            dq.push_back(right->right);
        }
        return true;
    }
};
