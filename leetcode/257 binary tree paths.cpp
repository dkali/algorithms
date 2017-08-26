// https://leetcode.com/problems/binary-tree-paths

// Given a binary tree, return all root-to-leaf paths.

// For example, given the following binary tree:

//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:

// ["1->2->5", "1->3"]

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void goDown(TreeNode *node, string path, vector<string> *v){
        if (!path.empty())
            path += "->";
        path += to_string(node->val);
        
        if (node->left != nullptr){
            goDown(node->left, path, v);
        }
        if (node->right != nullptr){
            goDown(node->right, path, v);
        }
        
        if (node->left == nullptr && node->right == nullptr){
            v->push_back(path);
        }
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        
        if (root != nullptr)
            goDown(root, "", &result);
        return result;
    }
};