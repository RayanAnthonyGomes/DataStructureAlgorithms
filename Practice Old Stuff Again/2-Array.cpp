#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Print Array Elements
    void print(vector<int> &nums)
    {
        int size = nums.size();
        cout << "Printing array: " << "\n";
        for (int i = 0; i < size; i++)
        {
            cout << nums[i] << " ";
        }
    }

    // Sum of all array elements
    int sumArr(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum;
    }

    // Count  odd numbers  in  an array

    int cntOdd(vector<int> &nums)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 1)
                cnt++;
        }
        return cnt;
    }

    // Reverse given array
    void revArr(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++, right--;
        }
    }

    // Check  if array is  sorted in asc  order
    bool isSorted(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - i])
            {
                return false;
            }
        }
        return true;
    }

    // Linear Search Function
    int linearSearch(vector<int> &nums, int target)
    {
        // Traverse the entire vector
        for (int i = 0; i < nums.size(); i++)
        {
            // Check if current element is target
            if (nums[i] == target)
            {
                // Return index
                return i;
            }
        }
        // If target not found
        return -1;
    }


    //Largest Number in an array
    int largestNum(vector<int> &nums){
        
        int largest = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > largest){
                largest = nums[i];
            }
        }
        return largest;
    }

    ///Array  Fundamentals
    /*
    Problems:
    Second Largest Number in an array
    Maximum consecutive 1's in an array
    Left Roate Array by one
    Left Rotate Array by k places
    */

    // Second Largest Number in an array
        //Brute Force Approach
    int secondLargestBrute(vector<int> &nums){
        int n = nums.size();
        if(n < 2) return -1;
        sort(nums.begin(), nums.end());
        int largest = nums.back();
        int  secondLargest = -1;
        for(int i = n-2; i>=0; i--){
            if(nums[i] != largest){
                secondLargest = nums[i];
                break;
            }
        }

        return secondLargest;
    }
        //Better Approach
        int secondLargestBetter(vector<int> &nums){
            int n = nums.size();
            if(n < 2) return -1;
            int largest = INT_MIN;
            int secondLargest = INT_MIN;
            for(int i = 0; i <n; i++){
                largest = max(largest, nums[i]);
            }
            for(int i = 0; i<n; i++){
                if(nums[i] >  secondLargest && nums[i] < largest){
                    secondLargest = nums[i];
                }
            }
            return secondLargest;
        }
        
        //Optimal Approach
        int secondLargest(vector<int> &nums){
            if(nums.size()<2) return -1;
            int largest = INT_MIN;
            int secondLargest = INT_MIN;
            for(int i = 0; i<nums.size(); i++){
                if(nums[i] > largest){
                    secondLargest = largest;
                    largest = nums[i];
                }
                else if(nums[i] > secondLargest && nums[i] < largest){
                    secondLargest = nums[i];
                }
            }
            return secondLargest;
        }

    //Maximum Consecutive 1's in an array
        int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0; 
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                cnt++;
                maxi = max(maxi,cnt);
            }else{
                cnt = 0;
            }
        }
        return maxi;
    }

    //Left Rotate Array by one
      void rotateArrayByOne(vector<int>& nums) {
        // Store the first element in a temporary variable
        int temp = nums[0];
        
        // Shift elements to the left
        for (int i = 1; i < nums.size(); ++i) {
            nums[i - 1] = nums[i];
        }

        // Place the first element at the end
        nums[nums.size() - 1] = temp;
    }

    //Left rotate the array by k places
    void rotateBrute(vector<int> &nums, int k){
        int n =  nums.size();
        k = k%n;
        vector<int>  temp;
        
        for(int  i  = 0; i < k; i++){
            temp.push_back(nums[i]);
        }
        ///shift
        for(int i = k;  k < n;  i++){
            nums[i-k] = nums[i];
        }
        ///Pull  back to the  end of k eelems
        for(int i = 0; i<k;  i++){
            nums[n-k+i] = temp[i];
        }
    }

    //optimal
    void reverseArray(vector<int> &nums, int left, int right){
        while(left<right){
            swap(nums[left], nums[right]);
            left++, right--;
        }
    }
    void rot(vector<int> &nums,  int  k){
        int n = nums.size();
        k = k % n;
        ///Reverse first k  elems
        reverseArray(nums, 0,  k-1);

        //Reverse n-k elems
        reverseArray(nums, k, n-1);

        //reverse entire
        reverseArray(nums, 0, n-1);
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int target = 4;

    // Create an instance of the Solution class
    Solution sol;

    // Call the linearSearch method
    // int result = sol.linearSearch(nums, target);

    // Print the result
    // cout << result << endl;

    sol.print(nums); // This  works as printing array yay..

    // Returning the count of odd numbers
    int resultOdd = sol.cntOdd(nums);
    cout << endl
         << "Count of Odd nums: " << resultOdd;

    // reversing  the array; c
    cout << endl;
    sol.revArr(nums);
    cout << "After reversing  the array: ";
    sol.print(nums);

    // // reversing array again to get to  normal version
    // sol.revArr(nums); /// now its in asc form lets check. with another algo
    // cout << endl << "Checking if the array  is sorted  in asc order: ";
    // cout << boolalpha <<(sol.isSorted(nums));

    int secondLargest = sol.secondLargestBrute(nums);
    cout << endl << "Second Largest Number in the array: " << secondLargest << endl;

    int secondLargestBetter = sol.secondLargestBetter(nums);
    cout << "Second Largest Number (Better Approach): " << secondLargestBetter << endl;

    int secondLargestOptimal = sol.secondLargest(nums);
    cout << "Second Largest Number (Optimal Approach): " << secondLargestOptimal << endl;

    int maximumconsecuteones = sol.findMaxConsecutiveOnes(nums);
    cout << "Maximum consecutive 1's in this array is : " << maximumconsecuteones << endl;

    sol.rotateArrayByOne(nums);
    cout << "Array after left rotation by one: " << endl;
    sol.print(nums);

    //Rotate array  by  k  places  print
    int zzz = 20;
    sol.rot(nums, zzz);
    cout << "The Nums array after " <<  zzz << " rotations is  now: \n";
    sol.print(nums);

    //Code runner extension  not working please fix it soon
}

