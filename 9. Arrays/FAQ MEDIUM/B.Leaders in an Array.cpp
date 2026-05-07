/*
Given an integer array nums, return a list of all the leaders in the array.



A leader in an array is an element whose value is strictly greater than all elements to its right in the given array. The rightmost element is always a leader. The elements in the leader array must appear in the order they appear in the nums array.


Example 1

Input: nums = [1, 2, 5, 3, 1, 2]

Output: [5, 3, 2]

Explanation:

2 is the rightmost element, 3 is the largest element in the index range [3, 5], 5 is the largest element in the index range [2, 5]

Example 2

Input: nums = [-3, 4, 5, 1, -4, -5]

Output: [5, 1, -4, -5]

Explanation:

-5 is the rightmost element, -4 is the largest element in the index range [4, 5], 1 is the largest element in the index range [3, 5] and 5 is the largest element in the range [2, 5]

Now your turn!

Input: nums = [-3, 4, 5, 1, -30, -10]

Output:

Pick your answer


[-3, 4, 5]

[5, 1, -30]

[5, 1, -10]

[5, -10, 1]
Constraints

1 <= nums.length <= 105
-104 <= nums[i] <= 104
Hints


Hint 1
Traverse the array from right to left, as the rightmost element is always a leader and gives a starting point for comparison. Maintain a variable to keep track of the maximum value encountered so far during the traversal. An element is a leader if it is greater than this maximum.

Hint 2
As you identify leaders while traversing from right to left, add them to a temporary list and reverse it at the end to preserve the original order.

Frequently Occurring Doubts


Why traverse the array from right to left?
Traversing from right to left ensures that the current maximum is always the leader for the elements processed so far. This avoids revisiting elements multiple times and allows a single-pass O(n) solution.

How does the algorithm ensure the leaders appear in the correct order?
By adding leaders to a temporary list during right-to-left traversal and reversing the list at the end, the leaders are presented in the same order as they appear in the original array.

Interview Follow-ups


How would you handle an unsorted list with duplicate elements?
The presence of duplicate elements does not change the logic. The algorithm still traverses from right to left and checks if the current element is greater than the maximum seen so far. Only elements that strictly satisfy this condition are added to the leader list.

What if the array is circular?
In a circular array, since there is no fixed “right side,” we redefine the problem: an element is a leader if it is greater than all elements encountered while traversing from its next position and wrapping around back to itself.



To implement this, we simulate circular traversal by iterating the array twice (or using modulo indexing) and comparing each element with all others in circular order.

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to find the leaders in an array.
    vector<int> leadersBRUTE(vector<int>& nums) {
        vector<int> ans;
        
        if(nums.empty()) {
            return ans;
        }
        
        // Last element of the vector is always a leader
        int max = nums[nums.size() - 1];
        ans.push_back(nums[nums.size() - 1]);
        
        // Check elements from right to left
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] > max) {
                ans.push_back(nums[i]);
                max = nums[i];
            }
        }
        
        /* Reverse the vector to match
        the required output order*/
        reverse(ans.begin(), ans.end());
        
        //Return the leaders
        return ans;
    }
};

int main() {
    vector<int> nums = {10, 22, 12, 3, 0, 6};
    
    // Create an instance of the Solution class
    Solution finder;
    
    // Get leaders using class method
    vector<int> ans = finder.leaders(nums);
    
    cout << "Leaders in the array are: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}

