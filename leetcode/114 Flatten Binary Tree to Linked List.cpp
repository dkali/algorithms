// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

// Given a binary tree, flatten it to a linked list in-place.

// For example,
// Given

//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6

// Hints:
// If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.

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
    TreeNode* preOrderTraversal(TreeNode *n){
        TreeNode *last = nullptr;
        if (n->left == nullptr && n->right == nullptr) return n;
        if (n->left){
            TreeNode *tmp = n->right;
            last = preOrderTraversal(n->left);
            n->right = n->left;
            last->right = tmp;
            n->left = nullptr;
        }
        if (n->right){
            last = preOrderTraversal(n->right);
        }
        return last;
    }

public:
    void flatten(TreeNode* root) {
        if (!root) return;
        preOrderTraversal(root);
    }
};