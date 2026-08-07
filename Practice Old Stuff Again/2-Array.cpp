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

//Sum of all array elements
int sumArr(vector<int> &nums){
    int sum = 0;
    for(int i = 0; i <  nums.size(); i++){
        sum+= nums[i];
    }
    return sum;
}


//Count  odd numbers  in  an array

int cntOdd(vector<int> &nums){
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i]%2==1) cnt++;
    }
    return cnt;
}


//Reverse given array
void revArr(vector<int> &nums){
    int n = nums.size();
    int left = 0; 
    int right =  n-1;
    while(left<right){
        swap(nums[left], nums[right]);
        left++, right--;
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
    //int result = sol.linearSearch(nums, target);

    // Print the result
    //cout << result << endl;

    sol.print(nums); // This  works as printing array yay..

    //Returning the count of odd numbers
    int resultOdd = sol.cntOdd(nums);
    cout << endl << "Count of Odd nums: " <<resultOdd;


    //reversing  the array; c
    cout << endl;
    sol.revArr(nums); cout  << "After reversing  the array: ";
    sol.print(nums);
    return 0;
}
