// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

// Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

// If there are no nodes with an even-valued grandparent, return 0.

// Example 1:
// Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// Output: 18
// Explanation: The red nodes are the nodes with even-value grandparent while the blue nodes are the even-value grandparents.

// Constraints:
// The number of nodes in the tree is between 1 and 10^4.
// The value of nodes is between 1 and 100.

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct familyMember {
    TreeNode* currentNode;
    queue<int> ancestors;
};

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        stack<familyMember*> mstack;
        
        if (root == nullptr)
            return 0;
        else {
            familyMember* froot = new familyMember;
            froot->currentNode = root;
            mstack.push(froot);
        }
            
        while(!mstack.empty()) {
            familyMember* current = mstack.top();
            mstack.pop();
            
            if (current->ancestors.size() == 2) {
                if (current->ancestors.front() % 2 == 0) {
                    sum += current->currentNode->val;
                    // cout << "child = " << current->currentNode->val << endl;
                }
                current->ancestors.pop();
            }
            
            // insert self as parent for leafs
            queue<int> newAncestors;
            if (!current->ancestors.empty())
                newAncestors.push(current->ancestors.front());
            newAncestors.push(current->currentNode->val);
            
            if (current->currentNode->left != nullptr) {
                familyMember* fleft = new familyMember();
                fleft->ancestors = newAncestors;
                fleft->currentNode = current->currentNode->left;
                mstack.push(fleft);
            }
            if (current->currentNode->right != nullptr) {
                familyMember* fright = new familyMember();
                fright->ancestors = newAncestors;
                fright->currentNode = current->currentNode->right;
                mstack.push(fright);
            }
            
            delete(current);
        }
        
        return sum;
    }
};
