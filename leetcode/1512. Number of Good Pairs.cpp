// Given an array of integers nums.

// A pair (i,j) is called good if nums[i] == nums[j] and i < j.

// Return the number of good pairs.

// Example 1:
// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

// Example 2:
// Input: nums = [1,1,1,1]
// Output: 6
// Explanation: Each pair in the array are good.

// Example 3:
// Input: nums = [1,2,3]
// Output: 0
 
// Constraints:
// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  int numIdenticalPairs(vector<int>& nums) {
    int total_count = 0;
    map<int, int> accountant;
    
    for (int i : nums) {
      if (accountant.find(i) == accountant.end()) {
        accountant.insert(pair<int,int>(i, 1));
      } else {
        accountant[i]++;
        total_count += (accountant[i] - 1);
      }
    }
    
    return total_count;
  }
};