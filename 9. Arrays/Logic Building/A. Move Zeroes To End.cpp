/*
Given an integer array nums, move all the 0's to the end of the array. The relative order of the other elements must remain the same.



This must be done in place, without making a copy of the array.


Example 1

Input: nums = [0, 1, 4, 0, 5, 2]

Output: [1, 4, 5, 2, 0, 0]

Explanation:

Both the zeroes are moved to the end and the order of the other elements stay the same

Example 2

Input: nums = [0, 0, 0, 1, 3, -2]

Output: [1, 3, -2, 0, 0, 0]

Explanation:

All 3 zeroes are moved to the end and the order of the other elements stay the same

Now your turn!

Input: nums = [0, 20, 0, -20, 0, 20]

Output:

Pick your answer


[0, 0, 0, 20, 20, -20]

[-20, 20, 20, 0, 0, 0]

[-20, 0, 0, 0, 20, 20]

[20, -20, 20, 0, 0, 0]
Constraints

1 <= nums.length <= 105
-104 <=nums[i] <= 104

Hint 1
Use two pointers to iterate through the array. One pointer keeps track of the current position, and the other identifies where the next non-zero element should go.

Hint 2
Focus on swapping non-zero elements to the front while keeping track of the current index for placing zeros at the end. Avoid creating a new array by modifying the original array directly. Shift non-zero elements left and fill zeros at the end.


What ensures the relative order of non-zero elements is preserved?
By iterating from left to right and moving each non-zero element to the next available position, the algorithm keeps their original sequence intact. Zeros are moved to the end only after all non-zero elements are correctly positioned, ensuring relative order remains unchanged.

Can this logic be generalized for multi-dimensional arrays?
The same principle can be extended to multi-dimensional arrays, but it must be applied consistently row-wise or column-wise depending on the problem’s definition of “end.” Preserving relative order in higher dimensions requires careful handling, usually with nested loops or recursion—to ensure elements maintain their intended sequence within each sub-structure.

Interview Followups

How would you modify the algorithm to move all zeros to the beginning instead?
To move zeros to the beginning: - Iterate through the array from right to left. - Shift non-zero elements to the rightmost available position, and place zeros at the beginning. - This maintains the relative order of non-zero elements.

How can you adapt this algorithm for other conditions, like moving all negative numbers to the end?
Instead of checking for zeros, modify the condition to identify negative numbers. Use the same two-pointer approach to shift non-negative numbers to the front while maintaining their order.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // j points to where the next non-zero should be placed
        int j = 0;

        // Traverse all elements
        for (int i = 0; i < nums.size(); i++) {
            // If current element is non-zero
            if (nums[i] != 0) {
                // Swap it with the element at index j
                swap(nums[i], nums[j]);

                // Move j to next position
                j++;
            }
        }
    }
};

int main() {
    // Input array
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};

    // Create Solution instance
    Solution solution;

    // Move zeroes to the end
    solution.moveZeroes(arr);

    // Print the updated array
    for (auto &it : arr) {
        cout << it << " ";
    }
    cout << '\n';

    return 0;
}
