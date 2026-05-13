/*
Given an integer array nums of even length consisting of an equal number of positive and negative integers.Return the answer array in such a way that the given conditions are met:



Every consecutive pair of integers have opposite signs.


For all integers with the same sign, the order in which they were present in nums is preserved.


The rearranged array begins with a positive integer.

Example 1

Input : nums = [2, 4, 5, -1, -3, -4]

Output : [2, -1, 4, -3, 5, -4]

Explanation:

The positive number 2, 4, 5 maintain their relative positions and -1, -3, -4 maintain their relative positions

Example 2

Input : nums = [1, -1, -3, -4, 2, 3]

Output : [1, -1, 2, -3, 3, -4]

Explanation:

The positive number 1, 2, 3 maintain their relative positions and -1, -3, -4 maintain their relative positions

Now your turn!

Input: nums = [-4, 4, -4, 4, -4, 4]

Output:

Pick your answer


[4, -4, 4, -4, 4, -4]

[-4, 4, -4, 4, -4, 4]

[4, 4, 4, -4, -4, -4]

[-4, -4, -4, 4, 4, 4]
Constraints

2 <= nums.length <= 105
1 <= | nums[i] | <= 104
nums.length is an even number.
Number of positive and negative numbers are equal.
Hints


Hint 1
Extract positive and negative integers into two separate arrays while preserving their relative order. Iterate through the positive and negative arrays simultaneously, alternately adding elements from each to the result array.

Hint 2
Use two indices to track the position in the positive and negative arrays during merging.

Frequently Occurring Doubts


How does the algorithm ensure the order of positives and negatives is preserved?
The algorithm processes positives and negatives in the order they appear in the original array by iterating over the separated positive and negative arrays without modifying their relative order.

How does the algorithm handle edge cases like duplicates?
The algorithm treats duplicate integers the same as other integers, preserving their order during separation and merging. Duplicates do not affect the correctness of the alternation.

Interview Follow-ups


How would you modify the algorithm to handle uneven counts of positives and negatives?
If the counts are uneven: Fill the result array with as many alternating pairs as possible. Append the remaining elements (all positives or all negatives) to the end of the result array while preserving their order.
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to rearrange the given array by signs
    vector<int> BRUTErearrangeArray(vector<int>& nums) {
        int n = nums.size();
        
        // Define 2 vectors, one for storing positive 
        // and the other for negative elements of the array
        vector<int> pos, neg;
  
        // Segregate the array into positives and negatives
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
  
        // Positives on even indices, negatives on odd
        for (int i = 0; i < n / 2; ++i) {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }
        
        // Return the result
        return nums;
    }
     vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        
        // Initialize a result vector of size n
        vector<int> ans(n, 0); 
        
        // Initialize indices for positive and negative elements
        int posIndex = 0, negIndex = 1;  
        
        // Traverse through each element in nums
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                
                /* If current element is negative, place
                it at the next odd index in ans*/
                ans[negIndex] = nums[i];
                
                // Move to the next odd index
                negIndex += 2;  
                
            } else {
                ans[posIndex] = nums[i];

                // Move to the next even index
                posIndex += 2;  
            }
        }
        
        // Return the rearranged array
        return ans;  
    }
};

int main() {
    vector<int> A = {1, 2, -4, -5};
    
    // Create an instance of Solution class
    Solution sol;
    
    // Get the rearranged array
    vector<int> ans = sol.rearrangeArray(A);
    
    // Print the result
    for (int num : ans) {
        cout << num << " ";
    }
    
    return 0;
}
