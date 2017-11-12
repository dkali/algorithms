// https://leetcode.com/problems/maximum-binary-tree

// Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

// The root is the maximum number in the array.
// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
// Construct the maximum tree by the given array and output the root node of this tree.

// Example 1:
// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:

//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1

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
    TreeNode* buildTree(vector<int> &nums, long left, long right){
        long posMax = left, maxVal = nums[left];
        for (long i = left + 1; i <= right; i++){
            if (nums[i] > maxVal){
                maxVal = nums[i];
                posMax = i;
            }
        }
        
        TreeNode *node = new TreeNode(nums[posMax]);
        if (posMax > left)
            node->left = buildTree(nums, left, posMax - 1);
        if (posMax < right)
            node->right = buildTree(nums, posMax + 1, right);
        
        return node;
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};
