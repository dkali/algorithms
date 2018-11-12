// https://leetcode.com/problems/unique-email-addresses/description/

// Every email consists of a local name and a domain name, separated by the @ sign.

// For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

// Besides lowercase letters, these emails may contain '.'s or '+'s.

// If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

// If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)

// It is possible to use both of these rules at the same time.

// Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 

 

// Example 1:

// Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
// Output: 2
// Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
 

// Note:

// 1 <= emails[i].length <= 100
// 1 <= emails.length <= 100
// Each emails[i] contains exactly one '@' character.

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
private:
    vector<string> splitString(string& str, char delimeter) {
        vector<string> results;
        string token = "";
        
        for (char c : str) {
            if (c == delimeter && token != "") {
                results.push_back(token);
                token = "";
            }
            else
            {
                token += c;
            }
        }
        if (token != "")
            results.push_back(token);
        return results;
    }
    
    string process_local_name(string& local_name) {
        int plus_pos = -1;
        for (int pos = int(local_name.size() - 1); pos >= 0; pos--) {
            if (local_name[pos] == '.') {
                local_name.erase(pos, 1);
                plus_pos -= 1;
            }
            if (local_name[pos] == '+')
                plus_pos = pos;
        }
        
        if (plus_pos > 0) {
            string new_name = "";
            for (int pos = 0; pos < plus_pos; pos ++)
                new_name.push_back(local_name[pos]);
            local_name = new_name;
        }
        
        return local_name;
    }
    
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, set<string>> sorted_email;
        
        //process incoming email addresses
        for (string email : emails) {
            vector<string> parts = splitString(email, '@');
            string local_name = parts[0];
            string doman_name = parts[1];
            
            local_name = process_local_name(local_name);
            
            if (sorted_email.find(doman_name) == sorted_email.end()) {
                set<string> domain_emails;
                domain_emails.insert(local_name);
                sorted_email[doman_name] = domain_emails;
            }
            else{
                sorted_email[doman_name].insert(local_name);
            }
        }

        //count the resulting unique email adresses
        int unique = 0;
        for (auto it = sorted_email.begin(); it != sorted_email.end(); ++it)
            unique += it->second.size();

        return unique;
    }
};