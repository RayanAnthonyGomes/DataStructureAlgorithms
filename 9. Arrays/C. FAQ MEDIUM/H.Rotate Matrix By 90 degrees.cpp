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

/*
BRUTE
Intuition
The naive way is to take another dummy matrix of row and column same as original matrix. Then, take the first row of the original matrix and place it in the last column of the dummy matrix. Next, take the second row of the original matrix and place it in the second last column of the dummy matrix, continuing this process until the last row of the original matrix is placed in the first column of the dummy matrix.

Finally, copy the elements of the dummy matrix back to the original matrix. This procedure ensures that the original matrix is rotated by 90 degrees clockwise.

Approach 
initialize a dummy matrix to store the elemens in rotated order.
Iterate in the array using nested for loops say (i) for row and (j) for columns and take the elements of the first row of matrix, put it in last column of the dummy matrix. Repeat this process until index i crosses sizeOfArray
Again, copy the elements of the dummy matrix to the original matrix and finally, return the original matrix.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to rotate the given 
    matrix by 90 degrees clockwise*/
    void rotateMatrixBRUTE(vector<vector<int>>& matrix) {
        
        /* Get the size of the matrix 
        (assuming it's a square matrix)*/
        int n = matrix.size();
        
        // Initialize new matrix to store rotated values
        vector<vector<int>> rotated(n, vector<int>(n, 0)); 
        
        // Iterate through elements of original matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                /* Rotate the element to its new 
                position in the rotated matrix
                New position is (j, n - i - 1) 
                in the rotated matrix*/
                
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }
        
        //copy rotated elements to matrix
        for(int i = 0; i < rotated.size(); i++){
            for(int j = 0; j < rotated[0].size(); j++){
                matrix[i][j] = rotated[i][j];
            }
        }
    
    }

    /*OPTIMAL
    Intuition
The optimal way is to find the transpose of the matrix, which ensures that the first row of the matrix becomes the first column, the second row becomes the second column, and so on. Then, reverse each row. This method ensures that the array is rotated 90 degrees without using extra space.

Approach 
Run nested for loop say(i) for row and (j) for column to iterate the matrix and transpose the matrix to change rows to columns and columns to rows.
Loop again to reverse each row of the matrix. Finally return the matrix.

    */

     /* Rotate the given matrix
    by 90 degrees clockwise.
    */
    void rotateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Reverse each row of the matrix
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; 
    
    // Create an instance of the Solution class
    Solution sol; 
    
    sol.rotateMatrix(arr); 
    
    // Print the rotated matrix
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " "; 
        }
        cout << endl; 
    }

    return 0;
}