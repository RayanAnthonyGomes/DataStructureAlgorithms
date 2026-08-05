#include<bits/stdc++.h>
using namespace std;

class Solution:
    public:
    {
        //print array elemss
        void printarr(arr){
            cout << "Array Elements: " << endl;
            for(int i = 0; i< n; i++){
                cout << arr[i] << " ";
            }
        }
        //Print array elements sum
        int sumArr(arr,n){
            int sum  = 0;
            for(int i = 0; i  < n;  i++){
                sum+= arr[i];
            }
            return sum;
        }

        
    }



int main(){
    int array [] = {1,23,5,123,56,1,2,5};
    int n = array.size();

    Solution  sol = sol.sumArr(array,n);

    cout << sol;





}