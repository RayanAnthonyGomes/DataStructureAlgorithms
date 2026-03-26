// You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.



// A number which completely divides another number is called it's divisor.


// Example 1

// Input: n = 6

// Output = [1, 2, 3, 6]

// Explanation: The divisors of 6 are 1, 2, 3, 6.

// Example 2

// Input: n = 8

// Output: [1, 2, 4, 8]

// Explanation: The divisors of 8 are 1, 2, 4, 8.

// Example 3

// Input: n = 7

// Output:

// [1, 7]

//BRUTE
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find all 
    divisors of n */
    vector<int> divisors(int n) {
        
        // To store the divisors;
        vector<int> ans;
        
        // Iterate from 1 to n
        for(int i=1; i <= n; i++) {
            
            // If a divisor is found
            if(n % i == 0) {
                //Add it to the answer
                ans.push_back(i);
            }
        }
        
        // Return the result
        return ans;
    }
};

int main()
{
    int n = 6;
    
    /* Creating and instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find 
    all divisors of n */
    vector<int> ans = sol.divisors(n);
    
    cout << "The divisors of " << n << " are: ";
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}