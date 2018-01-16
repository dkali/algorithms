// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/

// Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.

// Example:

// Input:
// [1,2,3]

// Output:
// 3

// Explanation:
// Only three moves are needed (remember each move increments two elements):

// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]


//===== TLE, not accepted ======
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void print_vector(vector<int> &v) {
        for (int n : v)
            printf("%d ", n);
        printf("\n");
    }
    
public:
    int minMoves(vector<int>& nums) {
        int max = INT_MIN;
        int moves = (int)nums.size() - 1;
        int counter = 0;
        int moves_tmp = moves;
        bool do_shit = true;
        
        for (int n : nums)
            if (n > max) max = n;
        
        do {
            moves_tmp = moves;
            vector<int> history(nums.size(), 1);
            do_shit = false;
            
            for (int pos = 0; pos < nums.size(); pos++) {
                if (moves_tmp == 0) break;
                
                if (nums[pos] < max) {
                    nums[pos]++;
                    history[pos]--;
                    moves_tmp--;
                    do_shit = true;
                }
                else if (nums[pos] > max)
                    max = nums[pos];
            }
            
            int ind = 0;
            while (moves_tmp > 0) {
                if (history[ind] == 1) {
                    nums[ind]++;
                    moves_tmp--;
                }
                ind++;
            }
            
                counter++;
//            print_vector(nums);
        } while (do_shit);
        
        return counter - 1;
    }
};