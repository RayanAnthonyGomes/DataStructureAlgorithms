//Problem statement
/*
Given an integer array nums and an integer target. Return all quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:



a, b, c, d are all distinct valid indices of nums.


nums[a] + nums[b] + nums[c] + nums[d] == target.


Notice that the solution set must not contain duplicate quadruplets. One element can be a part of multiple quadruplets. The output and the quadruplets can be returned in any order.


Example 1

Input: nums = [1, -2, 3, 5, 7, 9], target = 7

Output: [[-2, 1, 3, 5]]

Explanation:

nums[1] + nums[0] + nums[2] + nums[3] = 7

Example 2

Input: nums = [7, -7, 1, 2, 14, 3], target = 9

Output: []

Explanation:

No quadruplets are present which add upto 9

Now your turn!

Input: nums = [1, 1, 3, 4, -3], target = 5

(Give answer with the output and quadruplets sorted in ascending order)

Output:

Pick your answer


[-3, 1, 3, 4]

[[-3, 1, 4, 3], [-3, 1, 3, 4]]

[[-3, 4, 3, 1]]

[[-3, 1, 3, 4]]
Constraints

1 <= nums.length <= 200
-104 <= nums[i] <= 104
-104 <= target <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Brute  force  method
    /*

    Intuition
The idea is to check all possible quadruplets and among them, consider the ones whose sum is equal to the given target. And before considering them as our answer, sort the quadruplets in ascending order.

Approach 
For getting quadruplets, 4 nested loops will be used.
The first loop(say i) will run from 0 to n-1. Inside which, there will be the second loop(say j) that will run from i+1 to n-1. The third loop(say k) that runs from j+1 to n-1. Inside loop k, the fourth loop(say l) will run from k+1 to n-1, yielding 4 elements from array for considering a quadruplet.
Now, inside these four nested loops, check the sum of arr[i], arr[j], arr[k] and arr[l], and if it is equal to the target, sort this quadruplet and insert it in the set data structure declared to store ans. Finally, return a list of stored quadruplets.


    Complexity Analysis 
Time Complexity: O(N4) for using 4 nested loops, where N is size of the array.

Space Complexity: O(2 x no. of the quadruplets), for using a set data structure and a list to store the quads.
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Size of the array
        int n = nums.size(); 
        
        // Set to store unique quadruplets
        set<vector<int>> st;
        
        // Checking all possible quadruplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    for (int l = k + 1; l < n; l++) {
                        // Calculate the sum of the current quadruplet
                        long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                        
                        // Check if the sum matches the target
                        if (sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                            // Sort the quadruplet to ensure uniqueness
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        
        // Convert set to vector (unique quadruplets)
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

int main() {
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    
    // Create an instance of Solution class
    Solution sol;

    vector<vector<int>> ans = sol.fourSum(nums, target);
    
    // Print the result
    cout << "The quadruplets are: \n";
    for (auto& it : ans) {
        cout << "[";
        for (auto& ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    
    return 0;
}