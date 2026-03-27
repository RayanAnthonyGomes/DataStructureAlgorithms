// Given an array of n elements. The task is to return the count of the number of odd numbers in the array.


// Example 1

// Input: n=5, array = [1,2,3,4,5]



// Output: 3



// Explanation: The three odd elements are (1,3,5).

// Example 2

// Input: n=6, array = [1,2,1,1,5,1]



// Output: 5



// Explanation: The five odd elements are one 5 and four 1's.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Function to count the odd numbers in an array 
    int countOdd(int arr[], int n) {
        // Set counter to 0
        int count = 0;
        // Iterate through the array
        for (int i = 0; i < n; i++) {
        // check for odd values and increment
            if (arr[i] % 2 != 0) {
                count++;
            }
        }
        return count;
    }
};

//Main method
int main() {
    // Creating an instance of Solution class
    Solution sol;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Function call to count the odd numbers in an array 
    int count = sol.countOdd(arr, n);
    cout << "Count of odd numbers: " << count << endl;
    return 0;
}