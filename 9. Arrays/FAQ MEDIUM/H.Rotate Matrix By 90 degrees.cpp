/*
Rotate matrix by 90 degrees
Medium

Hints
Company
Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.



The rotation must be done in place, meaning the input 2D matrix must be modified directly.


Example 1

Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]



Output: matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]



Example 2

Input: matrix = [[0, 1, 1, 2], [2, 0, 3, 1], [4, 5, 0, 5], [5, 6, 7, 0]]



Output: matrix = [[5, 4, 2, 0], [6, 5, 0, 1], [7, 0, 3, 1], [0, 5, 1, 2]]



Now your turn!

Input: matrix = [[1, 1, 2], [5, 3, 1], [5, 3, 5]]

Output:

Pick your answer


[[2, 1, 5], [1, 3, 3], [1, 5, 5]]

[[5, 3, 5], [1, 3, 5], [2, 1, 1]]

[[5, 5, 1], [3, 3, 1], [5, 1, 2]]

[[5, 3, 5], [1, 3, 5], [1, 1, 2]]
Constraints

n == matrix.length.
n == matrix[i].length.
1 <= n <= 100.
-104 <= matrix[i][j] <= 104
Hints


Hint 1
Swap elements such that matrix[i][j] becomes matrix[j][i]. Reverse the order of elements in each row to complete the rotation.

Hint 2
Alternatively, rotate the matrix in layers, starting from the outermost layer and moving inward. For each layer, shift elements in groups of four.
Frequently Occurring Doubts


How does the algorithm handle non-square matrices?
The given problem assumes a square N×N matrix. For non-square matrices, a 90-degree rotation would not be in place, as the dimensions change. Handling non-square matrices requires creating a new matrix to store the result.

Why does transposing and reversing achieve a 90-degree rotation?
Transposing: Converts rows into columns (flipping the matrix across its diagonal). Reversing Each Row: Aligns the transposed columns to their new positions after rotation.

Interview Follow-ups


How would you generalize this for multiple rotations?
For k rotations of 90 degrees: Reduce k modulo 4 (k%4) to minimize redundant rotations. Perform the k rotations iteratively using the 90-degree rotation logic.

What if the matrix is sparse?
For sparse matrices: Use a coordinate-based representation (e.g., a dictionary of non-zero values). Transform the coordinates for the rotation rather than manipulating the entire matrix. This reduces both time and space complexity for large sparse matrices.

*/
