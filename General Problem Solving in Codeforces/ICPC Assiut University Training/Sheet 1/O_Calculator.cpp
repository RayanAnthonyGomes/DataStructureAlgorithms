// O. Calculator
// time limit per test1 second
// memory limit per test256 megabytes
// Given a mathematical expression. The expression will be one of the following expressions: A+B
// , A−B
// , A∗B
//  and A/B
// .

// Print the result of the mathematical expression.

// Input
// Only one line contains A,S
//  and B
//  (1≤A,B≤104)
// , S
//  is either (+,−,∗,/)
// .

// Output
// Print the result of the mathematical expression.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    char c;
    cin >> x >> c >> y;
    // cout << x << c << y;
    int ans;
    if(c == '+') ans = x+y;
    else if(c == '-') ans = x-y;
    else if(c== '*') ans  = x*y;
    else if(c == '/') ans  = x /y;

    cout << ans;


    return 0;
}