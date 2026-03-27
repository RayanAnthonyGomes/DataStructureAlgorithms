// Given two strings s and t, return true if t is an anagram of s, and false otherwise.



// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


// Example 1

// Input : s = "anagram" , t = "nagaram"

// Output : true

// Explanation :

// We can rearrange the characters of string s to get string t as frequency of all characters from both strings is same.

// Example 2

// Input : s = "dog" , t = "cat"

// Output : false

// Explanation :

// We cannot rearrange the characters of string s to get string t as frequency of all characters from both strings is not same.
// Constraints

// 1 <= s.length , t.length <= 5*104
// s and t consist of only lowercase English letters

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool anagramStrings(string &s, string &t) {
        // Edge Cases
        if (s.length() != t.length()) return false;

        // To store the count of each character
        vector<int> count(26, 0);

        // Count occurence of each character in first string 
        for (char c : s) count[c - 'a']++;

        // Decrement the count for each character in the second string
        for (char c : t) count[c - 'a']--;

        // Check for count of every character
        for (int i : count) {
            // If the count is not zero
            if (i != 0) return false; // Return false
        }

        // Otherwise strings are anagram
        return true;
    }
};

int main() {
    string str1 = "integer";
    string str2 = "tegerni";
    
    // Creating an instance of Solution class
    Solution sol;
    
    /* Function call to find out 
    whether two strings are anagram */
    bool result = sol.anagramStrings(str1, str2);
    
    // Output 
    if(result) cout << "The given strings are anagrams.";
    else cout << "The given strings are not anagrams.";
    
    return 0;
}