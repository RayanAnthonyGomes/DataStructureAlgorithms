/*
Given an integer r, return all the values in the rth row (1-indexed) in Pascal's Triangle in correct order.



In Pascal's triangle:



The first row has one element with a value of 1.


Each row has one more element in it than its previous row.


The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

Example 1

Input: r = 4

Output: [1, 3, 3, 1]

Explanation:

The Pascal's Triangle is as follows:

1

1 1

1 2 1

1 3 3 1

....

Thus the 4th row is [1, 3, 3, 1]

Example 2

Input: r = 5

Output: [1, 4, 6, 4, 1]

Explanation:

The Pascal's Triangle is as follows:

1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

....

Thus the 5th row is [1, 4, 6, 4, 1]

Constraints

1 <= r <= 30
All values will fit inside a 32-bit integer.
*/