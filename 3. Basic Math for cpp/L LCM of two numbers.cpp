// You are given two integers n1 and n2. You need find the Lowest Common Multiple (LCM) of the two given numbers. Return the LCM of the two numbers.



// The Lowest Common Multiple (LCM) of two integers is the lowest positive integer that is divisible by both the integers.


// Example 1

// Input: n1 = 4, n2 = 6

// Output: 12

// Explanation: 4 * 3 = 12, 6 * 2 = 12.

// 12 is the lowest integer that is divisible both 4 and 6.

// Example 2

// Input: n1 = 3, n2 = 5

// Output: 15

// Explanation: 3 * 5 = 15, 5 * 3 = 15.

// 15 is the lowest integer that is divisible both 3 and 5.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find LCM of n1 and n2
    int LCM(int n1,int n2) {
        //Variable to store lcm
        int lcm;
        
        // Variable to store max of n1 & n2
        int n = max(n1, n2);
        int i = 1;
        
        while(1) {
            // Variable to store multiple
            int mul = n * i;
            
            /* Checking if multiple is common
            common for both n1 and n2 */
            if(mul % n1 == 0 && mul % n2 == 0) {
                lcm = mul;
                break;
            }
            i++;
        }
        
        // Return the stored LCM
        return lcm;
    }
};

int main()
{
    int n1 = 4, n2 = 12;
    
    /* Creating and instance of 
    Solution class */
    Solution sol; 
    
    // Function call to get LCM of n1 and n2
    int ans = sol.LCM(n1, n2);
    cout << "The LCM of" << n1 << " and " << n2 << " is: " << ans;
    
    return 0;
}

