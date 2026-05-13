 /*
 Given an integer array nums, rotate the array to the left by one.



Note: There is no need to return anything, just modify the given array.


Example 1

Input: nums = [1, 2, 3, 4, 5]

Output: [2, 3, 4, 5, 1]

Explanation:

Initially, nums = [1, 2, 3, 4, 5]

Rotating once to left -> nums = [2, 3, 4, 5, 1]

Example 2

Input: nums = [-1, 0, 3, 6]

Output: [0, 3, 6, -1]

Explanation:

Initially, nums = [-1, 0, 3, 6]

Rotating once to left -> nums = [0, 3, 6, -1]

Now your turn!

Input: nums = [7, 6, 5, 4]

Output:

Pick your answer


[5, 6, 4, 7]

[5, 4, 7, 6]

[6, 5, 4, 7]

[4, 7, 6, 5]
Constraints

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 */
 #include <bits/stdc++.h>
 using namespace std;
 
class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int temp= nums[0];
        for(int i=1; i <nums.size();i++) nums[i-1] = nums[i];
        nums[nums.size()-1] = temp;
    }
};
 //remember 1 thing. When interviewer asks what extra spaace are u using? -> 0(1)
 //what space are you using? we are also using the array  so o(n) is gonna come to consideration as well.
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};

    solution.rotateArrayByOne(nums);

    for (int num : nums) {
        cout << num << " "; // Output the rotated array
    }

    return 0;
}