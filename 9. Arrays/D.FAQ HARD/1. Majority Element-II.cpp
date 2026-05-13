/*
--Problem Statement--
Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. The output can be returned in any order.


Example 1

Input: nums = [1, 2, 1, 1, 3, 2]

Output: [1]

Explanation:

Here, n / 3 = 6 / 3 = 2.

Therefore the elements appearing 3 or more times is : [1]

Example 2

Input: nums = [1, 2, 1, 1, 3, 2, 2]

Output: [1, 2]

Explanation:

Here, n / 3 = 7 / 3 = 2.

Therefore the elements appearing 3 or more times is : [1, 2]

Now your turn!

Input: nums = [1, 2, 1, 1, 3, 2, 2, 3](Give the solution sorted in ascending order)

Output:

Pick your answer


[0, 1]

[3, 6]

[1, 2]

[2, 5]
Constraints

n == nums.length.
2 <= n <= 105
-104 <= nums[i] <= 104

Hints


Hint 1
Use two counters to track two potential majority candidates. Count occurrences using a hash map (O(n) space). Collect elements that appear more than n/3 times.
Hint 2
Sort the array (O(n log n)). Scan linearly to find elements occurring more than n/3 times
Frequently Occurring Doubts


Why can there be at most two elements appearing more than n/3 times?
If there were 3 elements appearing more than n/3 times, their total count would exceed n, which is impossible.

Why is sorting less efficient?
Sorting takes O(n log n), which is slower than O(n) Boyer-Moore.

Interview Follow-ups


How would you modify this for elements appearing more than n/k times?
To find elements that appear more than n/k times in an array, modify the Boyer-Moore Voting Algorithm to track k - 1 candidates instead of just 2.

*/

