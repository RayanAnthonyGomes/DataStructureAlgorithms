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

    //OPTIMAL SOLUTION::: (PREREQUISITE MERGE SORT)
    /**
     *Intuition 
The optimal solution uses the concept of merge sort algorithm to count the inversion pairs in an array. Try to break down the problem as finding the count of inversion pairs in two sorted arrays. Finally, combine the count and return it.

Approach 
In order to solve this, keep two pointers i and j, where i will point to the first index of arr1[] and j will point to the first index of arr2[]. Now in each iteration, do the following:
If arr1[i] less than or equal to arr2[j]: These two elements cannot be a pair and so we will move the pointer i to the next position.


Why we moved the i pointer: We know, that the given arrays are sorted. So, all the elements after the pointer j, should be greater than a2[j]. Now, as a1[i] is smaller or equal to arr2[j], it is obvious that arr1[i] will be smaller or equal to all the elements after arr2[j]. We need a bigger value of arr1[i] to make a pair and so we move the i pointer to the next position i.e. next bigger value.
If arr1[i] greater than arr2[j]: These two elements can be a pair and so we will update the count of pairs. Now, here, we should observe that as arr1[i] is greater than arr2[j], all the elements after arr1[i] will also be greater than arr2[j] and so, those elements will also make pair with arr2[j]. So, the number of pairs added will be n1-i (where n1 = size of arr1[ ]). Now, we will move the j pointer to the next position.



The steps of the merge() function are the following:
In the merge function, we will use a temp array to store the elements of the two sorted arrays after merging. Here, the range of the left array is low to mid and the range for the right half is mid+1 to high.
Now we will take two pointers left and right, where left starts from low and right starts from mid+1.
Using a while loop( while(left <= mid && right <= high)), we will select two elements, one from each half, and will consider the smallest one among the two. Then, we will insert the smallest element in the temp array.
After that, the left-out elements in both halves will be copied as it is into the temp array. Now, we will just transfer the elements of the temp array to the range low to high in the original array

Modifications in merge() and mergeSort():
In order to count the number of pairs, we will keep a count variable, cnt, initialized to 0 beforehand inside the merge().
While comparing a[left] and a[right] in the 3rd step of merge(), if a[left] > a[right], we will simply add this line: cnt += mid-left+1 (mid+1 = size of the left half)
Now, we will return this cnt from merge() to mergeSort(). Inside mergeSort(), we will keep another counter variable that will store the final answer. With this cnt, we will add the answer returned from mergeSort() of the left half, mergeSort() of the right half, and merge(). Finally, we will return this cnt, as our answer from mergeSort(). 
     * 

     * Complexity Analysis 
Time Complexity: O(NxlogN), where N is size of the given array. We are not changing the merge sort algorithm except by adding a variable to it. So, the time complexity is as same as the merge sort.

Space Complexity: O(N), in the merge sort there is use a temporary array to store elements in sorted order.
     * 
     */
    /* Merge function to count 
    inversions and merge sorted halves*/
    long long int merge(vector<int>& arr, int low, int mid, int high) {
        
        // Temporary array for merging
        vector<int> temp;
        
        // Starting indices of left and right halves
        int left = low;
        int right = mid + 1;

        // Count variable to count the pairs
        long long int cnt = 0;

        // Merge sorted halves into temp array
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                
                temp.push_back(arr[left]);
                left++;
                
            } 
            else {
                temp.push_back(arr[right]);
                
                // Count inversions
                cnt += (mid - left + 1);
                
                right++;
            }
        }

        // Copy remaining elements of left half
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // Copy remaining elements of right half
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        /* Copy elements from temp 
        array back to original array*/
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        
        //return the count of inversions
        return cnt;
    }
    
    // Merge sort function to recursively sort and count inversions
    long long int mergeSort(vector<int>& arr, int low, int high) {
        long long int cnt = 0;
        if (low < high) {
            int mid = low + (high - low) / 2;
            
            // Sort left half
            cnt += mergeSort(arr, low, mid);  
            
            // Sort right half
            cnt += mergeSort(arr, mid + 1, high); 
            
            // Merge and count inversions
            cnt += merge(arr, low, mid, high);  
        }
        return cnt;
    }
    
//OPTIOMAL
    // Function to find number of inversions in an array
    long long int numberOfInversions(vector<int>& nums) {
        
        // Size of the array
        int n = nums.size();

        // Count the number of pairs
        return mergeSort(nums, 0, n - 1);
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