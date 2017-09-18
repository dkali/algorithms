// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

#include <iostream>
#include <vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* initTree(vector<int> nums, int lcur, int rcur){
        if (lcur > rcur) return nullptr;
        int mid = (lcur + rcur)/2;
        TreeNode *n = new TreeNode(nums[mid]);
        n->left = initTree(nums, lcur, mid - 1);
        n->right = initTree(nums, mid + 1, rcur);
        return n;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *head = nullptr;
        if (!nums.empty())
            head = initTree(nums, 0, nums.size() - 1);
        return head;
    }
};