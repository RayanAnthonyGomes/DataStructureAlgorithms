/*
Given two sorted arrays, nums1 and nums2, return an array containing the intersection of these two arrays. Each element in the result must appear as many times as it appears in both arrays; that is, if an element appears x times in nums1 and y times in nums2, it should appear min(x, y) times in the result.



The intersection of two arrays is an array where all values are present in both arrays.


Example 1

Input: nums1 = [1, 2, 2, 3, 5], nums2 = [1, 2, 7]

Output: [1, 2]

Explanation:

The elements 1, 2 are the only elements present in both nums1 and nums2

Example 2

Input: nums1 = [1, 2, 2, 3, 3, 3], nums2 = [2, 3, 3, 4, 5, 7]

Output: [2, 3, 3]

Explanation:

The element 2 appears in both arrays only one time.

The element 3 appears in both arrays two times so we add element 3 equal to its number of occurrences.

Now your turn!

Input: nums1 = [-45, -45, 0, 0, 2], nums2 = [-50, -45, 0, 0, 5, 7]

Output:

Pick your answer


[-50, -45, 0, 2, 5, 7]

[-45, 0]

[0, 0, -45]

[-45, 0, 0]
Constraints

1 <= nums1.length, nums2.length <= 1000
-104 <= nums1[i], nums2[i] <= 104
Both nums1 and nums2 are sorted in non-decreasing order.

Hints


Hint 1
Use two pointers to traverse both arrays simultaneously. This helps efficiently find common elements since both arrays are sorted.Add an element to the intersection only if it is present in both arrays at the same index of the pointers.

Hint 2
If duplicates are not allowed in the result, skip consecutive duplicate elements in either array during traversal.

What happens if one or both arrays are empty?
If either array is empty, the intersection is empty since there are no common elements.
How does the algorithm handle duplicates within the arrays?
If duplicates are allowed in the intersection: Include the common element as many times as it appears in both arrays. If duplicates are not allowed: Skip consecutive duplicates in both arrays while processing.

How would you handle unsorted arrays?
For unsorted arrays: Sort both arrays first O(mlogm+nlogn). Apply the two-pointer technique to find the intersection.


*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //BRUTE ->Function to find intersection of two sorted arrays
    vector<int> BRUTEintersectionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        // To maintain visited status
        vector<int> visited(nums2.size(), 0);
   
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {

               /*If nums1[i] is equal to nums2[j] and nums2[j]
               is not visited then add nums2[j] in ans.*/
                if (nums1[i] == nums2[j] && visited[j] == 0) {
                    ans.push_back(nums2[j]);
                    
                    // Mark as visited
                    visited[j] = 1;
                    
                    break;
                } 
                /** If num2[j] is greater than nums1[i] 
                break out of the loop */
                else if (nums2[j] > nums1[i])
                    break; 
            }
        }
       //Return ans vector
        return ans;
    }

    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2) {
        // Vector to store the intersection elements
        vector<int> ans;
        // Pointers for nums1 and nums2
        int i = 0, j = 0; 


        // Traverse both arrays using two pointers approach
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums2[j] < nums1[i]) {
                j++;
            } 
          // nums1[i] == nums2[j]
          else { 
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }
       
       //Return intersection
        return ans;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 3, 4, 5, 6, 7};
    vector<int> nums2 = {3, 3, 4, 4, 5, 8};

    // Create an instance of the Solution class
    Solution finder;

    // Get intersection of nums1 and nums2 using class method
    vector<int> ans = finder.intersectionArray(nums1, nums2);

    cout << "Intersection of nums1 and nums2 is:" << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}