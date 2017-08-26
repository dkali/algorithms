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
};

int main() {
    Solution sol;
    vector<string> inputV = {"0", "1", "2", "3", "4", "5", "6"};
    TreeLinkNode *r = sol.initTree<TreeLinkNode>(inputV);
    sol.connect(r);
    return 0;
}