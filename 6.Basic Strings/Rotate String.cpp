// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.



// A shift on s consists of moving the leftmost character of s to the rightmost position.



// For example, if s = "abcde", then it will be "bcdea" after one shift.


// Example 1

// Input : s = "abcde" , goal = "cdeab"

// Output : true

// Explanation :

// After performing 2 shifts we can achieve the goal string from string s.

// After first shift the string s is => bcdea

// After second shift the string s is => cdeab.

// Example 2

// Input : s = "abcde" , goal = "adeac"

// Output : false

// Explanation :

// Any number of shift operations cannot convert string s to string goal.

// Constraints

// 1 <= s.length <= 100
// 1 <= goal.length <= 100
// s and goal consist of only lowercase English letters.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string& s, string& goal) {
    // Strings must be same length to be rotations of each other
        if (s.length() != goal.length()) {
            return false;  
        }
        // Try all possible rotations of s
        for (int i = 0; i < s.length(); i++) {
            string rotated = s.substr(i) + s.substr(0, i);  
            if (rotated == goal) {
                return true;  
            }
        }
        return false;  
    }
};

int main() {
    Solution sol;
    string s = "abcde";
    string goal = "cdeab";
    cout << (sol.rotateString(s, goal) ? "true" : "false") << endl;  
    s = "abcde";
    goal = "abced";
    cout << (sol.rotateString(s, goal) ? "true" : "false") << endl;  
    return 0;
}
