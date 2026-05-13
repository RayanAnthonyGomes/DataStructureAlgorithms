#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        void reverseArray(vector<int>& nums, int start, int end) {

        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++, end--;
        }
    }
public:
    //optimal
     void rotateArray(vector<int>& nums, int k) {
        int n = nums.size(); // Size of array
        k = k % n; // To avoid unnecessary rotations
        
        // Reverse the first k elements
        reverseArray(nums, 0, k - 1);

        // Reverse the last n-k elements
        reverseArray(nums, k, n - 1);

        // Reverse the entire vector
        reverseArray(nums, 0, n - 1);
    }

    void bruterotateArray(vector<int>& nums, int k) {
        //Brute force method
        int n = nums.size();
        k = k % n;
        vector<int> temp;

        //Jotogula k totogula vector e dimu
        for(int i = 0; i < k; i++){
            temp.push_back(nums[i]);
        }

        //shift korte hoibo
        for(int  i = k; i < n; i++) nums[i-k] = nums[i];

        //copy back the k elems at end
        for(int i = 0; i <k; i++) nums[n-k+i] = temp[i];
    }


};
void printArray(vector<int> nums) {
    for(int val : nums) {
        cout << val << " ";
    }
    cout << endl;
}
int main() {
    vector nums = {1, 2, 3, 4, 5, 6};
    int k = 2;

    cout << "Initial array: ";
    printArray(nums);

    // Create an instance of the Solution class
    Solution sol;
    
    /* Function call to rotate the 
    array to the left by k places */
    sol.rotateArray(nums, k);
    
    cout << "Array after rotating elements by " << k << " places: ";
    printArray(nums);

    return 0;
}