/*
Given an integer array nums of size n, return the majority element of the array.



The majority element of an array is an element that appears more than n/2 times in the array. The array is guaranteed to have a majority element.


Example 1

Input: nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]

Output: 7

Explanation:

The number 7 appears 5 times in the 9 sized array

Example 2

Input: nums = [1, 1, 1, 2, 1, 2]

Output: 1

Explanation:

The number 1 appears 4 times in the 6 sized array

Now your turn!

Input: nums = [-1, -1, -1, -1]

Output:

Pick your answer


0

1

-1

4
Constraints

n == nums.length.
1 <= n <= 105
-104 <= nums[i] <= 104
One value appears more than n/2 times.

Hints


Hint 1
Keep a count variable while iterating, Increase count when encountering the same candidate. Decrease count when encountering a different number. If count == 0, change candidate. The final candidate will be the majority element.

Hint 2
Recursively split the array into halves, find the majority element in each half, if both halves agree, return that element.

requently Occurring Doubts


Why does the Boyer-Moore algorithm work?
The majority element always dominates other numbers, so it cancels out non-majority elements when counting. Even if count resets, the majority element eventually overtakes.

Why does sorting work?
Since the majority element appears more than n/2 times, it will always be at nums[n/2] in a sorted array.

Interview Follow-ups


How would you modify this to find all elements appearing more than n/3 times?
Boyer-Moore extended approach: Use two candidates instead of one. Each valid candidate must appear more than n/3 times.

Can this problem be solved using bitwise operations?
Yes, count each bit position and reconstruct the majority element.


*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //BRUUTE FORCE SOLUTION:
    /// Function to find the majority element in an array
    int majorityElementbrute(vector<int>& nums) {
        
        // Size of the given array
        int n = nums.size(); 
        
        // Iterate through each element of the array
        for (int i = 0; i < n; i++) {
            
            // Counter to count occurrences of nums[i]
            int cnt = 0; 
            
            // Count the frequency of nums[i] in the array
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }
            
            // Check if frequency of nums[i] is greater than n/2
            if (cnt > (n / 2)) {
                // Return the majority element
                return nums[i]; 
            }
        }
        
        // Return -1 if no majority element is found
        return -1; 
    }

    //BEtter Solution
    int majorityElement(vector<int>& nums) {
        
        // Size of the given array
        int n = nums.size();
        
        // Hash map to store element counts
        unordered_map<int, int> mp;
        
        // Count occurrences of each element
        for (int num : nums) {
            mp[num]++;
        }
        
        /* Iterate through the map to
        find the majority element*/
        for (auto& pair : mp) {
            if (pair.second > n / 2) {
                return pair.first;
            }
        }
        
        // Return -1 if no majority element is found
        return -1;
    }
};

int main() {
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    
    // Create an instance of Solution class
    Solution sol;
 
    int ans = sol.majorityElement(arr);
    
    // Print the majority element found
    cout << "The majority element is: " << ans << endl;
    
    return 0;
}
