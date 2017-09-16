// https://leetcode.com/problems/largest-number/description/

// Given a list of non negative integers, arrange them such that they form the largest number.

// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

// Note: The result may be very large, so you need to return a string instead of an integer.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto my_comp = [this](string lstr, string rstr){
            int il = 0, ir = 0;
            int lsize = lstr.size(), rsize = rstr.size();
            while (il < lsize && ir < rsize){
                if (lstr[il] == rstr[ir]){
                    if (il == lsize - 1 && ir == rsize - 1) break;
                    il = il + 1 == lsize ? 0 : il + 1;
                    ir = ir + 1 == rsize ? 0 : ir + 1;
                }
                else{
                    return lstr[il] < rstr[ir];
                }
            }

            return true;
        };
        priority_queue<string, vector<string>, decltype(my_comp)> q(my_comp);
        for (int n : nums){q.push(to_string(n));}

        string str = "";
        bool trim_zeroes = true;
        while (!q.empty()){
            string s = q.top();
            q.pop();
            if (s == "0" && trim_zeroes)
                continue;
            else if (s != "0"){
                trim_zeroes = false;
            }
            str += s;
        }
        str = str == "" ? "0" : str;
        return str;
    }
};
