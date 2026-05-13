/*
Maximum Product Subarray in an Array
Hard

Hints
Company
Given an integer array nums. Find the subarray with the largest product, and return the product of the elements present in that subarray.



A subarray is a contiguous non-empty sequence of elements within an array.


Example 1

Input: nums = [4, 5, 3, 7, 1, 2]

Output: 840

Explanation:

The largest product is given by the whole array itself

Example 2

Input: nums = [-5, 0, -2]

Output: 0

Explanation:

The largest product is achieved with the following subarrays [0], [-5, 0], [0, -2], [-5, 0, -2].

Now your turn!

Input: nums = [1, -2, 3, 4, -4, -3]

Output:

Pick your answer


12

96

144

288
Constraints

1 <= nums.length <= 104
-10 <= nums[i] <= 10
-109 <= product of any prefix or suffix of nums <= 109
Hints


Hint 1
While iterating from left to right, maintain a running prefix product. If the running product becomes 0, reset it to 1, because the product of any subarray including 0 is 0, and a new subarray can start after it.

Hint 2To account for cases where a negative number at the beginning could be part of the maximum product, also iterate from right to left and track the suffix product.
Frequently Occurring Doubts


Why does Kadane’s algorithm for max sum not work directly for max product?
Because multiplication behaves differently with negative numbers and zeros, so we must track the min product as well.

Why do we track both max and min products?
A negative number can flip the sign, turning a small negative product into a large positive one.
Interview Follow-ups


How would you modify this to return the actual subarray instead of just the product?
Track start and end indices whenever max_prod is updated.
*/