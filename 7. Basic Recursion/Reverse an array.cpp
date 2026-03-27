// Given an array nums of n integers, return reverse of the array.


// Example 1

// Input : nums = [1, 2, 3, 4, 5]

// Output : [5, 4, 3, 2, 1]

// Example 2

// Input : nums = [1, 3, 3, 3, 5]

// Output : [5, 3, 3, 3, 1]

// Now your turn!

// Input : nums = [1, 2, 1]

// Output:

// Pick your answer


// [1, 2, 1]

// [1, 1, 2]

// [2, 1, 1]

// [1, 2, 2]
// Constraints

// 1 <= n <= 100
// 1 <= nums[i] <= 100

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> reverseArray(vector<int>& nums) {
    // Call the helper function to reverse the array
        reverse(nums, 0, nums.size() - 1); 
        // Return the reversed array
        return nums; 
    }

// Helper method to reverse the array using recursion
private:
    void reverse(vector<int>& nums, int left, int right) { 
        if (left >= right) {
            return; 
        }
        // Swap the elements
        int temp = nums[left]; 
        nums[left] = nums[right];
        nums[right] = temp;
        // Recursive call with updated pointers
        reverse(nums, left + 1, right - 1); 
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5}; 
    vector<int> result = solution.reverseArray(nums); 
    for (int num : result) {
        cout << num << " "; 
    }
    return 0;
}
