// https://leetcode.com/problems/binary-tree-level-order-traversal

// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

//=============== using queue =================
#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
 
        if (root == nullptr) return result;
 
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()){
            vector<int> row;
            int rowSize = q.size();
 
            for (int i = 0; i < rowSize; i++){
                TreeNode *node = q.front();
                q.pop();
 
                row.push_back(node->val);
 
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
 
            result.push_back(row);
        }
 
        return result;
    }
};
 
//============= using dfs, no additional memory ===========
#include <iostream>
#include <vector>
 
using namespace std;
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
void dfs(TreeNode *node, int depth, vector<vector<int>> &result){
    if (depth > result.size() - 1){
        vector<int> row;
        result.push_back(row);
    }
 
    result[depth].push_back(node->val);
 
    if (node->left != nullptr) dfs(node->left, depth + 1, result);
    if (node->right != nullptr) dfs(node->right, depth + 1, result);
}
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
 
        if (root == nullptr)
            return result;
 
        vector<int> row;
        result.push_back(row);
        dfs(root, 0, result);
 
        return result;
    }
};