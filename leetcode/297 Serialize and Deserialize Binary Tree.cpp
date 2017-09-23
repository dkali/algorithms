// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// For example, you may serialize the following tree

//     1
//    / \
//   2   3
//      / \
//     4   5
// as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *n = q.front();
            q.pop();
            if (n){
                str += to_string(n->val) + ',';
                q.push(n->left);
                q.push(n->right);
            }
            else
                str += "#,";
        }

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root = nullptr;
        int start_pos = 0;
        queue<TreeNode*> q;

        string d = get_digit(data, start_pos);
        if (d == "#")
            return root;
        root = new TreeNode(stoi(d));
        q.push(root);

        while (start_pos < data.size()){
            TreeNode *n = q.front();
            q.pop();
            string ln = get_digit(data, start_pos);
            string rn = get_digit(data, start_pos);
            if (ln != "#"){
                n->left = new TreeNode(stoi(ln));
                q.push(n->left);
            }
            if (rn != "#"){
                n->right = new TreeNode(stoi(rn));
                q.push(n->right);
            }
        }

        return root;
    }

private:
    string get_digit(string &data, int &start_pos){
        string digit = "";
        for (; start_pos < data.size(); start_pos++){
            if (data[start_pos] != ',')
                digit += data[start_pos];
            else
                break;
        }
        start_pos++;
        return digit;
    }
};