/*
--Problem Statement--
Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. The output can be returned in any order.


Example 1

Input: nums = [1, 2, 1, 1, 3, 2]

Output: [1]

Explanation:

Here, n / 3 = 6 / 3 = 2.

Therefore the elements appearing 3 or more times is : [1]

Example 2

Input: nums = [1, 2, 1, 1, 3, 2, 2]

Output: [1, 2]

Explanation:

Here, n / 3 = 7 / 3 = 2.

Therefore the elements appearing 3 or more times is : [1, 2]

Now your turn!

Input: nums = [1, 2, 1, 1, 3, 2, 2, 3](Give the solution sorted in ascending order)

Output:

Pick your answer


[0, 1]

[3, 6]

[1, 2]

[2, 5]
Constraints

n == nums.length.
2 <= n <= 105
-104 <= nums[i] <= 104

Hints


Hint 1
Use two counters to track two potential majority candidates. Count occurrences using a hash map (O(n) space). Collect elements that appear more than n/3 times.
Hint 2
Sort the array (O(n log n)). Scan linearly to find elements occurring more than n/3 times
Frequently Occurring Doubts


Why can there be at most two elements appearing more than n/3 times?
If there were 3 elements appearing more than n/3 times, their total count would exceed n, which is impossible.

Why is sorting less efficient?
Sorting takes O(n log n), which is slower than O(n) Boyer-Moore.

Interview Follow-ups


How would you modify this for elements appearing more than n/k times?
To find elements that appear more than n/k times in an array, modify the Boyer-Moore Voting Algorithm to track k - 1 candidates instead of just 2.

*/

/*
Brute Force Intuition 
The naive way is to use nested loops to count the occurrences of each of the elements and if the count is greater than one third of the size of array, include the element in the answer.

Can there be more than 2 majority elements ? Let's understand the scenario!
To understand why there can't be more than two majority elements (elements that appear more than n/3 times) in an array of size n, let's use a simple mathematical reasoning. A majority element in this context is defined as an element that appears more than n/3 times in the array. For an element to be a majority element, it must appear more than n/3 times. Let's assume there are more than two such majority elements. Let's denote these elements as A, B, and C.

Since each of these elements appears more than n/3 times, the combined frequency of these three elements would be: frequency of 𝐴 + frequency of 𝐵 + frequency of 𝐶 > 𝑛/3 + 𝑛/3 + 𝑛/3 = 𝑛

Now, the total number of occurrences of all elements in the array cannot exceed n, the size of the array. This means the combined frequency of any three elements each appearing more than n/3 times would exceed the total size of the array, which is a contradiction. Therefore, it's mathematically impossible for there to be more than two elements in the array that each appear more than n/3 times.

Approach 
Iterate in the array to select the elements of the array one by one. Now, for each unique element, run another loop and count its occurrence in the given array. If any element occurs more than the floor of (N/3), include it in our answer.
While traversing if any element that is already included in our answer is found, just skip it. When the answer array size is already 2, break out of loop, as there cant be more than 2 elements.
Return the answer array or -1 if no such element is found.

Complexity Analysis 
Time Complexity: O(N2), where N is the size of the array. As for every element of the array the inner loop runs for N times.

Space Complexity: O(1) the space used is so small that it can be considered constant.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find majority elements in an array
    vector<int> majorityElementTwoBr(vector<int>& nums) {
        
        // Size of the array
        int n = nums.size(); 
        
        // List of answers
        vector<int> result;
        
         for (int i = 0; i < n; i++) {
             
        /*Checking if nums[i] is not 
        already part of the answer*/
        if (result.size() == 0 || result[0] != nums[i]) {
            
            int cnt = 0;
            
            for (int j = 0; j < n; j++) {
                // counting the frequency of nums[i]
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                result.push_back(nums[i]);
        }
        
        //if result size is equal to 2 break out of loop
        if (result.size() == 2) break;
    }
    
    //return the majority elements
    return result;
    }

    //Better Solution
    /*
    Intuition 
A better idea is to use a data structure to reduce the number of look-up operations and hence to reduce the time complexity. Moreover, we have been calculating the count of the same element again and again, so reduce that also.

Approach 
Use a hashmap and store the elements as pairs. (Can also use frequency array based on the size of nums). Here the key will be the element of the array and the value will be the number of times it occurs.
Traverse the whole array and update the occurrence of each element.
After that, check the map if the value for any element is greater than the floor of N/3. If yes, include it in the answer. Else, iterate forward. At any point if we find that the size of answer array is 2, break out of the loop. Finally, return the answer.

Complexity Analysis 
Time Complexity: O(N), where N is size of the given array. For using an unordered map data structure, where insertion in the map takes O(1) time and we are doing it for N elements. On using map instead, the first term will be O(N*logN) for the best and average case and for the worst case, it will be O(N2).

Space Complexity: O(N) for uing a map data structure. A list that stores a maximum of 2 elements is also used, but that space used is so small that it can be considered constant.

    */
       vector<int> majorityElementTwoBetter(vector<int>& nums) {
        
        // size of the array
        int n = nums.size(); 
        
        // list of answers
        vector<int> result; 
        
        // declaring a map
        unordered_map<int, int> mpp;
        
        // least occurrence of the majority element
        int mini = int(n / 3) + 1;
        
        // storing the elements with its occurrence
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
            
            // checking if nums[i] is the majority element
            if (mpp[nums[i]] == mini) {
                result.push_back(nums[i]);
            }
            
            // if result size is equal to 2 break out of loop
            if (result.size() == 2) {
                break;
            }
        }
        
        // return the majority elements
        return result;
    }

    //Optimal/Best Solution
    /*
    Intuition 
Imagine you're in charge of a small party with 30 guests. Each guest has a favorite fruit, and you want to find out which fruits are most popular. Specifically, you want to know if any fruit is liked by more than a third of the guests (so more than 10 people).

As guests arrive, note their favorite fruit. Keep track of up to two different fruits at a time and how many people like each of these fruits. If a new guest likes one of the fruits you're tracking, increase the count for that fruit. If they like a different fruit and you have room to track another, you start tracking that fruit. If both tracking slots are full and the new fruit is different, you reduce the count for both tracked fruits. After all guests have arrived, you have two potential popular fruits. To confirm, go through the list one more time and count how many guests like each of these fruits.

Approach 
Initialize 4 variables: cnt1 & cnt2 for tracking the counts of elements and el1 & el2 for storing the majority of elements.
Traverse through the given array. If cnt1 is 0 and the current element is not el2 then store the current element of the array as el1 along with increasing the cnt1 value by 1.
If cnt2 is 0 and the current element is not el1 then store the current element of the array as el2 along with increasing the cnt2 value by 1.
If the current element and el1 are the same increase the cnt1 by 1 and if the current element and el2 are the same increase the cnt2 by 1.
Other than all the above cases decrease cnt1 and cnt2 by 1. The integers present in el1 & el2 should be the result we are expecting. So, using another loop, to manually check their counts if they are greater than the floor(N/3).

Complexity Analysis 
Time Complexity: O(N) + O(N), where N is size of the given array. The first O(N) is to calculate the counts and find the expected majority elements. The second one is to check if the calculated elements are the majority ones or not.

Space Complexity: O(1) for only using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.
    */
       vector<int> majorityElementTwo(vector<int>& nums) {
        
        // Size of the array
        int n = nums.size(); 

        // Counts for elements el1 and el2
        int cnt1 = 0, cnt2 = 0;
        
        /*Initialize Element 1 and 
        Element 2 with INT_MIN value*/
        int el1 = INT_MIN, el2 = INT_MIN;

        /*Find the potential candidates using
        Boyer Moore's Voting Algorithm*/
        for (int i = 0; i < n; i++) {
            
            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                // Initialize el1 as nums[i]
                el1 = nums[i]; 
            }
            else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                // Initialize el2 as nums[i]
                el2 = nums[i]; 
            } 
            else if (nums[i] == el1) {
                // Increment count for el1
                cnt1++;
            } 
            else if (nums[i] == el2) {
                // Increment count for el2
                cnt2++; 
            } 
            else {
                // Decrement count for el1
                cnt1--; 
                 // Decrement count for el2
                cnt2--;
            }
        }

        //Validate the candidates by counting occurrences in nums
        //Reset counts for el1 and el2
        cnt1 = 0, cnt2 = 0; 
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == el1) {
                // Count occurrences of el1
                cnt1++; 
            }
            if (nums[i] == el2) {
                 // Count occurrences of el2
                cnt2++;
            }
        }

        /* Determine the minimum count
        required for a majority element*/
        int mini = n / 3 + 1;
        
        // List of answers
        vector<int> result; 

        /*Add elements to the result vector
        if they appear more than n/3 times*/
        if (cnt1 >= mini) {
            result.push_back(el1);
        }
        if (cnt2 >= mini && el1 != el2) {
            // Avoid adding duplicate if el1 == el2
            result.push_back(el2); 
        }

        // Uncomment the following line if you want to sort the answer array
        // sort(result.begin(), result.end()); // TC --> O(2*log2) ~ O(1);

        //return the majority elements
        return result;
    }

};

int main() {
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    
    // Create an instance of Solution class
    Solution sol;

    vector<int> ans = sol.majorityElementTwo(arr);
    
    // Print the majority elements found
    cout << "The majority elements are: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}

