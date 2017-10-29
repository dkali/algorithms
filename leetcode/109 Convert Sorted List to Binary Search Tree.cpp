// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* listToBST(ListNode *left, ListNode *right){
        int size = 0;
        ListNode *tmpNode = left, *prev = left;
        while (tmpNode != right){
            size++;
            tmpNode = tmpNode->next;
        }
        
        tmpNode = left;
        for (int i = 0; i < size /2; i++){
            prev = tmpNode;
            tmpNode = tmpNode->next;
        }
        
        TreeNode *node = nullptr;
        if (tmpNode){
            node = new TreeNode(tmpNode->val);
            if (left != tmpNode)
                node->left = listToBST(left, prev);
            if (tmpNode != right)
                node->right = listToBST(tmpNode->next, right);
        }
    
        return node;
    }
    
public:
    TreeNode* sortedListToBST(ListNode *head) {
        if (!head)
            return nullptr;
        
        TreeNode *node = listToBST(head, nullptr);
        return node;
    }
};
