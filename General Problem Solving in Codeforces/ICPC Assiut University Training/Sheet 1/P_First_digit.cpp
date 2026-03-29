// P. First digit !
// time limit per test0.25 seconds
// memory limit per test64 megabytes
// Given a number X. Print "EVEN" if the first digit of X is even number. Otherwise print "ODD".

// For example: In 4569 the first digit is 4, the second digit is 5, the third digit is 6 and the fourth digit is 9.

// Input
// Only one line containing a number X (999 < X  ≤  9999)

// Output
// If the first digit is even print "EVEN" otherwise print "ODD"

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    while (n >= 10){
        n /=10;
    }
    if (n % 2 == 0) cout << "ODD";
    else cout << "EVEN";
    return 0;
}