/*
PROBLEM STATEMENT
Given an integer array nums. Return the number of inversions in the array.



Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.



It indicates how close an array is to being sorted.


A sorted array has an inversion count of 0.


An array sorted in descending order has maximum inversion.

Example 1

Input: nums = [2, 3, 7, 1, 3, 5]

Output: 5

Explanation:

The responsible indexes are:

nums[0], nums[3], values: 2 > 1 & indexes: 0 < 3

nums[1], nums[3], values: 3 > 1 & indexes: 1 < 3

nums[2], nums[3], values: 7 > 1 & indexes: 2 < 3

nums[2], nums[4], values: 7 > 3 & indexes: 2 < 4

nums[2], nums[5], values: 7 > 5 & indexes: 2 < 5

Example 2

Input: nums = [-10, -5, 6, 11, 15, 17]

Output: 0

Explanation:

nums is sorted, hence no inversions present.

Now your turn!

Input: nums = [9, 5, 4, 2]

Output:

Pick your answer


0

1

6

8
Constraints

1 <= nums.length <= 105
-104 <= nums[i] <= 104
Hints


Hint 1
We can use Merge Sort to count inversions efficiently in O(n log n). While merging, if nums[i] > nums[j], all elements from i onward in the left half form inversions with nums[j].

Hint 2
If values in nums are bounded, a Fenwick Tree or Segment Tree can be used to count elements greater than nums[j] before index j in O(n log n).
Frequently Occurring Doubts


How does Merge Sort count inversions?
While merging two halves, if left[i] > right[j], all remaining elements in left contribute to inversions because they are all greater than right[j].

What is the worst-case inversion count?
What is the worst-case inversion count?
The maximum inversions occur when the array is reverse sorted, which is n(n-1)/2.
Interview Follow-ups


How does this relate to sorting algorithms?
The number of inversions represents the minimum swaps needed to sort the array.

How can we modify Merge Sort to also return the sorted array alongside inversion count?
Modify the merge function to return both sorted output and the inversion count.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //brute force algorithm
    /*
    Intuition 
The naive approach is pretty straightforward, which will use nested loops to solve this problem. The prerequisite is that the index i must be smaller than index j. So, fix i at one index, and with another loop say(j), which runs from i+1 to last index of the array, try to count the inversion pairs.

Approach 
Iterate in array from 0 to N-1 to select the first element in the pair. As index j should be greater than index i, inside loop i, run another loop i.e. j from i+1 to N-1. Inside this second loop, check if arr[i] is greater than arr[j] i.e. if arr[i] and arr[j] can be an inversion pair. If it satisfy the condition, increase the count by 1.
Finally, return the count i.e. the number of such pairs.
Complexity Analysis 
Time Complexity: O(N2), for using 2 nested loops, where N is the size of the array.
    */
    // Function to find number of inversions in an array
    long long int numberOfInversionsBRUTE(vector<int>&nums) {
    
    //size of the array 
    int n = nums.size();
    
    // Count the number of pairs:
    long long int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
            /*if nums[i] is greater than 
            nums[j], increase countby 1.*/
            if (nums[i] > nums[j]) cnt++;
            
        }
    }
    
    //return the count of inversions
    return cnt;

    }
};

int main() {
    vector<int> nums = {5, 4, 3, 2, 1};
    
    // Create an instance of Solution class
    Solution sol;

    long long int result = sol.numberOfInversions(nums);
    
    // Print the repeating and missing numbers found
    cout << "The number of inversions is: "
         << result << endl;
    
    return 0;
}