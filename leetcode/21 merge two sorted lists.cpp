// https://leetcode.com/problems/merge-two-sorted-lists

// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    void setNode(ListNode **head, ListNode **current, ListNode **node){
        if (*head == nullptr){
            *head = *node;
            *current = *node;
        }
        else{
            (*current)->next = *node;
            *current = *node;
        }

        (*node) = (*node)->next;
    }

public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *current = nullptr;

        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr){
                setNode(&head, &current, &l2);
                continue;
            }

            if (l2 == nullptr){
                setNode(&head, &current, &l1);
                continue;
            }

            if (l1->val < l2->val){
                setNode(&head, &current, &l1);
            }
            else{
                setNode(&head, &current, &l2);
            }
        }

        return head;
    }
};