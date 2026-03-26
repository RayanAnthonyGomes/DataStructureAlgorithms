// Return the Largest Digit in a Number
// You are given an integer n. Return the largest digit present in the number.


// Example 1

// Input: n = 25

// Output: 5

// Explanation: The largest digit in 25 is 5.

// Example 2

// Input: n = 99

// Output: 9

// Explanation: The largest digit in 99 is 9.

// Example 3

// Input: n = 1

// Output:

// 1
// Constraints

// 0 <= n <= 5000
// n will contain no leading zeroes except when it is 0 itself.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to find the largest
    digit in a given number*/
    int largestDigit(int n) {
        // Variable to store the largest digit
        int largestDigit = 0;

        /* Keep on iterating while there
        are digits left to extract */
        while(n > 0) {
            int lastDigit = n % 10;

            /* If the current digit is greater than 
            largest digit, update largest digit */
            if(lastDigit > largestDigit) {
                largestDigit = lastDigit;
            }
            
            n = n / 10;
        }
        
        // Return the largest digit 
        return largestDigit;
    }
};

int main()
{
    int n = 348;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    // Function call to find the largest digit in n
    int ans = sol.largestDigit(n);
    
    cout << "The largest digit in the number is: " << ans;
    
    return 0;
}
