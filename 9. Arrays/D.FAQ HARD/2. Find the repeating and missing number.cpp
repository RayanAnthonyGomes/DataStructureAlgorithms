/*
---Problem Statement---
Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.



Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.



Note: You are not allowed to modify the original array.


Example 1

Input: nums = [3, 5, 4, 1, 1]

Output: [1, 2]

Explanation:

1 appears two times in the array and 2 is missing from nums

Example 2

Input: nums = [1, 2, 3, 6, 7, 5, 7]

Output: [7, 4]

Explanation:

7 appears two times in the array and 4 is missing from nums.

Now your turn!

Input: nums = [6, 5, 7, 1, 8, 6, 4, 3, 2]

Output:

Pick your answer


[6, 9]

[9, 6]

[10, 6]

[6, 8]
Constraints

n == nums.length
1 <= n <= 105
n - 2 elements in nums appear exactly once and are valued between [1, n].
1 element in nums appears twice, and is valued between [1, n].
Hints


Hint 1
The sum of squares of numbers from 1 to n should be (n(n+1)(2n+1))/6. Using this along with the actual sum of squares from the array, we can derive two equations to solve for the missing and duplicate numbers.

Hint 2
The XOR approach works because XOR of the same number cancels out (x ^ x = 0), leaving only the difference between the missing and duplicate numbers.

Frequently Occurring Doubts

How does sorting help?
After sorting, adjacent duplicates appear together, making them easy to detect. Missing numbers are found by checking consecutive values.

Interview Follow-ups


How would you modify this if multiple numbers were duplicated or missing?
Use a hash table to track frequencies (O(n) space). Extend XOR approach to detect multiple values.

How does this change for an unsorted list with arbitrary numbers?
Use a hash set or frequency array instead of 1 to n assumption.


*/