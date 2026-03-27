// Palindrome Check

// You are given a string s. Return true if the string is palindrome, otherwise false.



// A string is called palindrome if it reads the same forward and backward.


// Example 1

// Input : s = "hannah"

// Output : true

// Explanation :

// The given string when read backward is -> "hannah", which is same as when read forward.

// Hence answer is true.

// Example 2

// Input : s = "aabbaaa"

// Output : false

// Explanation :

// The given string when read backward is -> "aaabbaa", which is not same as when read forward.

// Hence answer is false.

// Example 3

// Input : s = "aabbccbbaa"

// Output:

// true
// Constraints

// 1 <= s.length <= 105
// s consist of only uppercase and lowercase English characters.
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // Function to check if a given string is a palindrome
        bool palindromeCheck(string& s) {
            int left = 0;             
            int right = s.length() - 1; 

            // Iterate while start pointer is less than  end pointer
            while (left < right) {
                // If characters don't match, it's not a palindrome
                if (s[left] != s[right]) {
                    return false;
                }
                left++;   
                right--;  
            }
            return true;  
        }
};

int main() {
    Solution solution;
    string str = "racecar";  

    if (solution.palindromeCheck(str)) {
        cout << str << " is a palindrome." << endl;
    } else {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}
