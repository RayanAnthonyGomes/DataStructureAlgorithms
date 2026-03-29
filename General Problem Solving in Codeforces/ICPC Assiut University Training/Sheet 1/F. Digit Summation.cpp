// F. Digits Summation
// time limit per test0.25 seconds
// memory limit per test64 megabytes
// Given two numbers N and M. Print the summation of their last digits.

// Input
// Only one line containing two numbers N, M (0 ≤ N, M ≤ 1018).

// Output
// Print the answer of the problem.

// Example
// InputCopy
// 13 12
// OutputCopy
// 5
// Note
// First Example :

// last digit in the first number is 3 and last digit in the second number is 2.

// So the answer is: (3 + 2 = 5)


#include<bits/stdc++.h>
using namespace std;

int main(){
   long long int x,y;
   cin >> x >> y;
   long long int ldx = x%10;
   long long int ldy = y%10;

   cout << ldx + ldy;
}