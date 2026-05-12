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

    vector<vector<int>> fourSumBR(vector<int>& nums, int target) {
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
//Better Solution
/*
Intuition
The better approach uses simple mathematics where some calculative parameter is taken in RHS(right hand side) to compute the result.

For example if a + b + c + d = 0, then a + b + c = -d. Similar idea is used here.

Approach 
Iterate in the array from 0 to n-1 where n is the length of the array. Inside this loop, there will be the second loop(say j) that will run from i+1 to n-1. Then using a 3rd nested loop(say k) that runs from j+1 to n-1 try to calculate the value of the fourth element i.e. target - (nums[i]+nums[j]+nums[k]).
Declare a HashSet to store the specific array elements as we intend to search the fourth element in that HashSet.
If the fourth element exists in the HashSet, sort these four values i.e. nums[i], nums[j], nums[k], and the fourth element, and insert it in the set data structure declared to store ans.
After that, insert the k-th element i.e. nums[k] in the HashSet as we only want to insert those array elements that are in between indices j and k. Finally, return a list of stored quadruplets stored in the set data structure.

Complexity Analysis 
Time Complexity: O(N3xlog(M)), for using 3 nested loops and inside the loops there are some operations on the set data structure which take log(M) time complexity, where N is size of the array, M is number of elements in the set.

Space Complexity: O(2 x no. of the quadruplets)+O(N) for using a set data structure and a list to store the quads. This results in the first term. And the second space is taken by the set data structure we are using to store the array elements. At most, the set can contain approximately all the array elements and so the space complexity is O(N).

*/
        vector<vector<int>> fourSumBTR(vector<int>& nums, int target) {
        // Size of the array
        int n = nums.size(); 
        
        // Set to store unique quadruplets
        set<vector<int>> st; 

        // Checking all possible quadruplets
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                
                // Set to store elements seen so far in the loop
                set<long long> hashset; 
                for (int k = j + 1; k < n; k++) {
                    
                    // Calculate the fourth element needed to reach target
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    
                    /* Find if fourth element exists in
                    hashset (complements seen so far)*/
                    if (hashset.find(fourth) != hashset.end()) {
                        
                        // Found a quadruplet that sums up to target
                        vector<int> temp = {nums[i], nums[j], nums[k], static_cast<int>(fourth)};
                        // Sort the quadruplet to ensure uniqueness
                        sort(temp.begin(), temp.end()); 
                        st.insert(temp);
                        
                    }
                    
                    // Insert the kth element into hashset for future checks
                    hashset.insert(nums[k]);
                }
            }
        }
        
        // Convert set to vector (unique quadruplets)
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
//OOptimal Solution
/*
Intuition
The optimal approach is based on similar idea from 2-Sum and 3-Sum problem, which is sorting the entire array in the first step and to get the unique quads and using pointers to keep getting unique quads.
Approach 
Sort the entire array and iterate from 0 to n-1 in the array where n is length of the array, lets call the loop variable i. In each iteration, i will be fixed for all different values of the rest of the 3 pointers. Inside the loop, first check if the current and the previous element is the same and if it is, do nothing and continue to the next value of i.
After the first check inside the loop, introduce another fixed pointer j(runs from i+1 to n-1). Again check for duplicate elements and only perform any further operation if the elements are different.
Now, there will be 2 moving pointers i.e. k(starts from j+1) and l(starts from the last index). The pointer k will move forward and the pointer l will move backward in the array until they cross each other while the value of i and j will be fixed.
Check the sum i.e. nums[i]+nums[j]+nums[k]+nums[l], if the sum is greater, then the idea is to minimize the sum, hence we need lesser elements and so decrease the value of l and if the sum is lesser than the target, we need a bigger value and so we will increase the value of k.
If the sum is equal to the target, simply insert the quad i.e. nums[i], nums[j], nums[k], and nums[l] into answer and move the pointers k and l skipping the duplicate elements(i.e. by checking the adjacent elements while moving the pointers). Finally, return the list of unique quadruplets.

Complexity Analysis 
Time Complexity: O(N3), where N is the size of the given array.
Sorting the array takes O(NlogN) time, and the 3 nested loops take O(N3) time. Thus, the overall time complexity is O(N3) + O(NlogN), which boils down to O(N3).

Space Complexity: O(no. of quadruplets), this space is only used to store the answer. No extra space is used to solve this problem. So, from that perspective, space complexity can be written as O(1).



*/

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Vector to store the quadruplets that sum up to target
        vector<vector<int>> ans;
        
        int n = nums.size();
        
        // Sort the input array nums
        sort(nums.begin(), nums.end());
        
        // Iterate through the array to find quadruplets
        for (int i = 0; i < n; i++) {
            // Skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            for (int j = i + 1; j < n; j++) {
                // Skip duplicates for j
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                // Two pointers approach
                int k = j + 1;
                int l = n - 1;
                
                while (k < l) {
                    long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                    
                    if (sum == target) {
                        // Found a quadruplet that sums up to target
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        
                        // Skip duplicates for k and l
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        
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