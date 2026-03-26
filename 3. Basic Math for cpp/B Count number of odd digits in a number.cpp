// You are given an integer n. You need to return the number of odd digits present in the number.



// The number will have no leading zeroes, except when the number is 0 itself.


// Example 1

// Input: n = 5

// Output: 1

// Explanation: 5 is an odd digit.

// Example 2

// Input: n = 25

// Output: 1

// Explanation: The only odd digit in 25 is 5.

// Example 3

// Input: n = 15

// Output:

// 2
// Constraints

// 0 <= n <= 5000
// n will contain no leading zeroes except when it is 0 itself.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    /* Function to count number
    of odd digits in N */
    int countOddDigit(int n) {
        
        int oddDigits = 0;
        int num = n;
        
        while (num > 0)
        {
            int lastDigit = num % 10;
            if(lastDigit % 2 == 1) oddDigits++;
            num = num/10;
        }
        return oddDigits;
        

        
    }
};

int main() {
    int n = 6678;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    // Function call to get count of odd digits in n
    int ans = sol.countOddDigit(n);
    cout << "The count of odd digits in the given number is: " << ans;
    
    return 0;
}