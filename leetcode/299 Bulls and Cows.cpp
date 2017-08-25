// https://leetcode.com/problems/bulls-and-cows

// You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

// For example:

// Secret number:  "1807"
// Friend's guess: "7810"
// Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
// Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

// Please note that both secret number and friend's guess may contain duplicate digits, for example:

// Secret number:  "1123"
// Friend's guess: "0111"
// In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
// You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

#include <iostream>
#include <algorithm>
 
using namespace std;
 
class Solution {
private:
    void analyzeFrequency(string& word, int **freq, int alphabet_size){
        for (int i = 0; i < alphabet_size; i++){
            (*freq)[i] = 0;
        }
 
        for (char c : word){
            if (c != '*'){
                (*freq)[c - 48]++;
            }
        }
    }
 
public:
    string getHint(string secret, string guess) {
        // first find all bulls
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); i++){
            if (secret[i] == guess[i]){
                bulls++;
                secret[i] = '*';
                guess[i] = '*';
            }
        }
 
        //find all cows
        int alphabet_size = 10;
        int *freq_s = new int[alphabet_size];
        int *freq_g = new int[alphabet_size];
 
        analyzeFrequency(secret, &freq_s, alphabet_size);
        analyzeFrequency(guess, &freq_g, alphabet_size);
 
        for (int i = 0; i < alphabet_size; i++){
            cows += min(freq_s[i], freq_g[i]);
        }
 
        delete[] freq_g;
        delete[] freq_s;
 
        //construct the resulted string
        string result = to_string(bulls) + "A" + to_string(cows) + "B";
        return result;
    }
};