// https://leetcode.com/problems/merge-k-sorted-lists/description/

// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.


// ====== v1 25ms ======
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MyCompare{
public:
    bool operator() (const ListNode *left, const ListNode *right){
        return left->val > right->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, MyCompare> q;

        for (ListNode *n : lists){
            while (n != nullptr){
                q.push(n);
                n = n->next;
            }
        }

        ListNode *root = nullptr, *current = nullptr;
        while(!q.empty()){
            ListNode *n = q.top();
            q.pop();

            ListNode *new_node = new ListNode(n->val);
            if (root == nullptr){
                root = new_node;
                current = root;
            }
            else{
                current->next = new_node;
                current = new_node;
            }
        }

        return root;
    }
};



// === V2 179ms. too slow ===
#include <iostream>
#include <vector>
 
using namespace std;
 
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool merging = true;
 
        ListNode *root = nullptr, *current = nullptr;
        while (merging){
            int min_pos = INT_MAX, min_val = INT_MAX;
            for (int i = 0; i < lists.size(); i++){
                if (lists[i] != nullptr){
                    if (lists[i]->val < min_val){
                        min_pos = i;
                        min_val = lists[i]->val;
                    }
                }
            }
 
            if (min_pos == INT_MAX)
                return root;
 
            ListNode *n = new ListNode(min_val);
            if (root == nullptr){
                root = n;
                current = root;
            }else{
                current->next = n;
                current = n;
            }
            lists[min_pos] = lists[min_pos]->next;
            if (lists[min_pos] == nullptr)
                lists.erase(lists.begin() + min_pos);
        }
 
        return root;
    }
};
