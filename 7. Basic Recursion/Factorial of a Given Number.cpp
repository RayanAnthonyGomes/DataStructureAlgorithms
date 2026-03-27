// Given an integer n, return the factorial of n.



// Factorial of a non-negative integer, is the multiplication of all integers smaller than or equal to n (use 64-bits to return answer).


// Example 1

// Input : n = 3

// Output : 6

// Explanation : Factorial = 1 * 2 * 3 => 6

// Example 2

// Input : n = 5

// Output : 120

// Explanation : Factorial = 1 * 2 * 3 * 4 * 5 => 120

// Constraints

// 0 <= n <= 15

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int factorial(int n) {
        // Base case: factorial of 0 or 1 is 1
        if (n <= 1) return 1;
        // Recursive case: N * factorial of N-1
        return n* factorial(n - 1);
    }
};

int main() {
    Solution solution;
    int N = 5; // Example input
    cout << "Factorial of " << N << " is " << solution.factorial(N) << endl;
    return 0;
}
