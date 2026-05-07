/*
Given an integer n, return the first n (1-Indexed) rows of Pascal's triangle.



In Pascal's triangle:

The first row has one element with a value of 1.
Each row has one more element in it than its previous row.
The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

Example 1

Input: n = 4

Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1]]

Explanation: The Pascal's Triangle is as follows:

1

1 1

1 2 1

1 3 3 1

1st Row has its value set to 1.

All other cells take their value as the sum of the values directly above them

Example 2

Input: n = 5

Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]

Explanation: The Pascal's Triangle is as follows:

1

1 1

1 2 1

1 3 3 1

1 4 6 4 1

1st Row has its value set to 1.

All other cells take their value as the sum of the values directly above them

Now your turn!

Input: n = 3

Output:

Pick your answer


[[1], [1, 1], [1, 3, 1]]

[[1], [1, 1], [1, 2, 1]]

[[1], [1, 1], [2, 3, 2]]

[[1], [1, 1], [1, 3, 1], [1, 4, 4, 1]
Constraints

1 <= n <= 30
All values will fit inside a 32-bit integer.
Hints


Hint 1
Each element in a row (except the first and last) is the sum of the two elements directly above it from the previous row. This recursive relationship can be used to compute Pascal's triangle row by row.

Hint 2
For each row, initialize the first and last elements as 1. Compute the middle elements using values from the previous row.
Frequently Occurring Doubts


How do we calculate elements in the middle of a row?
Each middle element is the sum of the two elements directly above it in the triangle. If the previous row is prevRow, then currRow[i] = prevRow[i - 1] + prevRow[i].

How can Pascal's triangle be used to compute Fibonacci numbers?
The sum of elements along the diagonals of Pascal's triangle gives Fibonacci numbers.

Interview Follow-ups


How would you compute a specific element in Pascal’s triangle without generating the entire triangle?
To compute the value at row r and column c (0-based indexing), use the combination formula: C(r,c)= r!/(c!×(r−c)!)​

How can Pascal's triangle be used in binomial expansion?
The n-th row of Pascal's triangle represents the coefficients of the terms in the expansion of (a+b)^n.

*/