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

/*
Intuition:
A naive approach to solve this problem will be to use the formula for the element of rth row and cth column of Pascal's triangle repetitively to find each element in the rth row. The time complexity of this approach will be O(n2) as we need to calculate the value of each element in the nth row.

A better way to solve this is by identifying a pattern in the rows of the Pascal's triangle. The rth row of Pascal's triangle is generated as shown in the figure:


It can be seen that any element in the rth row is of the form:
curr = (prev * (r-i))/(i)
where prev is the previous element in the row and i is the index of the element in the row.

Using this formula, we can generate the rth row of Pascal's triangle in O(n) time complexity.

Approach:

Initialize the list with a size equal to the given row number.
Set the first element of the row to 1, as the first element in every row of Pascal's Triangle is always 1.
Iterate through the row to compute each value using the above formula.
Return the computed row as the final result.
*/

#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    // Function to return the rth row of pascal's triangle
    vector<int> pascalTriangleII(int r) {
        vector<int> ans(r); // to store the answer
        
        // Set the first element of the row as 1
        ans[0] = 1; 
        
        // Compute each element in the rth row
        for(int i = 1; i < r; i++) {
            ans[i] = (ans[i-1]*(r-i))/i;
        }
        
        return ans; // return the result
    }
};

int main() {
    // row number
    int r = 5; 

    // Create an instance of the Solution class
    Solution sol; 
    
    // Function call to return the rth row of pascal's triangle
    vector<int> ans = sol.pascalTriangleII(r);

    // Output
    cout << "Row " << r << ": ";
    for(int x : ans) cout << x << " ";

    return 0;
}
