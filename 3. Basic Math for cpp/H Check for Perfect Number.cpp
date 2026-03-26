// You are given an integer n. You need to check if the number is a perfect number or not. Return true if it is a perfect number, otherwise, return false.



// A perfect number is a number whose proper divisors (excluding the number itself) add up to the number itself.


// Example 1

// Input: n = 6

// Output: true

// Explanation: Proper divisors of 6 are 1, 2, 3.

// 1 + 2 + 3 = 6.

// Example 2

// Input: n = 4

// Output: false

// Explanation: Proper divisors of 4 are 1, 2.

// 1 + 2 = 3.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find whether the
    number is perfect or not */
    bool isPerfect(int n) {
        
        /* Variable to store the sum
        of all proper divisors */
        int sum = 0;
        
        // Loop from 1 to n
        for(int i=1; i < n; ++i) {
            
            // Check if i is a proper divisor
            if(n % i == 0){
                // Update sum
                sum = sum + i;
            }
        }
        
        // Compare sum and n
        if(sum == n) return true;
        return false;
    }
};

int main() {
    int n = 6;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find whether the
     given number is perfect or not */
    bool ans = sol.isPerfect(n);
    
    if(ans) {
        cout << n << " is a perfect number." << endl;
    } else {
        cout << n << " is not a perfect number." << endl;
    }
    
    return 0;
}