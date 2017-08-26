// https://leetcode.com/problems/path-sum-iii

// You are given a binary tree in which each node contains an integer value.

// Find the number of paths that sum to a given value.

// The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

// The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

// Example:

// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1

// Return 3. The paths that sum to 8 are:

// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void startSearch(TreeNode *node, int targetSum, int *count, int tmpSum){
        tmpSum += node->val;
        
        if (tmpSum == targetSum){
            (*count)++;
        }
        
        if (node->left != nullptr){
            startSearch(node->left, targetSum, count, tmpSum);
        }
        if (node->right != nullptr){
            startSearch(node->right, targetSum, count, tmpSum);
        }
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        queue<TreeNode *> q;
        int count = 0;
        
        if (root != nullptr){
            q.push(root);
        }
        
        while(!q.empty()){
            TreeNode *startNode = q.front();
            
            q.pop();
            
            if (startNode->left != nullptr)
                q.push(startNode->left);
            if (startNode->right != nullptr)
                q.push(startNode->right);
            
            startSearch(startNode, sum, &count, 0);
        }
        
        return count;
    }
};