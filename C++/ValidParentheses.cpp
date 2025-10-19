// LeetCode 20: Valid Parentheses
// Solution using a stack
// Time Complexity: O(n)

#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> openBrackets;
        
        // Map to hold matching pairs
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            // If it's a closing bracket
            if (bracketMap.count(c)) {
                // Stack must not be empty, and top must match
                if (openBrackets.empty() || openBrackets.top() != bracketMap[c]) {
                    return false;
                }
                openBrackets.pop(); // We found a match, pop it
            } 
            // If it's an opening bracket
            else {
                openBrackets.push(c);
            }
        }
        
        // If the stack is empty, all brackets were matched
        return openBrackets.empty();
    }
};

// Main function to test the code
int main() {
    Solution sol;
    string s1 = "()[]{}";
    string s2 = "([)]";
    string s3 = "{[]}";

    cout << "'" << s1 << "' is valid: " << (sol.isValid(s1) ? "true" : "false") << endl;
    cout << "'" << s2 << "' is valid: " << (sol.isValid(s2) ? "true" : "false") << endl;
    cout << "'" << s3 << "' is valid: " << (sol.isValid(s3) ? "true" : "false") << endl;

    return 0;
}
