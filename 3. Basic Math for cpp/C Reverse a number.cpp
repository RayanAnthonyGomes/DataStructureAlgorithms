// You are given an integer n. Return the integer formed by placing the digits of n in reverse order.


// Example 1

// Input: n = 25

// Output: 52

// Explanation: Reverse of 25 is 52.

// Example 2

// Input: n = 123

// Output: 321

// Explanation: Reverse of 123 is 321.

// Example 3

// Input: n = 54

// Output:

// 45
// Constraints

// 0 <= n <= 5000
// n will contain no leading zeroes except when it is 0 itself.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to reverse given number n
    int reverseNumber(int n) {
        int revNum = 0;

        int num = n;

        while (num > 0)
        {
            int lastDigit  = num%10;
            revNum = (revNum*10) + lastDigit;
            num = num / 10;
        }

        return revNum;
        
    }
};

int main()
{
    int n = 6678;
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    // Function call to reverse the digits in n
    int ans = sol.reverseNumber(n);
    cout << "The reverse of given number is: " << ans;
    
    return 0;
}