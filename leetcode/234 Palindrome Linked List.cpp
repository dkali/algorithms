// https://leetcode.com/problems/palindrome-linked-list

// Given a singly linked list, determine if it is a palindrome.

// Follow up:
// Could you do it in O(n) time and O(1) space?

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
    bool goDeeper(ListNode **head, ListNode *cur){
        bool result = true;
 
        if (cur->next != nullptr){
            result &= goDeeper(head, cur->next);
        }
 
        if (cur->val != (*head)->val){
            return false;
        }
        else{
            *head = (*head)->next;
        }
 
        return result;
    }
 
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr)
            return true;
        else{
            ListNode *cur = head;
            return goDeeper(&head, cur);
        }
    }
};