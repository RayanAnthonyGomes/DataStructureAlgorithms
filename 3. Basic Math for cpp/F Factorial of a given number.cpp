// Factorial of a given number
// You are given an integer n. Return the value of n! or n factorial.



// Factorial of a number is the product of all positive integers less than or equal to that number.


// Example 1

// Input: n = 2

// Output: 2

// Explanation: 2! = 1 * 2 = 2.

// Example 2

// Input: n = 0

// Output: 1

// Explanation: 0! is defined as 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to find the
    factorial of a number*/
    int factorial(int n) {
        // Edge case
        if(n == 0) return 1;
        
        // Variable to store the factorial
        int fact = 1;

        // Iterate from 1 to n
        for(int i = 1; i <= n; i++) {
            // Multiply fact with current number
            fact = fact * i;
        }
        
        // Return the factorial stored
        return fact;
    }
};

int main()
{
    int n = 4;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    // Function call to find the factorial of n
    int ans = sol.factorial(n);
    
    cout << "The factorial of given number is: " << ans;
    
    return 0;
}
