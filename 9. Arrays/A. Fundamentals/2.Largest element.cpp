// Given an array of integers nums, return the value of the largest element in the array


// Example 1

// Input: nums = [3, 3, 6, 1]

// Output: 6

// Explanation: The largest element in array is 6

// Example 2

// Input: nums = [3, 3, 0, 99, -40]

// Output: 99

// Explanation: The largest element in array is 99

// Now your turn!

// Input: nums = [-4, -3, 0, 1, -8]

// Output:

// Pick your answer


// 3

// 5

// 1

// 4
// Constraints

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// nums may contain duplicate elements.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int largestElement(std::vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());

        // Largest element will be at the last index of the array.
        int largest = nums[nums.size() - 1];

        // Return the largest element in array.
        return largest;
    }
};

int main() {
 vector<int> nums = {3, 2, 1, 5, 2};

    // Create an instance of the Solution class
    Solution sol;

    int largest = sol.largestElement(nums);

    // Print the largest element.
    cout << largest << endl;

    return 0;
}
