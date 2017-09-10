// https://leetcode.com/problems/swap-nodes-in-pairs

// Given a linked list, swap every two adjacent nodes and return its head.

// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *newHead = head->next == nullptr ? head : head->next;
        ListNode *prevNode = nullptr;
        
        while (head){
            //do we have a pair?
            if (head->next == nullptr) return newHead;
            ListNode *tmp = head->next;
            head->next = tmp->next;
            tmp->next = head;
            if (prevNode != nullptr) prevNode->next = tmp;
            prevNode = head;
            head = head->next;
        }

        return newHead;
    }
};