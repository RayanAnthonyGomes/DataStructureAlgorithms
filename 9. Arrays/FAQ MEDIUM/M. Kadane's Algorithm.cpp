// Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.



// A subarray is a contiguous non-empty sequence of elements within an array.


// Example 1

// Input: nums = [2, 3, 5, -2, 7, -4]

// Output: 15

// Explanation:

// The subarray from index 0 to index 4 has the largest sum = 15

// Example 2

// Input: nums = [-2, -3, -7, -2, -10, -4]

// Output: -2

// Explanation:

// The element on index 0 or index 3 make up the largest sum when taken as a subarray

// Now your turn!

// Input: nums = [-1, 2, 3, -1, 2, -6, 5]

// Output:

// Pick your answer


// 5

// 7

// 8

// 6
// Constraints

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Brute Force algorith
    /**
     * Intuition 
The idea is to find out all the subarrays of the given array and while finding out the subarray calculate the sum of all the elements of that particular subarray. Finally, find out the maximum sum among them and that will be the result.

Approach 
Iterate in the array lets say i, this variable will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
Inside the loop, run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
After that for each subarray starting from index i and ending at index j, iterate again to calculate the sum of all the elements(of that particular subarray). Use a max variable to store the maximum sum so far and finally, return the max variable.

Complexity Analysis 
Time Complexity: O(N3), where N is the size of the array. Using three nested loops, each running approximately N times.

Space Complexity: O(1) no extra space used.

     */
    int maxSubArrayBrute(vector<int>& nums) {
        
        /* Initialize maximum sum with 
        the smallest possible integer*/
        int maxi = INT_MIN; 

        // Iterate over each starting index of subarrays
        for (int i = 0; i < nums.size(); i++) {
            
            /* Iterate over each ending index
            of subarrays starting from i*/
            for (int j = i; j < nums.size(); j++) {
                
                // Variable to store the sum of the current subarray
                int sum = 0; 

                // Calculate the sum of subarray nums[i...j]
                for (int k = i; k <= j; k++) {
                    sum += nums[k];
                }

                /* Update maxi with the maximum of its current 
                value and the sum of the current subarray*/
                maxi = max(maxi, sum);
                
            }
        }
        
        // Return the maximum subarray sum found
        return maxi; 
    }


    //Better

//     Intuition 
// The better approach is to avoid triple looping structure mentioned previously that calculates the sum of each subarray. On observation we understand that to get the sum of the current subarray we just need to add the current element to the sum of the previous subarray, hence there is no need of third loop to do that.

// Approach 
// Iterate in the array lets say i to select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n is the array size).
// Inside the loop, iterate again lets say j that will signify the ending index as well as the current element of the subarray. For every subarray starting from index i, the possible ending index can vary from index i to n-1(n is size of the array).
// Inside loop j, keep adding the current element to the sum of the previous subarray. Among all the sums, the maximum one will be the answer and return it.
// Complexity Analysis 
// Time Complexity:O(N2), for using two nested loops, each running approximately N times, here N is the size of the array.

// Space Complexity: O(1) for not using any extra space.
 int maxSubArrayBetter(vector<int>& nums) {
        
        /* Initialize maximum sum with
        the smallest possible integer*/
        int maxi = INT_MIN; 

        // Iterate over each starting index of subarrays
        for (int i = 0; i < nums.size(); i++) {
            
            /* Variable to store the sum
            of the current subarray*/
            int sum = 0; 
            
            /* Iterate over each ending index
            of subarrays starting from i*/
            for (int j = i; j < nums.size(); j++) {
                
                /* Add the current element nums[j] to
                the sum i.e. sum of nums[i...j-1]*/
                sum += nums[j];

                /* Update maxi with the maximum of its current
                value and the sum of the current subarray*/
                maxi = max(maxi, sum);
            }
        }

        // Return the maximum subarray sum found
        return maxi;
    }

};

int main() {
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    //create an instance of Solution class
    Solution sol;
    
    int maxSum = sol.maxSubArray(arr);
    
    //Print the max subarray sum
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

