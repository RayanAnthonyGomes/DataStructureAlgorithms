#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//Print Array Elements
void print(vector<int> &nums){
    int size = nums.size();
    cout << "Printing array: " << "\n";
    for(int i =  0; i < size; i++){
        cout << nums[i] << " ";
    }
}




// Linear Search Function
    int linearSearch(vector<int>& nums, int target) {
        // Traverse the entire vector
        for (int i = 0; i < nums.size(); i++) {
            // Check if current element is target
            if (nums[i] == target) {
                // Return index
                return i;
            }
        }
        // If target not found
        return -1;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 4;

    // Create an instance of the Solution class
    Solution sol;

    // Call the linearSearch method
    int result = sol.linearSearch(nums, target);

    // Print the result
    cout << result << endl;

    return 0;
}
