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