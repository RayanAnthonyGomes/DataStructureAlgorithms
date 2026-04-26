#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function for selection sort
    vector<int> selectionSort(vector<int>& nums) {
        // Loop through the unsorted array
        for (int i = 0; i < nums.size() - 1; i++) {
            /*Assume the current 
            index is the smallest*/
            int minIndex = i;
            
            // Find the index of the smallest element
            for (int j = i + 1; j <nums.size(); j++) {
                /*Update minIndex if smaller 
                element is found */
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }
        
            // Swap only if minIndex is changed
            if (minIndex != i) {
                swap(nums[minIndex], nums[i]);
            }
        }
        return nums;
    }
};

int main() {

    vector<int> arr = {7, 5, 9, 2, 8};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Create an instance of the Solution class
    Solution s1;

    // function call for Selection Sort
    vector<int> sortedArr = s1.selectionSort(arr);

    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}



/*
    my explanation:
    2ta loop cholbe;
    first loop (i = 0; i < nums.size) porzonto cholbe  jekhane ami assume korbo je minimum index i
    second loop (j = i+1; j<numsss.size) porzonto cholbe jekhane ami compare korbo je ashol minindex  konta
        if(nums[j] < nums[minindex]) taile korbo minindex =  j;

    erpor  jodi minindex  != i  hoy  taile  swap(nums[minindex], nums[i])

    last e nums return korbo;
*/