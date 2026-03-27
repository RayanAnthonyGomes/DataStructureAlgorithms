// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.


// Example 1

// Input : num = 529

// Output : 7

// Explanation : In first iteration the digits sum will be = 5 + 2 + 9 => 16

// In second iteration the digits sum will be 1 + 6 => 7.

// Now single digit is remaining , so we return it.

// Example 2

// Input : num = 101

// Output : 2

// Explanation : In first iteration the digits sum will be = 1 + 0 + 1 => 2

// Now single digit is remaining , so we return it.

// Now your turn!

// Input : num = 38

// Output:

// Pick your answer


// 1

// 3

// 2

// 4
// Constraints

// 0 <= num <= 2^31 - 1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method to compute the sum of digits of given number
    int addDigits(int num) {
        // Base case: if the number is a single digit, return it
        if (num < 10) {
            return num;
        }
        
        // Recursive case: sum the digits and continue
        int sum = sumDigits(num);
        
        return addDigits(sum);
    }
    
private:
    // Helper function to add the sum of digits recursively
    int sumDigits(int num) {
        // Base case: If the number is 0, return 0
        if(num == 0) return 0;
        
        // Recursive case
        return sumDigits(num / 10) + (num % 10);
    }
};

int main() {
    Solution solution;
    
    // Example number
    int num = 529;
    
    // Call the addDigits method and print the result
    int result = solution.addDigits(num);
    std::cout << "Sum of digits: " << result << std::endl;  
    
    return 0;
}