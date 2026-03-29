// R. Age in Days
// time limit per test1 second
// memory limit per test256 megabytes
// Given a Number N corresponding to a person's age (in days). Print his age in years, months and days, followed by its respective message "years", "months", "days".

// Note: consider the whole year has 365 days and 30 days per month.

// Input
// Only one line containing a number N (0 ≤ N ≤ 106).

// Output
// Print the output, like the following examples.

// Examples
// InputCopy
// 400
// OutputCopy
// 1 years
// 1 months
// 5 days
// InputCopy
// 800
// OutputCopy
// 2 years
// 2 months
// 10 days
// InputCopy
// 30
// OutputCopy
// 0 years
// 1 months
// 0 days


#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    //Note: consider the whole year has 365 days and 30 days per month
    int yrs = n/365;
    n%=365;
    int moo = n/30;
    n%=30 ;
    int days = n;
    //leftover n is days?
    cout << yrs << " years\n" << moo << " months\n" << days << " days\n";   
    return 0;
}