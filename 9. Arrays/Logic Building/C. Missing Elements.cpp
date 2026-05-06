/*
ind missing number
Easy

Hints
Company
Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.


Example 1

Input: nums = [0, 2, 3, 1, 4]

Output: 5

Explanation:

nums contains 0, 1, 2, 3, 4 thus leaving 5 as the only missing number in the range [0, 5]

Example 2

Input: nums = [0, 1, 2, 4, 5, 6]

Output: 3

Explanation:

nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the range [0, 6]

Now your turn!

Input: nums = [1, 3, 6, 4, 2, 5]

Output:

Pick your answer


6

7

0

8
Constraints

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.

Why use the sum formula instead of iterative checks?
The sum formula is faster (O(n)) compared to iterative checks (O(n2)) because the sum formula requires only a single pass to compute the sum of array elements and one subtraction. Iterative checks require comparing each number in the range to the array, which is inefficient.
What happens if the missing number is 0 or n?
If 0 is missing, the sum formula still works because S includes 0 by definition. If n is missing, the sum formula accounts for n since it calculates the sum of the entire range, and subtracting the array sum leaves n

Interview Follow-ups


How would you handle the problem if duplicates are allowed in the array?
If duplicates are allowed: Use a hash set to track numbers present in the array. Iterate through 0 to n, checking if each number exists in the set. This approach requires O(n) time and O(n) space.

How does the performance compare between the sum formula and XOR methods?
Both methods have O(n) time complexity and O(1) space complexity. The sum formula involves addition and subtraction, while the XOR method uses bitwise operations. XOR is slightly faster in practice due to the lower computational cost of bitwise operations.


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int BRUTEmissingNumber(vector<int> &nums){ //linear search
        int n = nums.size();
         for(int i = 0; i<=n;i++){
            int flag = 0;
            for(int j = 0; j <  n; j++){
                if(nums[j] == i){
                    flag = 1;
                    break;
                }
            } 
             if (flag == 0) return i;
         }
         return -1; //never execs but its there 
    }

    int BETTERmissingNumber(vector<int> &nums){ //hashing
            int n = nums.size();
            int freq[n+1] = {0};

            for (int num:nums)  
            {
                freq[num]++;
            }
            for (int i = 0; i <n; i++)
            {
                if(freq[i]==0)return i;
            }
    }

    int OPTIMALSUMmissingNumber(vector<int> &nums){ //sum 1 -> n
         int n = nums.size();
        int sum1 = (n*(n+1))/2;
        int sum2 = 0;
        for(int num:nums){
            sum2+=num;
        }
        int  missing = sum1-sum2;
        return missing;
    }

    int missingNumber(vector<int> &nums){ //sum 1 -> n
         int n = nums.size();
         int xor1 = 0, xor2 = 0;
         for(int i = 0; i<nums.size();i++){
            xor1  = xor1^(i+1); //xor  of 1->n
            xor2  = xor2^nums[i]; //xor  of array elems

         }
         return(xor1^xor2);
    }



};



int main() {
    vector<int> nums = {1, 2, 4, 0};

    // Create an instance of the Solution class
    Solution solution;

    /* Call the missingNumber method 
    to find the missing number*/
    int ans = solution.missingNumber(nums);

    cout << "The missing number is: " << ans << endl;

    return 0;
}