#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /////////// utility
    template<class T>
    T *initTree(vector<string> vectorStr) {
        auto *curLine = new queue<T *>, *nextLine = new queue<T *>;
        T *root = nullptr, *current = nullptr;
        int pos = 0;
        root = new T(stoi(vectorStr[pos++], nullptr, 10));
        curLine->push(root);

        while (pos < vectorStr.size()) {
            while (!curLine->empty()) {
                T *node = curLine->front();
                curLine->pop();

                if (pos >= vectorStr.size()) break;
                if (vectorStr[pos] != "#") {
                    node->left = new T(stoi(vectorStr[pos], nullptr, 10));
                    nextLine->push(node->left);
                }
                pos++;

                if (pos >= vectorStr.size()) break;
                if (vectorStr[pos] != "#") {
                    node->right = new T(stoi(vectorStr[pos], nullptr, 10));
                    nextLine->push(node->right);
                }
                pos++;
            }

            if (!nextLine->empty()) {
                delete curLine;
                curLine = nextLine;
                nextLine = new queue<T *>;
            }
        }

        return root;
    }

////////////////////////////////////////
    // Decodes your encoded data to tree.
    template<class T>
    T* deserialize(string data) {
        T *root = nullptr;
        int start_pos = 0;
        queue<T*> q;

        string d = get_digit(data, start_pos);
        if (d == "#")
            return root;
        root = new T(stoi(d));
        q.push(root);

        while (start_pos < data.size()){
            T *n = q.front();
            q.pop();
            string ln = get_digit(data, start_pos);
            string rn = get_digit(data, start_pos);
            if (ln != "#"){
                n->left = new T(stoi(ln));
                q.push(n->left);
            }
            if (rn != "#"){
                n->right = new T(stoi(rn));
                q.push(n->right);
            }
        }

        return root;
    }

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

int main() {
    Solution sol;
    vector<string> inputV = {"0", "1", "2", "3", "4", "5", "6"};
    TreeLinkNode *r = sol.initTree<TreeLinkNode>(inputV);

    string str = "1,2,3,#,#,4,5,#,#,#,#";
    sol.deserialize<TreeNode>(s);
    return 0;
}