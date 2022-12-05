// https://leetcode.com/problems/merge-in-between-linked-lists/submissions/

// You are given two linked lists: list1 and list2 of sizes n and m respectively.
// Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
// The blue edges and nodes in the following figure indicate the result:

// Example 1:
// Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
// Output: [0,1,2,1000000,1000001,1000002,5]
// Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.

// Example 2:
// Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
// Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
// Explanation: The blue edges and nodes in the above figure indicate the result.

public class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int val=0, ListNode next=null) {
        this.val = val;
        this.next = next;
    }
}
 
public class Solution
{
    public ListNode MergeInBetween(ListNode list1, int a, int b, ListNode list2)
    {
        ListNode firstNode = list1;
        ListNode secondNode;

        // find from where we need to cut off the list range
        for (int ind = 0; ind < a - 1; ind++)
        {
            firstNode = firstNode.next;
        }

        // find where is the end of the range that we are cutting off
        secondNode = firstNode;
        for (int ind = a; ind <= b+1; ind++)
        {
            secondNode = secondNode.next;
        }

        // insert list 2
        firstNode.next = list2;

        // find the new tail
        while (firstNode.next != null)
        {
            firstNode = firstNode.next;
        }
        
        // apend the tail of the first list
        firstNode.next = secondNode;

        return list1;
    }
}