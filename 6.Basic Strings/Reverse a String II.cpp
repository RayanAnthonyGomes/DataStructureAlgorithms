// Given a string, the task is to reverse it. The string is represented by an array of characters s.



// Perform the reversal in place with O(1) extra memory.



// Note: no need to return anything, modify the given list.


// Example 1

// Input : s = ["h", "e" ,"l" ,"l" ,"o"]

// Output : ["o", "l", "l", "e", "h"]

// Explanation :

// The given string is s = "hello" and after reversing it becomes s = "olleh".

// Example 2

// Input : s = ["b", "y" ,"e" ]

// Output : ["e", "y", "b"]

// Explanation :

// The given string is s = "bye" and after reversing it becomes s = "eyb".

// Example 3

// Input : s = ["h", "a" ,"n" ,"n" ,"a", "h"]

// Output:

// ['h', 'a' , 'n' , 'n' , 'a' , 'h']

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to reverse a string
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size()-1;
        
        // Until the string is reversed
        while(start < end) {
            // Swap the characters at start and end
            char ch = s[start];
            s[start] = s[end];
            s[end] = ch;
            
            // Move the pointers towards the center
            start++, end--;
        }
        
        return;
    }
};

int main() {
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    
    // Creating an instance of Solution class
    Solution sol;
    
    // Function call to reverse the string
    sol.reverseString(str);

    for (char c : str) {
        cout << c;
    }
    
    return 0;
}