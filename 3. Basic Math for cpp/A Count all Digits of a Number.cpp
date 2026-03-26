// You are given an integer n. You need to return the number of digits in the number.



// The number will have no leading zeroes, except when the number is 0 itself.


// Example 1

// Input: n = 4

// Output: 1

// Explanation: There is only 1 digit in 4.

// Example 2

// Input: n = 14

// Output: 2

// Explanation: There are 2 digits in 14.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count all digits in n
    int countDigit(int n) {
        if(n == 0) return 1;
        int cnt = 0;
        int num = n;
        while(num > 0){
            num = num / 10;
            cnt++; 
        }
        return cnt;
        
        //Without loops we can do log10(num) + 1 to  get the digits of the number 
        //TimeComplexity = 0(digits)
        
    }
};

int main()
{
    int n = 6678;
    
    /* Creating and instance of 
    Solution class */
    Solution sol; 
    
    // Function call to get count of digits in n
    int ans = sol.countDigit(n);
    cout << "The count of digits in the given number is: " << ans;
    
    return 0;
}