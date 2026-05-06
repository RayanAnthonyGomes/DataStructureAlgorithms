// Problem Statement
// Takahashi works in the general affairs department of a company. He needs to organize a meeting that all 
// N employees must attend.

// The company has 
// M meeting rooms, numbered from 
// 1 to 
// M.

// For each employee 
// i (
// 1≤i≤N), due to scheduling constraints, there is a positive integer 
// P 
// i
// ​
//   representing their participation condition. Employee 
// i can only attend in a meeting room whose number is a multiple of 
// P 
// i
// ​
//  . In other words, employee 
// i can attend in meeting room 
// j if and only if 
// j is a multiple of 
// P 
// i
// ​
//  .

// Takahashi wants to find a meeting room that all employees can attend. Specifically, determine whether there exists a meeting room number 
// j (
// 1≤j≤M) such that 
// j is a multiple of 
// P 
// i
// ​
//   for every employee 
// i (
// 1≤i≤N).

// If such a meeting room exists, output Yes; otherwise, output No.

// Constraints
// 1≤N≤10 
// 5
 
// 1≤M≤10 
// 18
 
// 1≤P 
// i
// ​
//  ≤10 
// 9
 
// All input values are integers.
// Input
// Copy
// N 
// M
// P 
// 1
// ​
  
// P 
// 2
// ​
  
// … 
// P 
// N
// ​
 
// The first line contains an integer 
// N representing the number of employees and an integer 
// M representing the number of meeting rooms, separated by a space.
// The second line contains 
// N integers 
// P 
// 1
// ​
//  ,P 
// 2
// ​
//  ,…,P 
// N
// ​
//   representing the participation conditions of each employee, separated by spaces.
// Output
// If there exists a meeting room that all employees can attend, output Yes; otherwise, output No, in a single line.

// Sample Input 1
// Copy
// 3 12
// 2 3 4
// Sample Output 1
// Copy
// Yes
// Sample Input 2
// Copy
// 4 100
// 6 10 15 3
// Sample Output 2
// Copy
// Yes
// Sample Input 3
// Copy
// 5 1000000000000000000
// 12 18 24 36 48
// Sample Output 3
// Copy
// Yes
// Sample Input 4
// Copy
// 3 50
// 7 11 13
// Sample Output 4
// Copy
// No

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
};

int main() {
    
    return 0;
}