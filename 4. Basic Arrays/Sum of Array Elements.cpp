// Sum of Array Elements
// Easy

// Company
// Given an array arr of size n, the task is to find the sum of all the elements in the array.


// Example 1

// Input: n=5, arr = [1,2,3,4,5]



// Output: 15



// Explanation: Sum of all the elements is 1+2+3+4+5 = 15

// Example 2

// Input: n=6, arr = [1,2,1,1,5,1]



// Output: 11



// Explanation: Sum of all the elements is 1+2+1+1+5+1 = 11

// Constraints

// 1 <= n <= 105
// 1 <= arr[i] <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to get the sum of array elements
    int sum(int arr[], int n) {
        int ans = 0; // to store the answer
        
        // Iterate on all the elements
        for(int i = 0; i < n; i++) {
            // Add the current element to the sum
            ans = ans + arr[i]; 
        }
        
        // Return the result
        return ans;
    }
};

// Main method
int main() {
    int n = 4;
    int arr[] = {1, 2, 3, 8};   
    
    // Creating an instance of solution class
    Solution sol;
    
    // Function call to get the sum of array elements
    int result = sol.sum(arr, n); 
    
    // output the result
    cout << "The sum of array elements is: " << result << endl;     
    return 0;
}
