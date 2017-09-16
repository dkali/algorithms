#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    // lpos, rpos - array boundaries to form a section to sort
    void qsort(vector<int> &nums, int lpos, int rpos){
        if (lpos >= rpos) return;

        int ppos = (rpos + lpos)/2; //pivot position
        int l = lpos, r = rpos; //changed cursors
        while (l < r){
            if (nums[l] > nums[ppos])
                swap(nums[l], nums[ppos]);
            else
                l++;

            if (nums[r] < nums[ppos])
                swap(nums[r], nums[ppos]);
            else
                r--;
        }
        if (rpos - lpos == 1) return;
        qsort(nums, lpos, ppos);
        qsort(nums, ppos, rpos);
    }
};

int main(){
    Solution sol;
    vector<int> v = {3, 30, 34, 5, 9};
    sol.qsort(v, 0, v.size()-1);

    return 0;
}