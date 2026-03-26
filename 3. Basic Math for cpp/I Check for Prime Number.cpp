// Check for Prime Number
// You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.



// A prime number is a number which has no divisors except 1 and itself.


// Example 1

// Input: n = 5

// Output: true

// Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.

// Example 2

// Input: n = 8

// Output: false

// Explanation: The divisors of 8 are 1, 2, 4, 8, thus it is not a prime number.

// Example 3

// Input: n = 9

// Output:

// false
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find whether the
    number is prime or not */
    bool isPrime(int n) {
        // Edge case
        if(n < 2) return false;
        
        // Loop from 2 to n-1
        for (int i = 2; i < n; ++i) {
            
            // Check if i is a divisor
            if (n % i == 0) {
                return false;
            }
        }
        
        // Return true as the number is prime
        return true;
    }
};

int main() {
    int n = 5;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find whether the
     given number is prime or not */
    bool ans = sol.isPrime(n);
    
    if (ans) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }
    
    return 0;
}
