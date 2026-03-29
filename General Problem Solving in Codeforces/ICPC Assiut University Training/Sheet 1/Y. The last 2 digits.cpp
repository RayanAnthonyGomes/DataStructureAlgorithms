// Y. The last 2 digits
// Given 4 numbers A
// , B
// , C
//  and D
// . Print the last 2 digits from their Multiplication.

// Input
// Only one line containing four numbers A
// , B
// , C
//  and D
//  (2≤A,B,C,D≤109)
// .

// Output
// Print the last 2 digits from their Multiplication.

// Examples
// InputCopy
// 5 7 2 4
// OutputCopy
// 80
// InputCopy
// 3 9 9 9
// OutputCopy
// 87
// Note
// First Example :

// the Multiplication of 4 numbers is 5 * 7 * 2 * 4 = 280 so the answer will be the last 2 digits which are 80.

// Second Example :

// the Multiplication of 4 numbers is 3 * 9 * 9 * 9 = 2187 so the answer will be the last 2 digits which are 87.



#include <bits/stdc++.h>
using namespace std;

int main() {
    // long long int a,b,c,d;
    // cin >> a >> b >> c >> d;
    // long long int mul = a * b * c * d;
    // long long int  secondLastDigit=0;
    // long long int lastDigit=0;
    // while(mul>10){
    //     lastDigit = mul % 10;
    //     mul/=10;
    //     secondLastDigit = mul%10;
    //     mul/=10;
    // }
    // cout << secondLastDigit << lastDigit;
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long result = 1;

    result = (result * a) % 100;
    result = (result * b) % 100;
    result = (result * c) % 100;
    result = (result * d) % 100;

    // print last 2 digits (handle leading zero)
    if (result < 10) cout << "0";
    cout << result << endl;

    return 0;
}