// //Sort an array of 0's 1's and 2's
// Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.



// The sorting must be done in-place, without making a copy of the original array.


// Example 1

// Input: nums = [1, 0, 2, 1, 0]

// Output: [0, 0, 1, 1, 2]

// Explanation:

// The nums array in sorted order has 2 zeroes, 2 ones and 1 two

// Example 2

// Input: nums = [0, 0, 1, 1, 1]

// Output: [0, 0, 1, 1, 1]

// Explanation:

// The nums array in sorted order has 2 zeroes, 3 ones and zero twos

// Now your turn!

// Input: nums = [1, 1, 2, 2, 1]

// Output:

// Pick your answer


// [1, 1, 1, 2, 2]

// [1, 1, 2, 2, 2]

// [2, 2, 1, 1, 1]

// [1, 1, 2, 2, 1]
// Constraints

// 1 <= nums.length <= 105
// nums consists of 0, 1 and 2 only.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to sort the array
    void sortZeroOneTwo(vector<int>& nums) {
        // Sort the vector using std::sort
        sort(nums.begin(), nums.end());
    }


};
int main() {
    vector<int> nums = {2, 0, 1, 1, 0, 2};
    
    //Create an instance of Solution class
    Solution sol;
    
    sol.sortZeroOneTwo(nums);
    
    //print the array elements
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}