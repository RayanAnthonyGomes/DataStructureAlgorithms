/*
Remove duplicates from sorted array
Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that each unique element appears only once.



Return the number of unique elements in the array.



If the number of unique elements be k, then,

Change the array nums such that the first k elements of nums contain the unique values in the order that they were present originally.
The remaining elements, as well as the size of the array does not matter in terms of correctness.
The driver code will assess correctness by printing and checking only the first k elements of the modified array.


An array sorted in non-decreasing order is an array where every element to the right of an element is either equal to or greater in value than that element.


Example 1

Input: nums = [0, 0, 3, 3, 5, 6]

Output: 4

Explanation:

Resulting array = [0, 3, 5, 6, _, _]

There are 4 distinct elements in nums and the elements marked as _ can have any value.

Example 2

Input: nums = [-2, 2, 4, 4, 4, 4, 5, 5]

Output: 4

Explanation:

Resulting array = [-2, 2, 4, 5, _, _, _, _]

There are 4 distinct elements in nums and the elements marked as _ can have any value.

Now your turn!

Input: nums = [-30, -30, 0, 0, 10, 20, 30, 30]

Select the possible resulting array.

Output:

Pick your answer


[-30, 0, 10, 20, 30, _, _]

[-30, 0, 10, 20, 30, _, _, _]

[-30, 10, 0, 20, 30, _, _, _]

[-30, 0, 0, 10, 20, _, _, _]
Constraints
1 <= nums.length <= 105
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.


EXTRASS::
Hint 1
Since the array is sorted, duplicates will always be consecutive. Compare adjacent elements to identify duplicates and move unique elements forward.

Hint 2
Keep a counter to track the number of unique elements as you traverse the array.

Frequently Occurring Doubts


What happens to the remaining elements after placing the unique elements?
The problem specifies that the elements after the first k unique values (where k is the number of unique elements) are irrelevant. They do not need to be in any particular order or have specific values, as only the first k elements are considered part of the result.

Interview Follow-ups


How would the solution change if the array was not sorted?
If the array was unsorted, the sorted property could not be used to identify duplicates in one pass. Instead: Sort the array first (O(nlogn)), then apply the two-pointer technique. Alternatively, use a hash set to track seen elements, but this would require O(n) extra space.



*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
          // Initialize pointer for unique elements
        int i = 0;
        
        // Iterate through the vector
        for (int j = 1; j < nums.size(); j++) {
            /*If current element is different 
            from the previous unique element*/
            if (nums[i] != nums[j]) {
                /* Move to the next position in 
                the vector for the unique element*/
                i++;
                /* Update the current position 
                with the unique element*/
                nums[i] = nums[j];
            }
        }
        
        
        // Return the number of unique elements
        return i+1;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 2, 3, 3};
    
    // Create an instance of the Solution class
    Solution solution;
    
    // Call removeDuplicates to remove duplicates from nums
    int k = solution.removeDuplicates(nums);
    
    cout << "The vector after removing duplicate elements is " << endl;
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}