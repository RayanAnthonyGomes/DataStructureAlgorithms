/*
---Problem Statement---
Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.



Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.



Note: You are not allowed to modify the original array.


Example 1

Input: nums = [3, 5, 4, 1, 1]

Output: [1, 2]

Explanation:

1 appears two times in the array and 2 is missing from nums

Example 2

Input: nums = [1, 2, 3, 6, 7, 5, 7]

Output: [7, 4]

Explanation:

7 appears two times in the array and 4 is missing from nums.

Now your turn!

Input: nums = [6, 5, 7, 1, 8, 6, 4, 3, 2]

Output:

Pick your answer


[6, 9]

[9, 6]

[10, 6]

[6, 8]
Constraints

n == nums.length
1 <= n <= 105
n - 2 elements in nums appear exactly once and are valued between [1, n].
1 element in nums appears twice, and is valued between [1, n].
Hints


Hint 1
The sum of squares of numbers from 1 to n should be (n(n+1)(2n+1))/6. Using this along with the actual sum of squares from the array, we can derive two equations to solve for the missing and duplicate numbers.

Hint 2
The XOR approach works because XOR of the same number cancels out (x ^ x = 0), leaving only the difference between the missing and duplicate numbers.

Frequently Occurring Doubts

How does sorting help?
After sorting, adjacent duplicates appear together, making them easy to detect. Missing numbers are found by checking consecutive values.

Interview Follow-ups


How would you modify this if multiple numbers were duplicated or missing?
Use a hash table to track frequencies (O(n) space). Extend XOR approach to detect multiple values.

How does this change for an unsorted list with arbitrary numbers?
Use a hash set or frequency array instead of 1 to n assumption.


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Brute Approach
/*
Intuition 
The naive way is to count the occurrence in the given array using linear search, for each number between 1 to N. The element which occurs twice will be the repeating number and the number with 0 occurrence will be the missing number.

Approach 
Iterate in array from 1 to N & for each integer, i, count its occurrence in the given array using linear search.
Store those two elements that have the occurrence of 2 and 0. Finally, return the elements.
Complexity Analysis 
Time Complexity: O(N2), where N is the size of the array. Since we are using nested loops to count occurrences of every element between 1 to N.
Space Complexity: O(1) as no extra space is used.
*/
    vector<int> findMissingRepeatingNumbersBRUTE(vector<int>& nums) {
        
        // Size of the array
        int n = nums.size(); 
        int repeating = -1, missing = -1;

        // Find the repeating and missing number:
        for (int i = 1; i <= n; i++) {
            
            // Count the occurrences:
            int cnt = 0;
            
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) cnt++;
            }

            // Check if i is repeating or missing
            if (cnt == 2) repeating = i;
            else if (cnt == 0) missing = i;

            /* If both repeating and missing
            are found, break out of loop*/
            if (repeating != -1 && missing != -1)
                break;
        }
        
        // Return {repeating, missing}
        return {repeating, missing};
    }

    //Better Solution
    /*
    Intuition 
The better way is, instead of counting the occurrences every time, use the hashing technique to store the frequency of each element between 1 to N. Now, the element with frequency 2 will be the repeating number and the element with frequency 0 will be the missing number.

Approach 
The range of the number is 1 to N, so declare a hash array of size N+1 (as we want to store the frequency of N as well).
Iterate all the elements of the given array and update the hash array when an element is encountered .
Now, iterate in the hash array and return the two elements with frequencies 2 and 0.

    Complexity Analysis 
Time Complexity: O(2*N), for using two loops each running for N times, where N is the size of the array.

Space Complexity: O(N) for using a hash array.
    */

     vector<int> findMissingRepeatingNumbers(vector<int>& nums) {
        
        // Size of the array
        int n = nums.size(); 
        
         // Hash array to count occurrences
        int hash[n + 1] = {0};
        
        // Update the hash array:
        for (int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }

        int repeating = -1, missing = -1;
        
        // Find the repeating and missing number:
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 2) {
                repeating = i;
            } else if (hash[i] == 0) {
                missing = i;
            }

            /* If both repeating and missing 
            are found, break out of loop*/
            if (repeating != -1 && missing != -1) {
                break;
            }
        }
        
        // Return {repeating, missing}
        return {repeating, missing};
    }
};

int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};
    
    // Create an instance of Solution class
    Solution sol;

    vector<int> result = sol.findMissingRepeatingNumbers(nums);
    
    // Print the repeating and missing numbers found
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}
