// https://leetcode.com/submissions/detail/488931457/

// Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

// Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

// If no such second minimum value exists, output -1 instead.

// Example 1:
// Input: root = [2,2,5,null,null,5,7]
// Output: 5
// Explanation: The smallest value is 2, the second smallest value is 5.

// Example 2:
// Input: root = [2,2,2]
// Output: -1
// Explanation: The smallest value is 2, but there isn't any second smallest value.
 
// Constraints:
// The number of nodes in the tree is in the range [1, 25].
// 1 <= Node.val <= 231 - 1
// root.val == min(root.left.val, root.right.val) for each internal node of the tree.

#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class mycomparison
{
    bool reverse;
public:
    mycomparison(const bool& revparam=false)
    {reverse=revparam;}
    bool operator() (const int& lhs, const int&rhs) const
    {
        if (reverse) return (lhs>rhs);
        else return (lhs<rhs);
    }
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        priority_queue<int, vector<int>, mycomparison> pq(mycomparison(true));
        queue<TreeNode*> qnodes;
        set<int> uniq;
        
        qnodes.push(root);
        while(!qnodes.empty()) {
            TreeNode *node = qnodes.front();
            qnodes.pop();
            
            if (uniq.find(node->val) == uniq.end()) {
                pq.push(node->val);
                uniq.insert(node->val);
            }
                
            
            if (node->left && node->right) {
                qnodes.push(node->left);
                qnodes.push(node->right);
            }
        }
        
        int result;
        if (pq.size() > 1) {
            pq.pop();
            result = pq.top();
        } else
            result = -1;
        
        return result;
    }
};