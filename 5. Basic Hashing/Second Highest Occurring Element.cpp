// // Given an array of n integers, find the second most frequent element in it.



// // If there are multiple elements that appear second most frequent times, find the smallest of them.



// // If second most frequent element does not exist return -1.


// // Example 1

// // Input: arr = [1, 2, 2, 3, 3, 3]

// // Output: 2

// // Explanation:

// // The number 2 appears the second most (2 times) and number 3 appears the most(3 times). 

// // Example 2

// // Input: arr = [4, 4, 5, 5, 6, 7]

// // Output: 6

// // Explanation:

// // Both 6 and 7 appear second most times, but 6 is smaller.

// // Example 3

// // Input: arr = [10, 9 ,7, 7]

// // Output:

// // 9

// Constraints

// 1 <= n <= 105
// 1 <= arr[i] <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to get the second highest 
    occurring element in array */
    int secondMostFrequentElement(vector<int> &nums) {
        
        // Variable to store the size of array
        int n = nums.size();
        
        /* Variable to store maximum frequency
        and second maximum frequency */
        int maxFreq = 0, secMaxFreq = 0; 
        
        /* Variable to store element 
        with maximum frequency and second
        highest frequency */
        int maxEle = -1, secEle = -1;
        
        // HashMap
        unordered_map<int, int> mpp;
        
        // Iterating on the array
        for (int i = 0; i < n; i++) {
            // Updating hashmap 
            mpp[nums[i]]++;
        }
            
        // Iterate on the map
        for(auto it : mpp) {
            int ele = it.first; // Key
            int freq = it.second; // Value
            
            /* Update variables if new element  
            having highest frequency or second
            highest frequency is found */
            if(freq > maxFreq) {
                secMaxFreq = maxFreq;
                maxFreq = freq;
                secEle = maxEle;
                maxEle = ele;
            } 
            else if(freq == maxFreq) {
                maxEle = min(maxEle, ele);
            }
            else if(freq > secMaxFreq) {
                secMaxFreq = freq;
                secEle = ele;
            }
            else if(freq == secMaxFreq) {
                secEle = min(secEle, ele);
            }
        }
        
        // Return the result
        return secEle;
    }
};

int main() {
    vector<int> nums = {4, 4, 5, 5, 6, 7};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the second
    highest occurring element in array */
    int ans = sol.secondMostFrequentElement(nums);
    
    cout << "The second highest occurring element in the array is: " << ans;
    
    return 0;
}