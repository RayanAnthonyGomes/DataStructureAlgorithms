// L. The Brothers
// time limit per test1 second
// memory limit per test256 megabytes
// Given two person names.

// Each person has {"the first name" + "the second name"}

// Determine whether they are brothers or not.

// Note: The two persons are brothers if they share the same second name.

// Input
// First line will contain two Strings F1, S1 which donates the first and second name of the 1st person.

// Second line will contain two Strings F2, S2 which donates the first and second name of the 2nd person.

// Output
// Print "ARE Brothers" if they are brothers otherwise print "NOT".

// Examples
// InputCopy
// bassam ramadan
// ahmed ramadan
// OutputCopy
// ARE Brothers
// InputCopy
// ali salah
// ayman salah
// OutputCopy
// ARE Brothers
// InputCopy
// ali kamel
// ali salah
// OutputCopy
// NOT

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;

    if(s2 == s4) cout << "ARE Brothers";
    else cout << "NOT";
    


    return 0;
}