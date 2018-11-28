// https://leetcode.com/problems/knight-dialer/description/

// A chess knight can move as indicated in the chess diagram below:
// ....

// This time, we place our chess knight on any numbered key of a phone pad (indicated above), and the knight makes N-1 hops.  Each hop must be from one key to another numbered key.

// Each time it lands on a key (including the initial placement of the knight), it presses the number of that key, pressing N digits total.

// How many distinct numbers can you dial in this manner?

// Since the answer may be large, output the answer modulo 10^9 + 7.

// Example 1:
// Input: 1
// Output: 10

// Example 2:
// Input: 2
// Output: 20

// Example 3:
// Input: 3
// Output: 46

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
private:
    void dp(char cur_digit, string constructed_number, int hops) {
        if (cur_digit != '*')
            constructed_number += cur_digit;
        
        if (hops > 0) {
            if (cur_digit == '*')
                for (int i = 0; i < 10; i++) {
                    dp('0' + i, constructed_number, hops - 1);
                }
            else {
                for (char new_digit : dp_baseline[cur_digit - '0'])
                    dp(new_digit, constructed_number, hops - 1);
            }
        }
        else {
            my_set.insert(constructed_number);
        }
    }
    
public:
    vector<vector<char>> dp_baseline;
    set<string> my_set;
    
    Solution() {
        dp_baseline = {{'4','6'}, {'6','8'}, {'7','9'}, {'4','8'}, {'3','9','0'}, {}, {'1','7','0'}, {'2','6'}, {'1','3'}, {'2','4'}};
    }
    
    int knightDialer(int hops) {
        dp('*', "", hops);
        return (int)my_set.size();
    }
};

// ================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    void dp(int cur_digit, int hops) {
        if (hops > 0) {
            if (cur_digit == -1)
                for (int i = 0; i < 10; i++) {
                    dp(i, hops - 1);
                }
            else {
                for (int new_digit : dp_baseline[cur_digit])
                    dp(new_digit, hops - 1);
            }
        }
        else {
            summ++;
        }
    }
    
public:
    vector<vector<int>> dp_baseline;
    int summ;
    
    Solution() {
        summ = 0;
        dp_baseline = {{4,6}, {6,8}, {7,9}, {4,8}, {3,9,0}, {}, {1,7,0}, {2,6}, {1,3}, {2,4}};
    }
    
    int knightDialer(int hops) {
        summ = 0;
        dp(-1, hops);
        return summ;
    }
};
