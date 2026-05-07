/*
Print the matrix in spiral manner
Medium

Hints
Company
Given an M * N matrix, print the elements in a clockwise spiral manner.



Return an array with the elements in the order of their appearance when printed in a spiral manner.


Example 1

Input: matrix = [[1, 2, 3], [4 ,5 ,6], [7, 8, 9]]

Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]

Explanation:

The elements in the spiral order are 1, 2, 3 -> 6, 9 -> 8, 7 -> 4, 5

Example 2

Input: matrix = [[1, 2, 3, 4], [5, 6, 7, 8]]

Output: [1, 2, 3, 4, 8, 7, 6, 5]

Explanation:

The elements in the spiral order are 1, 2, 3, 4 -> 8, 7, 6, 5

Now your turn!

Input: matrix = [[1, 2], [3, 4], [5, 6], [7, 8]]

Output:

Pick your answer


[1, 2, 3, 4, 5, 6, 7, 8]

[1, 2, 4, 6, 8, 7, 5, 3]

[1, 3, 5, 7, 8, 6, 4, 2]

[1, 2, 4, 6, 7, 8, 5, 3]
Constraints

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
Hints


Hint 1
Treat the matrix as a collection of concentric rectangular layers. Traverse each layer in four steps: top row (left to right), right column (top to bottom), bottom row (right to left), and left column (bottom to top).
Hint2
Maintain four boundaries (top, bottom, left, right) to keep track of the limits of the matrix as you spiral inward.

Frequently Occurring Doubts


How does the algorithm avoid revisiting elements?
After traversing a boundary, adjust it inward: Increment top after traversing the top row. Decrement right after traversing the right column. Decrement bottom after traversing the bottom row. Increment left after traversing the left column.

How do I handle the center element in an odd-dimensional matrix?
In an odd-dimensional square matrix, the center element is visited during the last iteration. No special handling is needed as the shrinking boundaries naturally include it in the traversal.

Interview Follow-ups


How would you handle a sparse matrix?
For sparse matrices: Use a coordinate-based approach to track only non-zero elements. Perform the traversal using the coordinates of active elements instead of iterating through every cell.


How would you modify the algorithm for counterclockwise spiral traversal?
To traverse counterclockwise:Start with the left column (top to bottom). Traverse the bottom row (left to right). Traverse the right column (bottom to top). Traverse the top row (right to left).


*/