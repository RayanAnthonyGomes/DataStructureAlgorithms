#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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
};

int main() {
    
    vector nums = {1, 1, 0, 1, 1, 1};

    // Create an instance of the Solution class
    Solution sol;

    int ans = sol.findMaxConsecutiveOnes(nums);

    cout << "The maximum consecutive 1's are " << ans << endl;
    return 0;
}