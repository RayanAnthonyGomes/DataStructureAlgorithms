// T. Sort Numbers
// time limit per test0.25 seconds
// memory limit per test256 megabytes
// Given three numbers A, B, C. Print these numbers in ascending order followed by a blank line and then the values in the sequence as they were read.

// Input
// Only one line containing three numbers A, B, C ( - 106  ≤  A, B, C  ≤  106)

// Output
// Print the values in ascending order followed by a blank line and then the values in the sequence as they were read.

// Examples
// InputCopy
// 3 -2 1
// OutputCopy
// -2
// 1
// 3

// 3
// -2
// 1
// InputCopy
// -2 10 0
// OutputCopy
// -2
// 0
// 10

// -2
// 10
// 0


#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int arr[3];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    sort(arr,arr+3);
       for (int i = 0; i < 3; i++) {
        cout << arr[i] << endl;
    }
    
    cout << endl << a << endl << b << endl << c; 

    return 0;
}