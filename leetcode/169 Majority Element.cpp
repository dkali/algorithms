// https://leetcode.com/problems/majority-element

// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
 
using namespace std;
 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;
 
        for (auto it = nums.begin(); it != nums.end(); ++it){
            if (freq.find(*it) == freq.end()){
                freq[*it] = 1;
            }
            else{
                freq[*it]++;
            }
        }
 
        int limit = nums.size()/2;
        int majorityElement = 0;
        for (auto it = freq.begin(); it != freq.end(); ++it){
            if (it->second > limit){
                majorityElement = it->first;
                break;
            }
        }
 
        return majorityElement;
    }
};