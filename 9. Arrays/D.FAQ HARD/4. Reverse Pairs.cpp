/*
Given an integer array nums. Return the number of reverse pairs in the array.



An index pair (i, j) is called a reverse pair if:



0 <= i < j < nums.length


nums[i] > 2 * nums[j]

Example 1

Input: nums = [6, 4, 1, 2, 7]

Output: 3

Explanation:

The reverse pairs are:

(0, 2) : nums[0] = 6, nums[2] = 1, 6 > 2 * 1

(0, 3) : nums[0] = 6, nums[3] = 2, 6 > 2 * 2

(1, 2) : nums[1] = 4, nums[2] = 1, 4 > 2 * 1

Example 2

Input: nums = [5, 4, 4, 3, 3]

Output: 0

Explanation:

No pairs satisfy both the conditons.

Now your turn!

Input: nums = [6, 4, 4, 2, 2]

Output:

Pick your answer


0

2

3

7
Constraints

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
Hints


Hint 1
Similar to counting inversions, we divide the array into two halves and count reverse pairs while merging. During merging, count the number of nums[j] where nums[i] > 2 * nums[j] for all i < j.

Hint 2

Hint 2
If values in nums are bounded, a Fenwick Tree or Segment Tree can efficiently count elements <= 2 * nums[j] in O(log n).
Frequently Occurring Doubts


How does Merge Sort help in counting reverse pairs?
While merging, count the number of nums[j] where nums[i] &gt; 2 * nums[j] before merging the two halves to maintain order.

What is the worst-case number of reverse pairs?
If the array is in reverse sorted order with exponentially decreasing values, the count will be close to n(n-1)/2.
Interview Follow-ups


Can we use a hash map to store frequency counts instead of a Fenwick Tree?
Hash maps allow quick lookups, but they do not support range queries efficiently.


What happens if the array contains negative numbers?
Negative values affect 2 * nums[j], but sorting-based approaches still work.

*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/* Brute Force Solution

Intuition
The straightforward approach to solve this problem is to iterate through each element in the array and run an inner loop say(j) to check all subsequent elements arr[j], if the condition arr[i] > 2 x arr[j] holds true, where i is the parent loop, then it is a reverse pair otherwise it's not a reverse pair.

Approach
iterate in the array from 0 to N-1 to select the arr[i]. As index j should be greater than index i, inside loop i, run another loop i.e. j from i+1 to N-1, and select the element arr[j].
Inside this second loop, check if arr[i] is greater than 2*arr[j] i.e. if arr[i] and arr[j] can be a pair. If they satisfy the condition, increase the count by 1. Finally, return the count as our answer.


Complexity Analysis 
Time Complexity: O(N2), where N is size of the given array. For using nested loops here and those two loops roughly run for N times.

Space Complexity: O(1), no extra space is used to solve this problem.
*/
    /* Function to count reverse
    pairs where a[i] > 2 * a[j]*/
    int reversePairsBR(vector<int>& nums) {
        
        // Call countPairs with the vector and its size
        return countPairsBR(nums, nums.size()); 
        
    }

      int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    /* Helper function to count pairs
    satisfying the condition a[i] > 2 * a[j]*/
    int countPairsBR(vector<int>& nums, int n) {
        
        // Initialize count of reverse pairs
        int cnt = 0;
        
        /* Nested loops to check each
        pair (i, j) where i < j*/
        for (int i = 0; i < n; i++) {
            
            for (int j = i + 1; j < n; j++) {
                
                /* Check if the condition 
                a[i] > 2 * a[j] holds*/
                if ((long long)nums[i] > (long long)2 * nums[j]) {
                    
                    /* Increment count if
                    condition is satisfied*/
                    cnt++; 
                    
                }
            }
        }
        // Return the total count of reverse pairs
        return cnt; 
    }
    /**
     * Intuition
In order to solve this problem in optimal way, use the concept of modified merge sort. Here, the approach will be to check, for every element in the sorted left half, how many elements in the right half(also sorted) can make a pair. Let’s try to understand, using the following example:



For the first element of the left half i.e. 6, start checking from index 0 of the right half i.e. arr2[]. Now, we can clearly see that the first two elements of arr2[] can make a pair with arr1[0] i.e. 6.



This process will work because arr1[1] will always be greater than arr1[0] which concludes if arr2[0] and arr2[1] are making a pair with arr1[0], they will obviously make pairs with a number greater than arr1[0] i.e. arr1[1].
Thus before the merge step in the merge sort algorithm, calculate the total number of pairs each time.

Approach
The steps are basically the same as they are in the case of the merge sort algorithm. The change will be just in the mergeSort() function:
In order to count the number of pairs, keep a count variable, cnt, initialized to 0 beforehand inside the mergeSort().
Add the numbers returned by the previous mergeSort() calls. Before the merge step, count the number of pairs using a function, named countPairs(). Remember that the left half starts from low and ends at mid, and the right half starts from mid+1 and ends at high.

The steps of the countPairs() function will be as follows:
Declare a variable, cnt, initialized with 0 & run a loop from low to mid, to select an element at a time from the left half.
Inside that loop, use another loop to check how many elements from the right half can make a pair.
Lastly, add the total number of elements i.e. (right-(mid+1)) (where right = current index), to the cnt and return it.
Thus before the merge step in the merge sort algorithm, we will calculate the total number of pairs each time.

Complexity Analysis
Time Complexity: O(2N * logN), where N is size of the given array.
Inside the mergeSort() we call merge() and countPairs() except mergeSort() itself. Now, inside the function countPairs(), though we are running a nested loop, we are actually iterating the left half once and the right half once in total.
That is why, the time complexity is O(N). And the merge() function also takes O(N). The mergeSort() takes O(logN) time complexity. Therefore, the overall time complexity will be O(logN x (N+N)) = O(2NxlogN)

Space Complexity: O(N), as in the merge sort, a temporary array to store elements in sorted order is used.

     */
    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;

        // For each element in left half
        for (int i = low; i <= mid; i++) {
            // Count how many elements in right half satisfy nums[i] > 2 * nums[j]
            while (right <= high && (long long)nums[i] > 2LL * nums[right]) {
                right++;
            }
            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    // Merges two sorted subarrays into one
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge process
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        // Append remaining elements
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);

        // Copy merged array back
        for (int i = low; i <= high; ++i) {
            nums[i] = temp[i - low];
        }
    }

    // Recursively divides the array and counts reverse pairs
    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;

        int mid = (low + high) / 2;
        int cnt = 0;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);

        return cnt;
    }
};

int main() {
    
    vector<int> nums = {6, 4, 1, 2, 7}; 
    
    // Create an instance of the Solution class
    Solution sol; 
    
    int cnt = sol.reversePairs(nums); 
    
    // Output the result
    cout << "The number of reverse pairs is: " << cnt << endl;
    return 0; 
}  