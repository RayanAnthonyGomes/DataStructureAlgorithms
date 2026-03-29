// S. Interval
// time limit per test1 second
// memory limit per test256 megabytes
// Given a number X. Determine in which of the following intervals the number X belongs to:

// [0,25], (25,50], (50,75], (75,100]

// Note:

// if X belongs to any of the above intervals print "Interval " followed by the interval.
// if X does not belong to any of the above intervals print "Out of Intervals".
// The symbol '(' represents greater than.
// The symbol ')' represents smaller than.
// The symbol '[' represents greater than or equal.
// The symbol ']' represents smaller than or equal.
// For example:

// [0,25] indicates numbers between 0 and 25.0000, including both.

// (25,50] indicates numbers greater than 25: (25.00001) up to 50.0000000.

// Input
// Only one line containing a number X ( - 1000 ≤ X ≤ 1000).

// Output
// Print the answer to the problem above.

// Examples
// InputCopy
// 25.1
// OutputCopy
// Interval (25,50]
// InputCopy
// 25.0
// OutputCopy
// Interval [0,25]
// InputCopy
// 100.0
// OutputCopy
// Interval (75,100]
// InputCopy
// -25.2
// OutputCopy
// Out of Intervals


#include <bits/stdc++.h>
using namespace std;


int main() {
    // Given a number X. Determine in which of the following intervals the number X belongs to:
        double x;
        cin >> x;

// [0,25], (25,50], (50,75], (75,100]
        if(x>=0 && x <=25) cout << "Interval [0,25]";
        else if(x > 25 && x <=50) cout << "Interval (25,50]";
        else if(x>50 && x<=75) cout << "Interval (50,75]";
        else if(x>75 && x<=100) cout << "Interval (75,100]";
        else cout << "Out of Intervals";
// Note:

// if X belongs to any of the above intervals print "Interval " followed by the interval.
// if X does not belong to any of the above intervals print "Out of Intervals".
// The symbol '(' represents greater than.
// The symbol ')' represents smaller than.
// The symbol '[' represents greater than or equal.
// The symbol ']' represents smaller than or equal.


    return 0;
}