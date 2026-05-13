/*
Merge two sorted arrays without extra space
Medium

Hints
Company
Given two integer arrays nums1 and nums2. Both arrays are sorted in non-decreasing order.



Merge both the arrays into a single array sorted in non-decreasing order.



The final sorted array should be stored inside the array nums1 and it should be done in-place.


nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s.


nums2 has a length of n.

Example 1

Input: nums1 = [-5, -2, 4, 5], nums2 = [-3, 1, 8]

Output: [-5, -3, -2, 1, 4, 5, 8]

Explanation:

The merged array is: [-5, -3, -2, 1, 4, 5, 8], where [-5, -2, 4, 5] are from nums1 and [-3, 1, 8] are from nums2

Example 2

Input: nums1 = [0, 2, 7, 8], nums2 = [-7, -3, -1]

Output: [-7, -3, -1, 0, 2, 7, 8]

Explanation:

The merged array is: [-7, -3, -1, 0, 2, 7, 8], where [0, 2, 7, 8] are from nums1 and [-7, -3, -1] are from nums2

Now your turn!

Input: nums1 = [1, 3, 5], nums2 = [2, 4, 6, 7]

Output:

Pick your answer


[1, 2, 3, 4, 6, 5, 7]

[1, 2, 3, 4, 5, 6, 7]

[1, 2, 3, 5, 5, 6, 7]

[7, 5, 6, 4, 3, 2, 1]
Constraints

n == nums2.length.
m + n == nums1.length.
0 <= n, m <= 1000
-104 <= nums1[i], nums2[i] <= 104
Both nums1 and nums2 are sorted in non-decreasing order.
Hints


Hint 1
"Use three pointers: i = m - 1 (last valid element in nums1) j = n - 1 (last element in nums2) k = m + n - 1 (last index in nums1)"
Hint 2
"If nums1[i] > nums2[j], place nums1[i] at nums1[k]. Otherwise, place nums2[j] at nums1[k]. Move the pointer(s) accordingly."

Frequently Occurring Doubts


Why start merging from the end instead of the beginning?
Placing elements from the end avoids shifting elements, making the process O(n + m) time instead of O((m+n) log(m+n)) using sorting.

Can this be solved using extra space?
Yes, but in-place merging is required, so no extra space should be used.
Interview Follow-ups


How would you modify this if nums1 did not have extra space?
Use a temporary array, merge both, then copy back into nums1.


How does this problem relate to merge sort?
This is the merge step of merge sort, combining two sorted arrays efficiently.


*/