/*
Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.



The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.


Example 1

Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]

Output: [1, 2, 3, 4, 5, 7]

Explanation:

The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

Example 2

Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]

Output: [1, 3, 4, 5, 6, 7, 8, 9]

Explanation:

The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2

Now your turn!

Input: nums1 = [3, 4, 4, 4], nums2 = [6, 7, 7]

Output:

Pick your answer


[3, 4, 6, 7, 7]

[3, 4, 6, 7]

[3, 4, 4, 4, 6, 7, 7]

[3 ,6, 4, 7]
Constraints

1 <= nums1.length, nums2.length <= 1000
-104 <= nums1[i] , nums2[i] <= 104
Both nums1 and nums2 are sorted in non-decreasing order

Frequently Occurring Doubts


Why do we need both merging and deduplication?
Merging ensures that elements from both arrays are included in the result in sorted order. Deduplication ensures that repeated elements (either within a single array or across both arrays) appear only once in the final result.

What if the arrays are very large?
For very large arrays: If they fit in memory, use the two-pointer approach to merge them efficiently. If they don’t fit in memory, use external sorting techniques or divide the arrays into manageable chunks, process each chunk separately, and merge the results.

Interview Follow-ups


How would you handle unsorted input arrays?
If the input arrays are unsorted: Sort each array first O(mlogm) and O(nlogn)). Apply the two-pointer approach or merge logic. This approach would have an overall time complexity of O(mlogm+nlogn+m+n).

How would you extend this to handle k sorted arrays?
To handle k sorted arrays: Use a min-heap to merge the arrays. Push the smallest element of each array into the heap. Extract the minimum element, add it to the result, and push the next element from the same array into the heap. This has a time complexity of O(Nlogk), where N is the total number of elements.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //bruteforce
        vector<int> BRUTEunionArray(vector<int>& nums1, vector<int>& nums2) {
       // Using set for storing unique elements
        set<int> s; 
        vector<int> Union;

        // Insert all elements of nums1 into the set
        for (int num : nums1) {
            s.insert(num);
        }

        // Insert all elements of nums2 into the set
        for (int num : nums2) {
            s.insert(num);
        }

        // Convert the set to vector to get the union
        for (int num : s) {
            Union.push_back(num);
        }

        return Union;
    }
    /*
        Time Complexity of BRUTE
        Time Complexity: O( (M+N)log(M+N) ), at max set can store M+N elements {when there are no common elements and elements in nums1 , nums2 are distntict}. So Inserting M+N th element takes log(M+N) time. Upon approximation across inserting all elements in worst, it would take O((M+N)log(M+N) time.

Space Complexity: O(M+N), considering space of Union Array.
    */


    ///Optimal Approach
        vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> Union; // Vector to store the union elements
        int i = 0, j = 0;
        int n = nums1.size();
        int m = nums2.size();

        while (i < n && j < m) {
            // Case 1 and 2
            if (nums1[i] <= nums2[j]){ 
            
            if (Union.size() == 0 || Union.back() != nums1[i])
                Union.push_back(nums1[i]);
                i++;
            } 
            
            //case 3
            else{
                if (Union.size() == 0 || Union.back() != nums2[j])
                Union.push_back(nums2[j]);
                j++;
            }
        }

        // If any element left in arr1
        while (i < n){ 
            if (Union.back() != nums1[i])
                Union.push_back(nums1[i]);
            i++;
        }
        // If any elements left in arr2
        while (j < m){ 
            if (Union.back() != nums2[j])
                Union.push_back(nums2[j]);
            j++;
        }

        return Union;
    }
};

int main() {
    // Initialize the arrays
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums2 = {2, 3, 4, 4, 5, 11, 12};
    
    // Create an instance of the Solution class
    Solution finder;
    
    /* Get the union of nums1 and 
    nums2 using the class method*/
    vector<int> Union = finder.unionArray(nums1, nums2);
    
    // Output the result
    cout << "Union of nums1 and nums2 is:" << endl;
    for (int val : Union) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}