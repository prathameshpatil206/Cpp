#include<bits/stdc++.h>
using namespace std;

// Optimized palindrome check using two pointers (no extra memory)
bool is_palindrome(const string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

// Pass original string by reference, use 'start' to track position
void partition(const string& s, int start, vector<string>& parts, vector<vector<string>>& ans) {
    // Base Case: If we have reached the end of the string, we found a valid partition
    if (start == s.size()) {
        ans.push_back(parts);
        return;
    }

    // Loop through the remaining string
    for (int i = start; i < s.size(); i++) {
        // If the substring from 'start' to 'i' is a palindrome
        if (is_palindrome(s, start, i)) {
            // Add it to our current path
            parts.push_back(s.substr(start, i - start + 1));
            
            // Recurse for the remaining part of the string
            partition(s, i + 1, parts, ans);
            
            // Backtrack
            parts.pop_back();
        }
    }
}

int main() {
    string s = "ababa";
    vector<string> parts;
    vector<vector<string>> ans;
    
    partition(s, 0, parts, ans);

    for (auto v : ans) {
        for (auto ele : v) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}