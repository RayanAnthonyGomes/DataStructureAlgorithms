//Problem statement
/*
Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:



a, b, c, d are all distinct valid indices of nums.


nums[a] + nums[b] + nums[c] + nums[d] == target.


Notice that the solution set must not contain duplicate quadruplets. One element can be a part of multiple quadruplets. The output and the quadruplets can be returned in any order.


Example 1

Input: nums = [1, -2, 3, 5, 7, 9], target = 7

Output: [[-2, 1, 3, 5]]

Explanation:

nums[1] + nums[0] + nums[2] + nums[3] = 7

Example 2

Input: nums = [7, -7, 1, 2, 14, 3], target = 9

Output: []

Explanation:

No quadruplets are present which add upto 9

Now your turn!

Input: nums = [1, 1, 3, 4, -3], target = 5

(Give answer with the output and quadruplets sorted in ascending order)

Output:

Pick your answer


[-3, 1, 3, 4]

[[-3, 1, 4, 3], [-3, 1, 3, 4]]

[[-3, 4, 3, 1]]

[[-3, 1, 3, 4]]
Constraints

1 <= nums.length <= 200
-104 <= nums[i] <= 104
-104 <= target <= 104
*/

asd