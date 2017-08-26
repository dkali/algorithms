// https://leetcode.com/problems/reverse-linked-list

// Reverse a singly linked list.

// A linked list can be reversed either iteratively or recursively. Could you implement both?

#include <iostream>
#include <stack>

using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
 public:
   ListNode* reverseList(ListNode* head) {
     stack<ListNode *> st;

     while (head != nullptr) {
       st.push(head);
       head = head->next;
     }

     head = nullptr;
     ListNode *curr_node = nullptr;
     while (!st.empty()) {
       if (head == nullptr) {
         head = st.top();
         head->next = nullptr;
         st.pop();
         curr_node = head;
       }
       else {
         curr_node->next = st.top();
         st.pop();
         curr_node = curr_node->next;
         curr_node->next = nullptr;
       }
     }

     return head;
   }
 };

// ==== constant memory solution ========

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
 public:
   ListNode* reverseList(ListNode* head) {
     ListNode *newHead = nullptr, *next = nullptr;

     while (head != nullptr) {
       next = head->next;
       head->next = newHead;
       newHead = head;
       head = next;
     }

     return newHead;
   }
 };