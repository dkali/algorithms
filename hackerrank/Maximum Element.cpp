
// https://www.hackerrank.com/challenges/maximum-element/problem

// You have an empty sequence, and you will be given  queries. Each query is one of these three types:

// 1 x  -Push the element x into the stack.
// 2    -Delete the element present at the top of the stack.
// 3    -Print the maximum element in the stack.

// Input Format
// The first line of input contains an integer, . The next  lines each contain an above mentioned query. (It is guaranteed that each query is valid.)

// Output Format
// For each type 3 query, print the maximum element in the stack on a new line.

// Sample Input
// 10
// 1 97
// 2
// 1 20
// 2
// 1 26
// 1 20
// 2
// 3
// 1 91
// 3

// Sample Output
// 26
// 91

#include <iostream>
#include <sstream>
#include <stack>
#include <climits>
#include <tuple>

using namespace std;

int main(int argc, const char * argv[]) {
    int steps;
    string input_str;
//    tuple<int, int> - val, current_max
    stack<tuple<int, int>> storage;
    
    getline(cin, input_str);
    stringstream(input_str) >> steps;
    int current_max = INT_MIN;
    
    while (steps-- > 0) {
        getline(cin, input_str);
        istringstream iss(input_str);
        
        string cmd, param;
        iss >> cmd;
        
        switch (stoi(cmd)) {
            case 1: { //push
                iss >> param;
                int val = stoi(param);
                if (val > current_max) current_max = val;
                tuple<int, int> tup (val, current_max);
                storage.push(tup);
            }
            break;
                
            case 2: { //pop
                storage.pop();
                if (storage.size() > 0) {
                    tuple<int, int> tup = storage.top();
                    current_max = get<1>(tup);
                }
                else
                    current_max = INT_MIN;
            }
            break;
                
            case 3: { //print max
                printf("%d\n", current_max);
            }
            break;
        }
    }
    
    return 0;
}

