// D. Fixed Password
// time limit per test1 second
// memory limit per test256 megabytes
// Given multiple lines each line contains a number X which is a password. Print "Wrong" if the password is incorrect otherwise, print "Correct" and terminate the program.

// Note: The "Correct" password is the number 1999.

// Input
// The input contains several passwords.

// Each line contains a number X (103 ≤ X ≤ 104 - 1).

// Output
// Print "Wrong" if the password is typed wrong otherwise, print "Correct" if the password is typed correctly.

// Example
// InputCopy
// 2200
// 1020
// 1999
// 1000
// 9999
// OutputCopy
// Wrong
// Wrong
// Correct


#include <bits/stdc++.h>
using namespace std;


int main() {
    int pass =  1999;
    long long int x;
    while (cin >> x)
    {
        
        if(x == pass){
            cout <<  "Correct";
            break;
        }else{

            cout << "Wrong\n";
        }    
    }
    

    return 0;
}