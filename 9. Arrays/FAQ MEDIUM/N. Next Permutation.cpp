/**Problem Statement
 * Next Permutation
Medium

Company
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.



For example, for arr = [1,2,3], the following are all the permutations of arr:

[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].



The next permutation of an array of integers is the next lexicographically greater permutation of its integers.

More formally, if all the permutations of the array are sorted in lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted order.



If such arrangement is not possible (i.e., the array is the last permutation), then rearrange it to the lowest possible order (i.e., sorted in ascending order).



You must rearrange the numbers in-place and use only constant extra memory.


Example 1

Input: nums = [1,2,3]

Output: [1,3,2]

Explanation:

The next permutation of [1,2,3] is [1,3,2].

Example 2

Input: nums = [3,2,1]

Output: [1,2,3]

Explanation:

[3,2,1] is the last permutation. So we return the first: [1,2,3].

Now your turn!

Input: nums = [1,1,5]

Output:

Pick your answer


[1, 5, 1]

[1, 1, 5]

[5, 1, 1]

[1, 1, 5]
Constraints

1 <= nums.length <= 100
0 <= nums[i] <= 100
 */

 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Function to get the next permutation of given array
    void nextPermutationBruteForce(vector<int>& nums) {
        // Get all the Permutations
        vector<vector<int>> ans = getAllPermutations(nums);
        
        int index = -1; // Current permutation index
        
        /* Perform a linear search to get the
        permutation of current permutation */
        for(int i = 0; i < ans.size(); i++) {
            if(nums == ans[i]) {
                index = i;
                break;
            }
        }
        
        // Store the next permutation in-place
        if(index == ans.size() - 1) nums = ans[0];
        else nums = ans[index + 1];
        
        return;
    }
    
private:
    /* Function to generate all permutations of 
    the given array in sorted order */
    vector<vector<int>> getAllPermutations(vector<int> &nums) {
        vector<vector<int>> ans; // To store the permutation
        
        // Recursive Helper function call 
        helperFunc(0, nums, ans);
        
        sort(ans.begin(), ans.end()); // Sort the permutations
        return ans; // Return the result
    }
    
    // Helper function to get all the permutations of the given array
    void helperFunc(int ind, vector<int> &nums, 
                        vector<vector<int>> & ans) {
        
        // Base case
        if(ind == nums.size()) {
            // Add the permutation to the answer
            ans.push_back(nums);
            return;
        }
        
        // Traverse the array
        for(int i = ind; i < nums.size(); i++) {
            swap(nums[ind], nums[i]); // Swap-In
            
            // Recursively call the helper function
            helperFunc(ind+1, nums, ans);
            
            swap(nums[ind], nums[i]); // Swap-Out
        }
        
        return;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    // Output
    cout << "Given array: ";
    for(int x : nums) cout << x << " ";
    
    // Function call to get the next permutation of given array
    sol.nextPermutation(nums);
    
    // Output
    cout << "\nNext Permutation: ";
    for(int x : nums) cout << x << " ";
    
    return 0;
}