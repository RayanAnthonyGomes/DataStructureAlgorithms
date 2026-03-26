// You are given an integer n. You need to check whether the number is a palindrome number or not. Return true if it's a palindrome number, otherwise return false.



// A palindrome number is a number which reads the same both left to right and right to left.


// Example 1

// Input: n = 121

// Output: true

// Explanation: When read from left to right : 121.

// When read from right to left : 121.

// Example 2

// Input: n = 123

// Output: false

// Explanation: When read from left to right : 123.

// When read from right to left : 321.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to check if a 
    number is palindrome or not*/
    bool isPalindrome(int n) {
        int num = n;
        int revnum = 0;
        while(num > 0) {
            int lastDigit = num %  10;
            revnum = (revnum*10) + lastDigit;
            num = num / 10;
        }
        if(revnum == n) {
            return true; 
        }else{
            return false;
            
        }
    }
};

int main()
{
    int n = 12321;
    
    /* Creating and instance of 
    Solution class */
    Solution sol; 
    
    // Function call to check if n is a palindrome
    bool ans = sol.isPalindrome(n);
    
    if(ans) cout << "The given number is a palindrome";
    else cout << "The given number is not a palindrome";
    
    return 0;
}