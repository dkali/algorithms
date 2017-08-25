// https://leetcode.com/problems/intersection-of-two-arrays-ii
 
// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

// Note:
// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.

#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> bucket;
        vector<int> result;
        if (nums1.size() == 0 || nums2.size() == 0)
            return result;
 
        for (int i = 0; i < nums1.size(); i++){
            bucket[nums1[i]]++;
        }
 
        for (int i = 0; i < nums2.size(); i++){
            if (bucket[nums2[i]] > 0){
                bucket[nums2[i]]--;
                result.push_back(nums2[i]);
            }
        }
 
        return result;
    }
};