// E - Number of Blocks in an Interval / 
// Time Limit: 2 sec / Memory Limit: 1024 MiB

// Score : 
// 466 pts

// Problem Statement
// Takahashi manages a coloring sheet consisting of 
// N cells arranged in a horizontal row. The cells are numbered from 
// 1 to 
// N from left to right.

// Each cell 
// i is painted with color 
// C 
// i
// ​
//  . In a sequence of cells, a maximal consecutive interval of the same color that cannot be extended further is called a block. The number of blocks in an interval 
// [L,R] is the number of blocks when the cell sequence 
// C 
// L
// ​
//  ,C 
// L+1
// ​
//  ,…,C 
// R
// ​
//   is divided into blocks.

// For example, if the sequence is 
// 1,1,2,2,2,1, the blocks are 
// (1,1),(2,2,2),(1), giving 
// 3 blocks, so the number of blocks is 
// 3.

// Aoki performs a total of 
// Q operations of the following two types. Process each operation in order and answer the queries.

// 1 L R X: Change the color of all cells in the interval 
// [L,R] to 
// X.
// 2 L R: Output the number of blocks in the current interval 
// [L,R].
// Constraints
// 1≤N≤2×10 
// 5
 
// 1≤Q≤10 
// 5
 
// 1≤C 
// i
// ​
//  ≤10 
// 9
 
// For operation 1 L R X: 
// 1≤L≤R≤N, 
// 1≤X≤10 
// 9
 
// For operation 2 L R: 
// 1≤L≤R≤N
// All input values are integers.
// Input
// Copy
// N 
// Q
// C 
// 1
// ​
  
// C 
// 2
// ​
  
// … 
// C 
// N
// ​
 
// T 
// 1
// ​
 
// T 
// 2
// ​
 
// ⋮
// T 
// Q
// ​
 
// The first line contains the number of cells 
// N and the number of operations 
// Q, separated by a space.
// The second line contains the initial colors of each cell 
// C 
// 1
// ​
//  ,C 
// 2
// ​
//  ,…,C 
// N
// ​
//  , separated by spaces.
// The 
// i-th of the following 
// Q lines contains the 
// i-th operation 
// T 
// i
// ​
//  . Each operation is in one of the following formats:
// 1 L R X: Change the color of all cells in the interval 
// [L,R] to 
// X.
// 2 L R: A query to find the number of blocks in the current interval 
// [L,R].
// Output
// For each operation 2 L R, output the number of blocks in that interval, one per line.

// Sample Input 1
// Copy
// 6 6
// 1 1 2 2 2 1
// 2 1 6
// 2 2 5
// 1 3 5 1
// 2 1 6
// 1 2 4 3
// 2 1 6
// Sample Output 1
// Copy
// 3
// 2
// 1
// 3
// Sample Input 2
// Copy
// 5 7
// 4 5 5 4 4
// 2 1 5
// 1 2 4 4
// 2 1 5
// 2 3 3
// 1 1 1 7
// 2 1 2
// 2 4 5
// Sample Output 2
// Copy
// 3
// 1
// 1
// 2
// 1
// Sample Input 3
// Copy
// 12 12
// 1 2 2 3 3 3 2 2 4 4 5 1
// 2 1 12
// 2 3 10
// 1 2 5 2
// 2 1 8
// 1 9 12 2
// 2 1 12
// 1 6 6 7
// 2 5 7
// 1 1 12 3
// 2 1 12
// 1 4 9 1
// 2 1 12
// Sample Output 3
// Copy
// 7
// 4
// 4
// 4
// 3
// 1
// 3
// Sample Input 4
// Copy
// 20 18
// 1 1 2 3 3 4 4 4 5 6 6 7 8 8 9 9 9 10 1 1
// 2 1 20
// 2 4 17
// 1 3 8 3
// 2 1 10
// 1 10 15 8
// 2 8 18
// 1 1 2 2
// 2 1 5
// 1 16 20 8
// 2 10 20
// 1 5 5 2
// 2 1 20
// 1 6 14 1
// 2 1 20
// 2 6 14
// 1 1 20 7
// 2 1 20
// 2 11 11
// Sample Output 4
// Copy
// 11
// 7
// 4
// 5
// 2
// 1
// 6
// 5
// 1
// 1
// 1
// Sample Input 5
// Copy
// 1 5
// 1000000000
// 2 1 1
// 1 1 1 1
// 2 1 1
// 1 1 1 1000000000
// 2 1 1
// Sample Output 5
// Copy
// 1
// 1
// 1