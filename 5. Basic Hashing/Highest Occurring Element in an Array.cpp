// Given an array nums of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times. If there are multiple elements that appear a maximum number of times, find the smallest of them.



// Please note that this section might seem a bit difficult without prior knowledge on what hashing is, we will soon try to add basics concepts for your ease! If you know the concepts already please go ahead to give a shot to the problem. Cheers!


// Example 1

// Input: nums = [1, 2, 2, 3, 3, 3]

// Output: 3

// Explanation: The number 3 appears the most (3 times). It is the most frequent element.

// Example 2

// Input: nums = [4, 4, 5, 5, 6]

// Output: 4

// Explanation: Both 4 and 5 appear twice, but 4 is smaller. So, 4 is the most frequent element.

// Example 3

// Input: nums = [2, 4, 3, 2, 5, 4]

// Output:

// 2
// Constraints

// 1 <= n <= 105
// 1 <= nums[i] <= 104

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to get the highest 
    occuring element in array n */
    int mostFrequentElement(vector<int> &nums) {
        
        // Variable to store the size of array
        int n = nums.size();
        
        // Variable to store maximum frequency
        int maxFreq = 0; 
        
        /* Variable to store element 
        with maximum frequency */
        int maxEle;
        
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
            
            if(freq > maxFreq) {
                maxFreq = freq;
                maxEle = ele;
            }
            else if(freq == maxFreq) {
                maxEle = min(maxEle, ele);
            }
        }
        
        // Return the result
        return maxEle;
    }
};

int main() {
    vector<int> nums = {4, 4, 5, 5, 6};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to get the
    highest occuring element in array n */
    int ans = sol.mostFrequentElement(nums);
    
    cout << "The highest occurring element in the array is: " << ans;
    
    return 0;
}