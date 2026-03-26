// Count of Prime Numbers till N
// You are given an integer n. You need to find out the number of prime numbers in the range [1, n] (inclusive). Return the number of prime numbers in the range.



// A prime number is a number which has no divisors except, 1 and itself.


// Example 1

// Input: n = 6

// Output: 3

// Explanation: Prime numbers in the range [1, 6] are 2, 3, 5.

// Example 2

// Input: n = 10

// Output: 4

// Explanation: Prime numbers in the range [1, 10] are 2, 3, 5, 7.


//BRUTE FORCE ATTEMPT:

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /* Function to find whether the
    number is prime or not */
    bool isPrime(int n) {
        
        /* Variable to store the 
        count of divisors of n */
        int count = 0;
        
        // Loop from 1 to n
        for (int i = 1; i <= n; ++i) {
            
            // Check if i is a divisor
            if (n % i == 0) {
                // Increment count
                count = count + 1;
            }
        }
        
        // If count is 2, n is prime
        if (count == 2) return true;
        // Else not prime
        return false;
    }
    
public:
    /* Function to find count
    of primes till n */
    int primeUptoN(int n) {
        
        // Variable to store count
        int count = 0;
        
        // Iterate from 1 to n
        for (int i = 2; i <= n; i++) {
            
            // Check if i is prime
            if (isPrime(i)) count++;
        }
        
        // Return the count
        return count;
    }
};

int main() {
    int n = 6;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get 
    count of all primes till n */
    int ans = sol.primeUptoN(n);
    
    cout << "The count of primes till " << n << " is: " << ans;
    
    return 0;
}
