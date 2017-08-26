// https://leetcode.com/problems/top-k-frequent-elements

// Given a non-empty array of integers, return the k most frequent elements.

// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].

// Note: 
// You may assume k is always valid, 1 ? k ? number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class MyPair {
public:
  int _digit, _frequency;

  MyPair(int d, int f) {
    _digit = d;
    _frequency = f;
  }
};

class MyComparison
{
public:
  MyComparison()
  {
  }

  bool operator() (const MyPair& lhs, const MyPair& rhs) const
  {
    return (lhs._frequency < rhs._frequency);
  }
};

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    long long_max = 32767*2;
    int int_max = 32767;
    int vector_size = long_max;
    vector<long> map;

    for (int i = 0; i <= vector_size; i++) {
      map.push_back(0);
    }

    // find frequency
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      map[*it + int_max]++;
    }

    vector<MyPair> mp;
    for (int i = 0; i <= vector_size; i++) {
      MyPair p(i, map[i]);
      mp.push_back(p);
    }

    // find top
    priority_queue<MyPair, vector<MyPair>, MyComparison> my_pq (mp.begin(), mp.end());

    
    vector<int> result;
    for (int i = 0; i < k; i++) {
      result.push_back(my_pq.top()._digit - int_max);
      my_pq.pop();
    }
    
    return result;
  }
};
// ==============================================



// https://leetcode.com/problems/top-k-frequent-elements/#/description

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class MyComparison
{
public:
  MyComparison() {}
  
  bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const
  {
    return (lhs.second < rhs.second);
  }
};

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> my_map;

    // find frequency
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      if (my_map.find(*it) == my_map.end()) {
        my_map[*it] = 1;
      }
      else {
        my_map[*it]++;
      }
    }

    // find top
    //priority_queue<pair<int, int>, map<int, int>, MyComparison> my_pq (my_map.begin(), my_map.end());
    priority_queue<pair<int, int>, map<int, int>, MyComparison> my_pq;
    for (auto it = my_map.begin(); it != my_map.end(); ++it) {
      my_pq.push(*it);
    }

    vector<int> result;
    for (int i = 0; i < k; i++) {
      result.push_back(my_pq.top().first);
      my_pq.pop();
    }
    
    return result;
  }
};
