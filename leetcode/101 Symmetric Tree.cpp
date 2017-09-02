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
    bool check_nodes(TreeNode *ln, TreeNode *rn){
        int llv = INT_MAX, lrv = INT_MAX, rlv = INT_MAX, rrv = INT_MAX;
        if (ln->left != nullptr) {llv = ln->left->val;}
        if (ln->right != nullptr) {lrv = ln->right->val;}
        if (rn->left != nullptr) {rlv = rn->left->val;}
        if (rn->right != nullptr) {rrv = rn->right->val;}

        if (llv != rrv) return false;
        if (lrv != rlv) return false;
        return true;
    }

public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> lq, rq;
        if (root == nullptr) return true;
        if (root->left == nullptr && root->right == nullptr) return true;
        if ((root->left == nullptr && root->right != nullptr) ||
            (root->right == nullptr && root->left != nullptr)) return false;
        if (root->left->val != root->right->val) return false;

        lq.push(root->left);
        rq.push(root->right);

        while (!lq.empty() && !rq.empty()){
            int limit = lq.size();

            for (int i = 0; i < limit; i++){
                TreeNode *ln, *rn;
                ln = lq.front();
                rn = rq.front();
                lq.pop();
                rq.pop();

                if (ln->val != rn->val) return false;
                if (check_nodes(ln, rn) == false) return false;
                if (ln->left != nullptr) lq.push(ln->left);
                if (ln->right != nullptr) lq.push(ln->right);
                if (rn->right != nullptr) rq.push(rn->right);
                if (rn->left != nullptr) rq.push(rn->left);
            }
        }

        if (!lq.empty() || !rq.empty())
            return false;
        return true;
    }
};
