//https://leetcode.com/problems/number-of-recent-calls/description/

// Write a class RecentCounter to count recent requests.

// It has only one method: ping(int t), where t represents some time in milliseconds.

// Return the number of pings that have been made from 3000 milliseconds ago until now.

// Any ping with time in [t - 3000, t] will count, including the current ping.

// It is guaranteed that every call to ping uses a strictly larger value of t than before.

 

// Example 1:

// Input: inputs = ["RecentCounter","ping","ping","ping","ping"], inputs = [[],[1],[100],[3001],[3002]]
// Output: [null,1,2,3,3]
 

// Note:

// Each test case will have at most 10000 calls to ping.
// Each test case will call ping with strictly increasing values of t.
// Each call to ping will have 1 <= t <= 10^9.


#include <iostream>

using namespace std;

class Node {
public:
    Node* next;
    int time_stamp;
    
    Node(int ts) {
        time_stamp = ts;
        next = nullptr;
    }
};

class RecentCounter {
private:
    int limit;
    int count;
    Node* head;
    Node* tail;
    
public:
    RecentCounter() {
        limit = 3000;
        count = 0;
        head = tail = nullptr;
    }
    
    int ping(int t) {
        //insert new node
        if (head == nullptr) {
            head = tail = new Node(t);
        }
        else {
            Node* new_node = new Node(t);
            tail->next = new_node;
            tail = new_node;
        }
        
        count += 1;
        
        //count the nodes within given timeframe
        while (head->time_stamp + limit < t) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            count -= 1;
        }
        
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
