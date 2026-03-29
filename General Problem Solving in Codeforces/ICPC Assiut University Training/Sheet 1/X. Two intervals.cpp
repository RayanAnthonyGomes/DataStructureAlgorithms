// Given the boundaries of 2 intervals. Print the boundaries of their intersection.

// Note: Boundaries mean the two ends of an interval which are the starting number and the ending number.

// Input
// Only one line contains two intervals [l1,r1]
// , [l2,r2]
//  where (1≤l1,l2,r1,r2≤109)
// , (l1≤r1,l2≤r2)
// .

// It's guaranteed that l1≤r1
//  and l2≤r2
// .

// Output
// If there is an intersection between these 2 intervals print its boundaries , otherwise print -1.

// Examples
// InputCopy
// 1 15 5 27
// OutputCopy
// 5 15
// InputCopy
// 2 5 6 12
// OutputCopy
// -1
// Note
// First Example :


// Second Example :


#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int l1,r1,l2,r2;
    cin >> l1 >>  r1 >> l2 >> r2;
    long long start = max(l1, l2);
    long long end = min(r1, r2);

    if (start <= end) {
        cout << start << " " << end << endl;
    } else {
        cout << -1 << endl;
    }    
    return 0;
}