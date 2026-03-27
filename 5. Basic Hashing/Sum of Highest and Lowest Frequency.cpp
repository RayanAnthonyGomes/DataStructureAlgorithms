// Given an array of n integers, find the sum of the frequencies of the highest occurring number and lowest occurring number.


// Example 1

// Input: arr = [1, 2, 2, 3, 3, 3]

// Output: 4

// Explanation: The highest frequency is 3 (element 3), and the lowest frequency is 1 (element 1). Their sum is 3 + 1 = 4.

// Example 2

// Input: arr = [4, 4, 5, 5, 6]

// Output: 3

// Explanation: The highest frequency is 2 (elements 4 and 5), and the lowest frequency is 1 (element 6). Their sum is 2 + 1 = 3.

// Example 3

// Input: arr = [10, 9, 7, 7, 8, 8, 8]

// Output:

// 4
// Constraints

// 1 <= n <= 105
// 1 <= arr[i] <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to get the sum of highest
    and lowest frequency in array */
    int sumHighestAndLowestFrequency(vector<int> &nums) {
        
        // Variable to store the size of array
        int n = nums.size();
        
        /* Variable to store maximum 
        and minimum frequency */
        int maxFreq = 0, minFreq = n; 
        
        // HashMap
        unordered_map<int, int> mpp;
        
        // Iterating on the array
        for (int i = 0; i < n; i++) {
            // Updating hashmap 
            mpp[nums[i]]++;
        }
            
        // Iterate on the map
        for(auto it : mpp) {
            int freq = it.second;
            
            /* Update maximum and 
            minimum frequencies */ 
            maxFreq = max(maxFreq, freq);
            minFreq = min(minFreq, freq);
            
        }
        
        // Return the required sum
        return maxFreq + minFreq;
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 3, 3, 3};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the sum of highest
    and lowest frequency in array */
    int ans = sol.sumHighestAndLowestFrequency(nums);
    
    cout << "The sum of highest and lowest frequency in the array is: " << ans;
    
    return 0;
}
