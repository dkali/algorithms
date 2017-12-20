// https://leetcode.com/problems/longest-consecutive-sequence/description/

// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

// Your algorithm should run in O(n) complexity.

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        map<int, int> my_map;
        for (int num : nums) {
            my_map.insert(pair<int, int>(num, 1));
        }
        
        int max_len = 0, cur_len = 1;
        int *prev = nullptr;
        for (auto it = my_map.begin(); it != my_map.end(); ++it) {
            if (prev == nullptr)
                prev = new int(it->first);
            else {
                if (*prev + 1 == it->first)
                    cur_len++;
                else{
                    if (cur_len > max_len)
                        max_len = cur_len;
                    cur_len = 1;
                }
                *prev = it->first;
            }
        }
        if (cur_len > max_len)
            max_len = cur_len;
        
        delete prev;
        return max_len;
    }
};
