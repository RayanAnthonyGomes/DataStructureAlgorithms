// Given a string s, representing a large integer, the task is to return the largest-valued odd integer (as a string) that is a substring of the given string s.



// The number returned should not have leading zero's. But the given input string may have leading zero. (If no odd number is found, then return empty string.)


// Example 1

// Input : s = "5347"

// Output : "5347"

// Explanation :

// The odd numbers formed by given strings are --> 5, 3, 53, 347, 5347.

// So the largest among all the possible odd numbers for given string is 5347.

// Example 2

// Input : s = "0214638"

// Output : "21463"

// Explanation :

// The different odd numbers that can be formed by the given string are --> 1, 3, 21, 63, 463, 1463, 21463.

// We cannot include 021463 as the number contains leading zero.

// So largest odd number in given string is 21463.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /* Function to find the largest odd number 
    that is a substring of given string */
    string largeOddNum(string& s) {
        int ind = -1;
        
        // Iterate through the string from the end to beginning
        int i;
        for (i = s.length() - 1; i >= 0; i--) {
            // Break if an odd digit is found
            if ((s[i] - '0') % 2 == 1) {
                ind = i;
                break;
            }
        }
        
        // Skipping any leading zeroes
        i = 0;
        while(i <= ind && s[i] == '0') i++;
        
        // Return the largest odd number substring
        return s.substr(i, ind - i + 1);
    }
};

int main() {
    Solution solution;
    string num = "504";
    string result = solution.largeOddNum(num);
    cout << "Largest odd number: " << result << endl;
    return 0;
}
