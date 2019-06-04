// https://leetcode.com/problems/asteroid-collision/

// We are given an array asteroids of integers representing asteroids in a row.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

// Example 1:
// Input: 
// asteroids = [5, 10, -5]
// Output: [5, 10]
// Explanation: 
// The 10 and -5 collide resulting in 10.  The 5 and 10 never collide.

// Example 2:
// Input: 
// asteroids = [8, -8]
// Output: []
// Explanation: 
// The 8 and -8 collide exploding each other.

// Example 3:
// Input: 
// asteroids = [10, 2, -5]
// Output: [10]
// Explanation: 
// The 2 and -5 collide resulting in -5.  The 10 and -5 collide resulting in 10.

// Example 4:
// Input: 
// asteroids = [-2, -1, 1, 2]
// Output: [-2, -1, 1, 2]
// Explanation: 
// The -2 and -1 are moving left, while the 1 and 2 are moving right.
// Asteroids moving the same direction never meet, so no asteroids will meet each other.

// Note:
// The length of asteroids will be at most 10000.
// Each asteroid will be a non-zero integer in the range [-1000, 1000]..

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ret;
        deque<int> deq;
        
        for (int current : asteroids) {
            if (deq.empty() || current > 0)
                deq.push_back(current);
            else {
                while (!deq.empty()) {
                    // when direction is toward each other
                    if (deq.back() > 0 && current < 0) {
                        // eleminate each other
                        if (deq.back() + current == 0) {
                            deq.pop_back();
                            break;
                        }
                        // negative eats positive
                        else if (deq.back() + current < 0) {
                            deq.pop_back();
                            if (deq.empty()) {
                                deq.push_back(current);
                                break;
                            }
                        }
                        else // positive beats negative
                            break;
                    }
                    else { // same direction
                        deq.push_back(current);
                        break;
                    }
                }
            }
        }
        
        while (!deq.empty()) {
            ret.push_back(deq.front());
            deq.pop_front();
        }
        return ret;
    }
};