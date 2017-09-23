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
#include <algorithm>

using namespace std;

class Solution {
private:
    void add_coin(int coin_index, vector<int> &coins, int &summ){
        summ += coins[coin_index];
        count->at(coin_index)++;
    }

    bool extract_coin(int coin_index, vector<int> &coins, int &summ) {
        if (count->at(coin_index) > 0){
            count->at(coin_index)--;
            summ -= coins[coin_index];
            return true;
        }
        return false;
    }

    bool extract_prev_coin(int coin_index, vector<int> &coins, int &summ) {
        coin_index++;
        while (coin_index < coins.size()){
            if (count->at(coin_index) > 0){
                count->at(coin_index)--;
                summ -= coins[coin_index];
                return true;
            }
            else
                coin_index++;
        }
        return false;
    }

public:
    vector<int> *count;

    Solution(){
        count = new vector<int>;
    }
    ~Solution(){
        delete count;
    }

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int index = coins.size() - 1;
        int summ = 0;

        for (int i = 0; i < coins.size(); i++){
            count->push_back(0);
        }

        while (summ != amount){
            if (summ < amount){
                add_coin(index, coins, summ);
            }
            else {
                if (false == extract_coin(index, coins, summ))
                    return -1;
                if (index == 0){
                    if (false == extract_prev_coin(index, coins, summ))
                        return -1; // no combinations available
                }
                if (index > 0)
                    index--;
            }
        }

        int cnt = 0;
        for (int i : *count){cnt += i;};
        return cnt;
    }
};

int main(){
    Solution sol;
    vector<int> v = {186,419,83,408};
    int target = 6249; //20
    cout << sol.coinChange(v, target) << endl;

    return 0;
}