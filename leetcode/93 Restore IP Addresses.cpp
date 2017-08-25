// https://leetcode.com/problems/restore-ip-addresses
 
// Given a string containing only digits, restore it by returning all possible valid IP address combinations.

// For example:
// Given "25525511135",

// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

#include <iostream>
#include <vector>
 
using namespace std;
 
class Solution {
private:
    void bactrack(string &s, string ip_addr, int pos, int level, vector<string> &result){
        if (level == 4 && pos == s.size())
            result.push_back(ip_addr);
        if (pos >= s.size() || level > 4)
            return;
 
        string tmp;
        for (int i = 1; i < 4; i++){
            tmp = s.substr(pos, i);
            if (stoi(tmp, nullptr, 10) <= 255){
                bool exit_cycle = (tmp == "0");
                if (ip_addr != "")
                    tmp = ip_addr + "." + tmp;
                bactrack(s, tmp, pos + i, level + 1, result);
                if (exit_cycle) break;
            }
        }
    }
 
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
 
        if (s.size() <= 12)
            bactrack(s, "", 0, 0, result);
        return result;
    }
};