/*
**Problem Statement**

Given an integer array nums. Return all triplets such that:



i != j, i != k, and j != k


nums[i] + nums[j] + nums[k] == 0.


Notice that the solution set must not contain duplicate triplets. One element can be a part of multiple triplets. The output and the triplets can be returned in any order.


Example 1

Input: nums = [2, -2, 0, 3, -3, 5]

Output: [[-2, 0, 2], [-3, -2, 5], [-3, 0, 3]]

Explanation:

nums[1] + nums[2] + nums[0] = 0

nums[4] + nums[1] + nums[5] = 0

nums[4] + nums[2] + nums[3] = 0

Example 2

Input: nums = [2, -1, -1, 3, -1]

Output: [[-1, -1, 2]]

Explanation:

nums[1] + nums[2] + nums[0] = 0

Note that we have used two -1s as they are separate elements with different indexes

But we have not used the -1 at index 4 as that would create a duplicate triplet

Now your turn!

Input: nums = [8, -6, 5, 4]

(Give answer with the output and triplets sorted in ascending order)

Output:

Pick your answer


[]

[[]]

[-6, 5, 4]

[[8, 5, 4]]
Constraints

1 <= nums.length <= 3000
-104 <= nums[i] <= 104
Hints


Hint 1
Begin by sorting the input array to simplify the process of finding triplets and managing duplicates. Sorting ensures that duplicates are adjacent and allows the use of a two-pointer technique.

Hint 2
Iterate through the array, fixing one element at a time. For each fixed element, look for a pair of numbers in the remaining array that sum to the negative of the fixed element. Use two pointers, one starting from the next element after the fixed element and the other from the end of the array.
Frequently Occurring Doubts


How do we avoid duplicate triplets?
Skip duplicate values of nums[i] while iterating. Skip duplicate values of nums[left] and nums[right] during the two-pointer traversal.

Why sort the array?
Sorting allows: Efficient identification of duplicates by comparing adjacent elements. Simplification of the two-pointer logic, as the relationship between pointer movements and the sum becomes predictable.
Interview Follow-ups


What if the input array is unsorted?
Sorting is part of the solution and is necessary for efficient implementation. It adds O(nlogn) complexity, which is negligible compared to the O(n2) time required for finding triplets.

How would you modify the algorithm to find all unique triplets with a sum equal to a different target?
Instead of finding triplets that sum to 0: Look for triplets that sum to a given target t. Use the same two-pointer approach, with nums[left]+nums[right]=t−nums[i].



*/

// brute  force solution

/*
Intuition
The most naive idea is to check all possible triplets using 3 loops and among them, consider the ones whose sum is equal to the given target 0.

Before taking them as the answer, sort the triplets in ascending order so as to consider only the unique triplets.

Approach 
Declare a set to store unique triplets that sum up to zero.
Use three nested loops to consider every possible triplet in the array:
Outer loop i runs from 0 to n-3.
Middle loop j runs from i+1 to n-2.
Inner loop k runs from j+1 to n-1.
For each triplet (nums[i], nums[j], nums[k]), check if their sum equals zero.
If yes, sort the triplet to maintain a consistent order and insert it into the set to avoid duplicates.
After processing all triplets, convert the set into a vector and return it as the final result.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Function to find triplets having sum equals to target
    vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
        // Set to store unique triplets
        set<vector<int>> tripletSet;

        int n = nums.size();

        // Check all possible triplets
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        // Found a triplet that sums up to target
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        
                        /* Sort the triplet to ensure
                         uniqueness when storing in set*/
                        sort(temp.begin(), temp.end());
                        tripletSet.insert(temp);
                        
                    }
                }
            }
        }

        // Convert set to vector (unique triplets)
        vector<vector<int>> ans(tripletSet.begin(), tripletSet.end());

       //Return the ans
        return ans;
    }
};

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    // Create an instance of Solution class
    Solution sol;

    vector<vector<int>> ans = sol.threeSum(nums);

    // Print the result
    for (auto& triplet : ans) {
        cout << "[";
        for (auto& num : triplet) {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << "\n";

    return 0;
}
