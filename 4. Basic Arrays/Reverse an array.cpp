// Given an array arr of n elements. The task is to reverse the given array. The reversal of array should be inplace.


// Example 1

// Input: n=5, arr = [1,2,3,4,5]



// Output: [5,4,3,2,1]



// Explanation: The reverse of the array [1,2,3,4,5] is [5,4,3,2,1]

// Example 2

// Input: n=6, arr = [1,2,1,1,5,1]



// Output: [1,5,1,1,2,1]



// Explanation: The reverse of the array [1,2,1,1,5,1] is [1,5,1,1,2,1].

#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    // Function to reverse array using an auxiliary array
    void reverse(int arr[], int n) {
        int* ans = new int[n];
        
        /* Fill new array with elements of 
        original array in reverse order */
        for (int i = n-1; i >= 0; i--) {
            ans[n-i-1] = arr[i];
        }
        
        // Copy the elements back to the original array
        for(int i=0; i < n; i++) {
            arr[i] = ans[i];
        }
        
        // Free the dynamically allocated memory
        delete[] ans; 
        
        // Return
        return;
    }
};
 
// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
int main() {
    int n = 5;
    int arr[] = {5, 4, 3, 2, 1};
    
    // Creating instance of Solution class
    Solution solution;
    cout << "Original array: ";
    printArray(arr, n);
    
    // Function call to reverse the array 
    solution.reverse(arr, n); 
    cout << "Reversed array: ";
    printArray(arr, n);
    
    return 0;
}
 