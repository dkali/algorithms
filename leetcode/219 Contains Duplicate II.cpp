// https://leetcode.com/problems/contains-duplicate-ii

// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> memory; // digit, last known index
        for (int i = 0; i < nums.size(); i++){
            if (memory.find(nums[i]) == memory.end()){
                memory[nums[i]] = i;
            }
            else{
                if ((i - memory[nums[i]]) <= k){
                    return true;
                }
                else{
                    memory[nums[i]] = i;
                }
            }
        }
 
        return false;
    }
};