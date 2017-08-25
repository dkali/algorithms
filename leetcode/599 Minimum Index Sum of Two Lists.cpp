// https://leetcode.com/problems/minimum-index-sum-of-two-lists
 
#include <iostream>
#include <vector>
#include <map>
#include <limits>
 
using namespace std;
 
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        map<string, int> *tmpTable = new map<string, int>;
        map<string, int> *common = new map<string, int>;
 
        //build tmpTable
        for (int i = 0; i < list1.size(); i++){(*tmpTable)[list1[i]] = i;}
        for (int i = 0; i < list2.size(); i++){
            if (tmpTable->find(list2[i]) != tmpTable->end()){
                (*common)[list2[i]] = tmpTable->at(list2[i]) + i;
            }
        }
        delete tmpTable;
 
        //find minimum distance
        int min = INT_MAX;
        for (auto it = common->begin(); it != common->end(); ++it){
            if (it->second == min){
                result.push_back(it->first);
            }
            if (it->second < min){
                result.clear();
                result.push_back(it->first);
                min = it->second;
            }
        }
        delete common;
 
        return result;
    }
};