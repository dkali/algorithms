// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/

// One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

//      _9_
//     /   \
//    3     2
//   / \   / \
//  4   1  #  6
// / \ / \   / \
// # # # #   # #
// For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

// Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

// Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

// You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

// Example 1:
// "9,3,4,#,#,1,#,#,2,#,6,#,#"
// Return true

// Example 2:
// "1,#"
// Return false

// Example 3:
// "9,#,#,1"
// Return false

#include <iostream>
#include <stack>

using namespace std;

class Solution {
private:
    int cursor;
    string *input_str;
    
    string getNum() {
        string num = "";
        for (; cursor < input_str->size(); cursor++) {
            if (input_str->at(cursor) != ',')
                num += input_str->at(cursor);
            else {
                cursor++;
                break;
            }
        }
        return num;
    }
    
public:
    Solution() {
        cursor = 0;
        input_str = nullptr;
    }
    
    bool isValidSerialization(string preorder) {
        input_str = &preorder;
        int expected_left = 1, expected_right = 0;
        bool goLeft = true;
        string root = "";
        while (cursor < preorder.size()) {
            string node = getNum();
            
            //check if starting from null node
            if (root == "") {
                root = node;
                if (root == "#" && cursor <= preorder.size() - 1)
                    return false;
            }

            if (goLeft)
                expected_left--;
            else {
                expected_right--;
                goLeft = true;
            }
            
            if (node != "#") {
                expected_left++;
                expected_right++;
            }
            else
                goLeft = false;
            
            //check for leafs after null node
            if (goLeft == false && expected_left == 0 && expected_right == 0 && cursor != preorder.size())
                return false;
        }
        
        return expected_left == 0 && expected_right == 0;
    }
};