// https://leetcode.com/problems/coin-change/description/

// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// Example 1:
// coins = [1, 2, 5], amount = 11
// return 3 (11 = 5 + 5 + 1)

// Example 2:
// coins = [2], amount = 3
// return -1.

// Note:
// You may assume that you have an infinite number of each kind of coin.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void print_dp(int *dp, int coin_val, int amount){
        printf("coin %d:", coin_val);
        for (int i = 0; i <= amount; i++){
            printf("\t%d", dp[i]);
        }
        printf("\n");
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        
        if (amount == 0)
            return 0;
        if (amount < coins[0])
            return -1;
        
        int *dp = new int[amount + 1];
        for (int i = 0; i <= amount; i++) {dp[i] = 0;}
        
        for (int coin_val : coins){
            if (coin_val > amount)
                break;
            
            dp[coin_val] = 1;
            for (int target = coin_val + 1; target <= amount; target++){
                if (dp[target - coin_val] != 0)
                    if (dp[target] == 0 || (dp[target] > dp[target - coin_val] + 1))
                        dp[target] = dp[target - coin_val] + 1;
            }
            //print_dp(dp, coin_val, amount);
        }
        
        int result = dp[amount] == 0 ? -1 : dp[amount];
        delete[] dp;
        return result;
    }
};