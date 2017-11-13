// https://leetcode.com/problems/binary-search-tree-iterator

// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

// Calling next() will return the next smallest number in the BST.

// Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

#include <iostream>
#include <stack>

using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> *st;
    TreeNode *current;
    
public:
    BSTIterator(TreeNode *root) {
        st = new stack<TreeNode*>();
        current = root;
    }
    
    ~BSTIterator(){
        delete st;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (current || !st->empty()) ? true : false;
    }
    
    /** @return the next smallest number */
    int next() {
        while (current){
            st->push(current);
            current = current->left;
        }
        
        TreeNode *tmp = st->top();
        st->pop();
        current = tmp->right;
        
        return tmp->val;
    }
};
