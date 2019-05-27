// https://leetcode.com/problems/last-stone-weight/

// We have a collection of rocks, each rock has a positive integer weight.
// Each turn, we choose the two heaviest rocks and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

// If x == y, both stones are totally destroyed;
// If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
// At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

// Example 1:
// Input: [2,7,4,1,8,1]
// Output: 1

// Explanation: 
// We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
// we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
// we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
// we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 
// Note:
// 1 <= stones.length <= 30
// 1 <= stones[i] <= 1000

// Variant 1: priority queue
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int val : stones)
            pq.push(val);
        
        while (!pq.empty()) {
            if (pq.size() == 1)
                break;
            
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if (x > y) {
                pq.push(x - y);
            }
        }
        
        if (pq.size() == 1)
            return pq.top();
        else
            return 0;
    }
};


//Variant 2: make_heap over the vector, inplace solution
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
    int get_top(vector<int>& stones) {
        int x = stones.front();
        pop_heap(stones.begin(), stones.end());
        stones.pop_back();
        return x;
    }
    
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        
        while (!stones.empty()) {
            if (stones.size() == 1)
                break;
            
            int x = get_top(stones);
            int y = get_top(stones);
            if (x > y) {
                stones.push_back(x - y);
                push_heap(stones.begin(), stones.end());
            }
        }
        
        if (stones.size() == 1)
            return stones.front();
        else
            return 0;
    }
};
