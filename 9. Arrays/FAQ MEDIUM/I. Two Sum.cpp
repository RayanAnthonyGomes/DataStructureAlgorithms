/*
**Problem Statement**
Two Sum
Easy

Hints
Company
Given an array of integers nums and an integer target. Return the indices(0 - indexed) of two elements in nums such that they add up to target.



Each input will have exactly one solution, and the same element cannot be used twice. Return the answer in increasing order.


Example 1

Input: nums = [1, 6, 2, 10, 3], target = 7

Output: [0, 1]

Explanation:

nums[0] + nums[1] = 1 + 6 = 7

Example 2

Input: nums = [1, 3, 5, -7, 6, -3], target = 0

Output: [1, 5]

Explanation:

nums[1] + nums[5] = 3 + (-3) = 0

Now your turn!

Input: nums = [-6, 7, 1, -7, 6, 2], target = 3

Output:

Pick your answer


[0, 1]

[3, 6]

[1, 2]

[2, 5]
Constraints

2 <= nums.length <= 105
-104 <= nums[i] <= 104
-105 <= target <= 105
Only one valid answer exists.
Hints


Hint 1
Use a hash map (dictionary) to store the indices of elements as you iterate through the array. This allows for efficient lookups of the complement (i.e., target−current element).

Hint 2
Alternatively, use two pointers, one starts at the beginning (smallest element) and the other at the end (largest element) of the sorted array.If the sum of the elements at the two pointers is less than the target, move the left pointer to the right. If the sum is greater than the target, move the right pointer to the left.
Frequently Occurring Doubts


Why does the two-pointer technique work only on sorted arrays?
In a sorted array: Increasing the left pointer increases the sum. Decreasing the right pointer decreases the sum.
What if there are no valid pairs?
If the pointers cross (i.e., the left pointer exceeds the right pointer) without finding a match, it means no two numbers in the array sum to the target. In this case, the algorithm returns an empty result or an appropriate error message.

Interview Follow-ups


How would you handle multiple solutions?
If multiple solutions are allowed: Continue moving the pointers inward even after finding a valid pair. Store all valid pairs in a result list.


How would you return the original indices after sorting?
While sorting, store the original indices as tuples (e.g., [(value, index)]). Use the sorted array to find the solution, and then map the indices back to their original positions.


*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
    Brute Force Solution Intuition and approach
    Intuition
        For each element of the given array, try to find another element such that their sum equals the target. If such two numbers exist, return their indices; otherwise, return -1.

Approach 
        Iterate in array from 0 to last index of the array (lets call this variable i). Now, run another loop say(j) from i+1 to last index of the array.
If sum of arr[i] and arr[j] equals to target then return the i and j. If no such indices are found then return -1 and -1.

Complexity Analysis 
Time Complexity:O(N 2), For using two nested loops to traverse the array, where N is the length of that array.

Space Complexity: O(1), not using extra space.
*/

    /*Function to find two indices in the array `nums`
    such that their elements sum up to `target`.*/
  
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        //create ans vector to store ans
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                
                /*if nums[i] + nums[j] is equal to 
                target put i and j in ans*/
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
                
            }
        }
        
        // Return {-1, -1} if no such pair is found
        return {-1, -1}; 
    }
};

int main() {
    int n = 5;
    vector<int> nums = {2, 6, 5, 8, 11};
    int target = 14;
    
    // Create an instance of the Solution class
    Solution sol;
    
    // Call the twoSum method to find the indices
    vector<int> ans = sol.twoSum( nums, target);
    
    // Print the result
    cout << "This is the answer: [" << ans[0] << ", " << ans[1] << "]" << endl;
    
    return 0;
}


