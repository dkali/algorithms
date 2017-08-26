// https://leetcode.com/problems/add-two-numbers

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

#include <iostream>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *node = nullptr, *head = nullptr;
    int remnant = 0;

    while (l1 != nullptr && l2 != nullptr || remnant != 0) {
      int v1 = l1 == nullptr ? 0 : l1->val;
      int v2 = l2 == nullptr ? 0 : l2->val;
      
      int val = v1 + v2 + remnant;
      if (val > 9) {
        val -= 10;
        remnant = 1;
      }
      else {
        remnant = 0;
      }

      ListNode *n = new ListNode(val);

      if (head == nullptr) {
        head = n;
        node = n;
      }
      else {
        node->next = n;
        node = n;
      }

      if (l1 != nullptr)
        l1 = l1->next;
      if (l2 != nullptr)
        l2 = l2->next;
    }

    ListNode *tail = nullptr;
    if (l1 != nullptr)
      tail = l1;
    if (l2 != nullptr)
      tail = l2;

    if (tail != nullptr)
      node->next = tail;
    
    return head;
  }
};