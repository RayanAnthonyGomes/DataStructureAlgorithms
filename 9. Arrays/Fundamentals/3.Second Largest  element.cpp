// Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.


// Example 1

// Input: nums = [8, 8, 7, 6, 5]

// Output: 7

// Explanation:

// The largest value in nums is 8, the second largest is 7

// Example 2

// Input: nums = [10, 10, 10, 10, 10]

// Output: -1

// Explanation:

// The only value in nums is 10, so there is no second largest value, thus -1 is returned

// Now your turn!

// Input: nums = [7, 7, 2, 2, 10, 10, 10]

// Output:

// Correct

// 10

// 2

// 7

// 0
// Constraints

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// nums may contain duplicate elements.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to find the second largest element
    int secondLargestElement(vector<int>& nums) {
        int n = nums.size();
        
        // Check if the array has less than 2 elements
        if (n < 2) {
            // Indicating no second largest element is possible
            return -1; 
        }
        
        // Sort the vector in ascending order
        sort(nums.begin(), nums.end());

        // Largest element will be at last index
        int largest = nums.back();

        int secondLargest = -1;

        // Traverse the sorted vector from right to left
        for (int i = n-2; i >= 0; i--) {

            /* If the current element is not
            equal to the largest element*/
            if (nums[i] != largest) {

                /* Assign the current element 
                as the second largest and break*/
                secondLargest = nums[i];
                break;

            }
        }

        // Return the second largest element
        return secondLargest ;
    }
};

int main() {
    vector nums = {1, 2, 4, 6, 7, 5};

    //Create an instance of the Solution class
    Solution sol;

    /* Function call to find 
    the second largest element*/
    int ans = sol.secondLargestElement(nums);

    cout << "The second largest element is: " << ans << endl;
    return 0;
}