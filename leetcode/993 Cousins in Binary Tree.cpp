// https://leetcode.com/problems/cousins-in-binary-tree/

// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
// Return true if and only if the nodes corresponding to the values x and y are cousins.

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // <TreeNode*, parent-value>>
    queue<tuple<TreeNode*, int>*> qLevels;
    vector<tuple<TreeNode*, int>*> vCandidates;
    
    void addNextNode(TreeNode* node, int parent, int &len) {
        if (node) {
            tuple<TreeNode*, int>* tupl = new tuple<TreeNode*, int>(node, parent);
            qLevels.push(tupl);
            len++;
        }
    }
    
    void delete_vector_values(vector<tuple<TreeNode*, int>*> vector) {
        for (auto it = vector.begin(); it != vector.end(); ++it) {
            delete *it;
        }
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int rowLength = 1;
        tuple<TreeNode*, int>* tupl = new tuple<TreeNode*, int>(root, 0);
        qLevels.push(tupl);
        
        while(qLevels.size() != 0) {
            // inspect the nodes on the same tree level
            int newLength = 0;
            while (rowLength-- > 0) {
                tupl = qLevels.front();
                qLevels.pop();
                
                // save nodes with values we are looking for
                TreeNode* curNode = get<0>(*tupl);
                if (curNode->val == x || curNode->val == y) {
                    vCandidates.push_back(tupl);
                }
                else {
                    delete tupl;
                }
                
                // save the nodes for the next tree level
                addNextNode(curNode->left, curNode->val, newLength);
                addNextNode(curNode->right, curNode->val, newLength);
            }
            
            if (vCandidates.size() == 1) {
                delete_vector_values(vCandidates);
                return false; // values are not on the same tree level
            }
            if (vCandidates.size() == 2) {
                int parent1 = get<1>(*(vCandidates[0]));
                int parent2 = get<1>(*(vCandidates[1]));
                
                delete_vector_values(vCandidates);
                if (parent1 == parent2)
                    return false;
                else
                    return true;
            }
            
            rowLength = newLength;
        }
        
        return false; //values not found in a tree at all
    }
};
