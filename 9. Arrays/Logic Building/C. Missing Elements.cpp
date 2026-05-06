/*

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int BRUTEmissingNumber(vector<int> &nums){ //linear search
        int n = nums.size();
         for(int i = 0; i<=n;i++){
            int flag = 0;
            for(int j = 0; j <  n; j++){
                if(nums[j] == i){
                    flag = 1;
                    break;
                }
            } 
             if (flag == 0) return i;
         }
         return -1; //never execs but its there 
    }

    int BETTERmissingNumber(vector<int> &nums){ //hashing
            int n = nums.size();
            int freq[n+1] = {0};

            for (int num:nums)  
            {
                freq[num]++;
            }
            for (int i = 0; i <n; i++)
            {
                if(freq[i]==0)return i;
            }
    }

    int missingNumber(vector<int> &nums){ //sum 1 -> n
         int n = nums.size();
        int sum1 = (n*(n+1))/2;
        int sum2 = 0;
        for(int num:nums){
            sum2+=num;
        }
        int  missing = sum1-sum2;
        return missing;
    }

};



int main() {
    vector<int> nums = {1, 2, 4, 0};

    // Create an instance of the Solution class
    Solution solution;

    /* Call the missingNumber method 
    to find the missing number*/
    int ans = solution.missingNumber(nums);

    cout << "The missing number is: " << ans << endl;

    return 0;
}