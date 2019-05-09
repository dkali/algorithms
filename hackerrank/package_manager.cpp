#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <set>
#include <queue>

using namespace std;

class Solution {
private:
    map<string, vector<string>> pkg_dependency;
    map<string, set<string>> pkg_installed;
    
    //because fuck C++ that doesn't have this built in function
    vector<string> split(string str, string delimeter) {
        vector<string> tokens;
        long start = 0U;
        auto end = str.find(delimeter);
        
        while (end != string::npos)
        {
            tokens.push_back(str.substr(start, end - start));
            start = end + delimeter.length();
            end = str.find(delimeter, start);
        }
        
        tokens.push_back(str.substr(start, end));
        return tokens;
    }
    
    void depend(vector<string> tokens) {
        vector<string> dep_list;
        for (int i = 2; i < tokens.size(); i++)
            dep_list.push_back(tokens[i]);
        pkg_dependency.insert(pair<string, vector<string>>(tokens[1], dep_list));
    }
    
    void install(string package) {
        stack<string> installation_stack;
        installation_stack.push(package);
        
        while (!installation_stack.empty()) {
            string cur_pkg = installation_stack.top();
            
            // package already installed, do nothing
            if (pkg_installed.find(cur_pkg) != pkg_installed.end()) {
                installation_stack.pop();
                continue;
            }
            
            // if we don't have the dependencies for that package, then install them first
            bool dependencies_resolved = true;
            for (string dep_pkg : pkg_dependency[cur_pkg]) {
                if (pkg_installed.find(dep_pkg) == pkg_installed.end()) {
                    installation_stack.push(dep_pkg);
                    dependencies_resolved = false;
                }
                else
                    pkg_installed[dep_pkg].insert(package);
            }
            
            if (dependencies_resolved) {
                set<string> who_using_this_package;
                pkg_installed.insert(pair<string,set<string>>(cur_pkg, who_using_this_package));
                printf("Installing %s\n", cur_pkg.c_str());
                installation_stack.pop();
            }
        }
    }
    
    void remove(string package) {
        // remove package, and all packages he is using
        queue<string> removal_queue;
        removal_queue.push(package);
        while (!removal_queue.empty()) {
            string cur_pkg = removal_queue.front();
            removal_queue.pop();
            
            bool still_used = false;
            for (string tmp : pkg_installed[cur_pkg]) {
                if (pkg_installed.find(tmp) != pkg_installed.end()) {
                    still_used = true;
                    break;
                }
            }
            
            if (still_used) {
                printf("%s is still needed\n", cur_pkg.c_str());
                continue;
            }
            else {
                pkg_installed.erase(cur_pkg);
                printf("Removing %s\n", cur_pkg.c_str());
            }
            
            for (string dep_pkg : pkg_dependency[cur_pkg])
                removal_queue.push(dep_pkg);
        }
    }
    
    void list() {
        printf("---list---\n");
        for (pair<string,set<string>> pair : pkg_installed) {
            printf("%s\n",pair.first.c_str());
        }
        printf("----------\n");
    }
    
public:
    void command(string cmd_line) {
        vector<string> tokens = split(cmd_line, " ");
        if (tokens[0] == "DEPEND")
            depend(tokens);
        else if (tokens[0] == "INSTALL")
            install(tokens[1]);
        else if (tokens[0] == "REMOVE")
            remove(tokens[1]);
        else if (tokens[0] == "LIST")
            list();
    }
};

int main() {
    Solution sol;
    sol.command("DEPEND WarCraft3 DX9");
    sol.command("DEPEND StarCraft BattleNet DX9");
    sol.command("DEPEND BattleNet ClientUpdater");
    
    sol.command("INSTALL WarCraft3");
    sol.command("INSTALL StarCraft");
    
    sol.command("LIST");
    
    sol.command("REMOVE BattleNet");
    sol.command("REMOVE WarCraft3");
    
    sol.command("LIST");
    
    sol.command("REMOVE StarCraft");
    
    sol.command("LIST");
    
    return 0;
}
