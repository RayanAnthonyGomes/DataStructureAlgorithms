// Given a number N. Print all even numbers between 1 and N inclusive in separate lines.

// Input
// Only one line containing a number N (1 ≤ N ≤ 103).

// Output
// Print the answer according to the required above. If there are no even numbers print -1.

// Examples
// InputCopy
// 10
// OutputCopy
// 2
// 4
// 6
// 8
// 10
// InputCopy
// 5
// OutputCopy
// 2
// 4


#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    int  cnt =  0;
    for (int i = 1; i <= x; i++)
    {
        if(i % 2 ==0) {cout  << i <<  endl;
        cnt++;}

    }
    if(cnt==0) cout << "-1\n";
        
    return 0;
}