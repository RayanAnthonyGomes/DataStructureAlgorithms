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



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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

    /*
    Complexity Analyis **BRUTE
Time Complexity: O(N3 x log(no. of unique triplets)), where N is size of the array. Using 3 nested loops & inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

Space Complexity: O(2 x no. of the unique triplets) for using a set data structure and a list to store the triplets.Complexity Analyis
Time Complexity: O(N3 x log(no. of unique triplets)), where N is size of the array. Using 3 nested loops & inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

Space Complexity: O(2 x no. of the unique triplets) for using a set data structure and a list to store the triplets.
    */

    //**Better Solution */

    /**
     *Intuition
     
The better approach uses simple mathematics where some calculative parameter is taken in RHS(right hand side) to compute the result.
For example if a + b + c = 0, then a + b = -c. Similar idea is used here.
    ***Approach 
Declare a set data structure to store unique triplets. Then iterate in the array lets call the variable i from index 0 to n -1. Inside it, there will be the second loop(say j) that will run from i+1 to n-1.
Declare another HashSet to store the array elements as we intend to search for the third element using this HashSet.
Inside the nested loop, calculate the value of the third element i.e. -(arr[i]+arr[j]).
If the third element exists in the HashSet, sort these 3 values i.e. arr[i], arr[j], and the third element, and insert it in the set data structure declared in step 1.
After that, insert the j-th element i.e. arr[j] in the HashSet as we only want to insert those array elements that are in between indices i and j. Finally, return a list of triplets stored in the set data structure.

    ***Complexity Analysis
Time Complexity: O(N2 x log(no. of unique triplets)), where N is size of the array.
Inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. However, we are not considering the time complexity of sorting, as we are only sorting 3 elements each time.
Note: For Java (HashSet), insertion operation takes O(1) time. Thus, the overall time complexity for Java code will be O(N2)

Space Complexity: O(2 x no. of the unique triplets) + O(N) for using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.
     */

     vector<vector<int>> threeSum(vector<int>& nums) {
        // Set to store unique triplets
        set<vector<int>> tripletSet;

        int n = nums.size();

        // Check all possible triplets
        for (int i = 0; i < n; i++) {
            // Set to store elements seen so far in the loop
            set<int> hashset;

            for (int j = i + 1; j < n; j++) {
                // Calculate the 3rd element needed to reach target
                int third = - (nums[i] + nums[j]);

                /* Find if third element exists in
                hashset (complements seen so far)*/
                if (hashset.find(third) != hashset.end()) {
                    // Found a triplet that sums up to target
                    vector<int> temp = {nums[i], nums[j], third};
                    
                    /* Sort the triplet to ensure 
                    uniqueness when storing in set*/
                    sort(temp.begin(), temp.end());
                    tripletSet.insert(temp);
                }
                
                /* Insert the current element
                into hashset for future checks*/
                hashset.insert(nums[j]);
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
