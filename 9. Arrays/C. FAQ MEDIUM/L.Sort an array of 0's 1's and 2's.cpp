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
    void BRUUTEsortZeroOneTwo(vector<int>& nums) {
        // Sort the vector using std::sort
        sort(nums.begin(), nums.end());
    }

    ///Better
    /*
    Intuition
The better way is to keep the count of 0's, 1's and 2's. Since there are only 3 distinct values in the array so it's easy to maintain the count of all. Then we can overwrite the array based on the frequencies of 0's, 1's, 2's.

Approach 
Initialize 3 variables to maintain the count of 0, 1 and 2 & iterate in the array to store the frequencies of the 0's, 1's, 2's in their corresponding variables.
Perform a 2nd traversal of array, to overwrite the array according to the frequencies, first filling up the indices by 0's, then by 1's and at last by 2's. Finally return the array.
Complexity Analysis 
Time Complexity: O(N)+O(N) = O(2N), where N is the size of the array. There are 2 traversals in the array to count the frequencies then in second iteration we are overwriting.

Space Complexity: O(1) no extra space used


    */

        void BETTERsortZeroOneTwo(vector<int>& nums) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        // Counting the number of 0s, 1s, and 2s in the array
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) cnt0++;
            else if (nums[i] == 1) cnt1++;
            else cnt2++;
        }

        /* Placing the elements in the
        original array based on counts*/
        //placing 0's
        for (int i = 0; i < cnt0; i++) nums[i] = 0;

        //placing 1's
        for (int i = cnt0; i < cnt0 + cnt1; i++) nums[i] = 1; 
        
        //placing 2's
        for (int i = cnt0 + cnt1; i < nums.size(); i++) nums[i] = 2;
    }

    //ooptimal

    /*
    Intuition
The optimal solution is a variation of the popular Dutch National flag algorithm.

This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.

Index 0 to low -1 contains 0
Index low to mid - 1 contains 1
Index high +1 to sizeOfArray - 1 contains 2.

The middle part i.e. mid to high is the unsorted segment. So, this part is a mix of 0's, 1's and 2's. Follow the rules mentioned in approach and image below and sort the array.


Approach 
Initialize low and mid at 0 and high is sizeOfArray - 1, & iterate in the array until mid <= high. There can be three different values of mid pointer i.e. arr[mid].
If arr[mid] is equal to 0, swap arr[low] and arr[mid] and increment both low and mid. Now the subarray from index 0 to (low-1) only contains 0.
If arr[mid] is equal to 1, just increment the mid pointer and then the index (mid-1) will point to 1 as it should according to the rules.
If arr[mid] is equal to 2, swap arr[mid] and arr[high] and decrement high. Now the subarray from index high+1 to (n-1) only contains 2. In this step, do nothing to the mid-pointer as even after swapping, the subarray from mid to high(after decrementing high) might be unsorted. So, check the value of mid again in the next iteration. Finally, the array should be sorted.

Complexity Analysis 
Time Complexity: O(N), where N is the size of the array, as there is single traversal of the array.
    */
     void sortZeroOneTwo(vector<int>& nums) {
        
        // 3 pointers: low, mid, high
        int low = 0, mid = 0, high = nums.size() - 1; 
        while (mid <= high) {
            if (nums[mid] == 0) {
                
                /* Swap nums[low] and nums[mid], then 
                 move both low and mid pointers forward*/
                swap(nums[low], nums[mid]);
                low++;
                mid++;
                
            }
            else if (nums[mid] == 1) {
                // Move mid pointer forward
                mid++;
            }
            else {
                /* Swap nums[mid] and nums[high], 
                then move high pointer backward*/
                swap(nums[mid], nums[high]);
                high--;
            }
        }
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