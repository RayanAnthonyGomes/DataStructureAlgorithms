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
  
    vector<int> twoSumBrute(vector<int>& nums, int target) {
        
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

    /*
    **Better Apprroach
    Intuition
The idea is to traverse the array and use a HashMap to check if for each element, an element in the HashMap exists, such that sum of both of the elements is equal to the target. This method trims down the search space and provides a better time complexity.

Approach 
Iterate in array from 0 to last index of the array (lets call this variable i).
Then check if the other required element(i.e. target-arr[i]) exists in the hashMap.
If that element exists, then return the current index i.e. i, and the index of the element found using map.
If that element does not exist, then just store the current element in the hashMap along with its index. Because in the future, the current element might be a part of our answer.
If at the end we have traversed whole array and no pair is found, that means that the target is unachievable. In this case, return {-1, -1}.

    */

    /*
    Complexity Analysis 
Time Complexity:O(N), where N is the size of the array. The loop runs N times in the worst case and searching in a hashmap takes O(1) generally. So the time complexity is O(N).

Note:In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In that case, the time complexity will be O(N2). If we use map instead of unordered_map, the time complexity will be O(N* logN) as the map data structure takes logN time to find an element.

Space Complexity: O(N) for using the map data structure
    */


    vector<int> twoSumBetter(vector<int>& nums, int target) {
        
        // Map to store (element, index) pairs
        unordered_map<int, int> mpp; 
        
        // Size of the nums vector
        int n = nums.size(); 

        for (int i = 0; i < n; i++) {
             // Current number in the vector
            int num = nums[i];
             // Number needed to reach the target
            int moreNeeded = target - num;

            // Check if the complement exists in map
            if (mpp.find(moreNeeded) != mpp.end()) {
                /* Return the indices of the 
                two numbers that sum up to target*/
                return {mpp[moreNeeded], i};
            }

            // Store current number and its index in map
            mpp[num] = i;
        }

        // If no such pair found, return {-1, -1}
        return {-1, -1};
    }

    /*
    **OPTIMAL SOLUTION**
    Intuition
Imagine being at a market with a list of ingredients, each with different calorie counts. You want to create a dish that meets a specific calorie target.

To find the right pair of ingredients, first organize your ingredients from lowest to highest calories. This way, you can easily adjust your choices based on the total calories you need.

Start with the lowest calorie ingredient and the highest calorie ingredient. By comparing their combined calories to target, decide whether to increase the total (by choosing a higher calorie ingredient) or decrease it (by choosing a lower calorie ingredient). This method allows you to efficiently zero in on the right pair, just like adjusting ingredients in a recipe until it tastes just right. If you find the perfect match, conclude that as your dish! If not, conclude there’s no suitable pair.

Approach 
Sort the given array and initialize two pointers i.e. left, which points to the 0th index, and right, which points to the last index.
Now, using a loop, check the sum of arr[left] and arr[right] until left less than right.
If sum of arr[left] and arr[right] greater than target, decrement the right pointer.
If sum of arr[left] and arr[right] less than target, increment the left pointer.
If sum of arr[left] and arr[right] equals to target, return the result. Finally, if no results are found we will return {-1, -1}.


**Complexity Analysis 
Time Complexity: O(N) + O(N*logN), where N is size of the array. As the loop will run at most N times & sorting the array will take N * logN time complexity.

Space Complexity: O(N), because of the external data structure created to store the array elements along with their indices
    */

        vector<int> twoSum(vector<int>& nums, int target) {
        // Size of the nums vector
        int n = nums.size(); 
        
        // Vector to store indices of two numbers
        vector<int> ans; 
        
        vector<vector<int>> eleIndex;
        for(int i = 0; i < nums.size(); i++){
            eleIndex.push_back({nums[i], i});
        }
        
        //Sort by first element in ascending order
        sort(eleIndex.begin(), eleIndex.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[0] < b[0]; 
        });

        /* Two pointers: one starting 
        from left and one from right*/
        int left = 0, right = n - 1; 

        while (left < right) {
             /* Calculate sum of elements
             at left and right pointers*/
            int sum = eleIndex[left][0] + eleIndex[right][0];

            if (sum == target) {
                
                /* If sum equals target, 
                store indices and return*/
                ans.push_back(eleIndex[left][1]);
                ans.push_back(eleIndex[right][1]);
                return ans;
                
            } else if (sum < target) {
                
                /* If sum is less than target, 
                move left pointer to the right*/
                left++;
                
            } else {
                
                /* If sum is greater than target,
                move right pointer to the left*/
                right--;
                
            }
        }

        // If no such pair found, return {-1, -1}
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


