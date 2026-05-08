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

/*

Intuition:
A naive way to solve this problem will be to calculate the element n and c (where n is the given row number and c is the column number that will vary from 1 to n) for every column from 1 to n and for every row, using the process used in Pascal Triangle-I. However, this will result in an O(N3) time complexity.

A better way to solve this problem will be to generate every row from 1 to n using the method discussed in Pascal Triangle-II and store the entire Pascal's Triangle in a 2D list. Once the entire Pascal's Triangle is generated, we can return the triangle.

Approach:

Create a 2D list to hold the values of Pascal's Triangle.
For each row i from 0 to n-1, create a list to hold the values of the current row.
Generate the row i using the method discussed in Pascal's triangle-II.
Append the current row to the triangle. Once all rows are computed, return the triangle.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to generate a single row of Pascal's Triangle
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> ansRow;
        
        /// Inserting the 1st element
        ansRow.push_back(1); 

        // Calculate the rest of the elements
        for (int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        
        return ansRow; // Return the computed row
    }

public:
    // Function to generate Pascal's Triangle up to n rows
    vector<vector<int>> pascalTriangleIII(int n) {
        vector<vector<int>> pascalTriangle;

        // Compute the entire Pascal's Triangle
        for (int row = 1; row <= n; row++) {
            pascalTriangle.push_back(generateRow(row));
        }
        
        //return the pascalTriangle
        return pascalTriangle;
    }
};

int main() {
    int n = 5;
    Solution sol;

    // Generate Pascal's Triangle with n rows
    vector<vector<int>> pascalTriangle = sol.pascalTriangleIII(n);

    // Output the Pascal's Triangle
    for (auto& row : pascalTriangle) {
        for (auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
