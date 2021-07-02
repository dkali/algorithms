// https://leetcode.com/problems/deepest-leaves-sum/

// Given the root of a binary tree, return the sum of values of its deepest leaves.

// Example 1:
// Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
// Output: 15

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        long qsize = 0;
        queue<TreeNode*> mq;
        
        if (root == nullptr)
            return 0;
        else {
            mq.push(root);
            qsize = mq.size();
        }
        
        while (!mq.empty()) {
            sum = 0;
            // calculate the sum for the current row
            while (qsize-- > 0) {
                TreeNode* currentNode = mq.front();
                mq.pop();
                sum += currentNode->val;
                if (currentNode->left != nullptr) {
                    mq.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    mq.push(currentNode->right);
                }
            }
            qsize = mq.size();
        }
        
        return sum;
    }
};