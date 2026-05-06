// Problem Statement
// Takahashi is a member of the astronomy club and is organizing his nighttime sky observation records. The observation data is recorded as a grid image with 
// H rows and 
// W columns, where each cell either contains nothing or contains a star.

// Cell positions are represented as 
// (i,j), where 
// (1,1) is the top-left cell, and 
// (i,j) denotes the cell in the 
// i-th row from the top and the 
// j-th column from the left. The 
// i-th row of the observation data is represented by the string 
// S 
// i
// ​
//  , where if the 
// j-th character of 
// S 
// i
// ​
//   is T, it means a star is captured in cell 
// (i,j), and if it is ., it means nothing is captured there.

// Given the observation data, find the positions of all cells that contain stars. Output the stars in ascending order of row number, and for stars in the same row, in ascending order of column number.

// Constraints
// 1≤H≤1000
// 1≤W≤1000
// H,W are integers
// S 
// i
// ​
  
// (1≤i≤H) is a string of length 
// W consisting only of . and T
// It is possible that no T is included (i.e., there are 
// 0 stars)
// Input
// The input is given from standard input in the following format:

// H 
// W
// S 
// 1
// ​
 
// S 
// 2
// ​
 
// ⋮
// S 
// H
// ​
 
// The first line contains the number of rows 
// H and the number of columns 
// W of the observation data, separated by a space.
// In the following 
// H lines, the 
// i-th line 
// (1≤i≤H) contains a string 
// S 
// i
// ​
//   of length 
// W representing the state of the 
// i-th row of the observation data.
// Output
// Output in the following format:

// K
// r 
// 1
// ​
  
// c 
// 1
// ​
 
// r 
// 2
// ​
  
// c 
// 2
// ​
 
// ⋮
// r 
// K
// ​
  
// c 
// K
// ​
 
// On the first line, output the total number of stars 
// K.
// On the following 
// K lines, output the positions of cells containing stars, one per line, in ascending order of row number, and for the same row number, in ascending order of column number. On the 
// k-th line 
// (1≤k≤K), output the row number 
// r 
// k
// ​
//   and column number 
// c 
// k
// ​
//   of the 
// k-th star, separated by a space.
// If 
// K=0, simply output 0 on the first line (no subsequent lines are needed).
// Sample Input 1
// Copy
// 3 5
// T..T.
// .....
// ..T..
// Sample Output 1
// Copy
// 3
// 1 1
// 1 4
// 3 3
// Sample Input 2
// Copy
// 5 8
// ........
// .T....T.
// ........
// .T..T...
// ....T..T
// Sample Output 2
// Copy
// 6
// 2 2
// 2 7
// 4 2
// 4 5
// 5 5
// 5 8
// Sample Input 3
// Copy
// 10 15
// T.............T
// ...T...........
// .......T.......
// ...............
// .T.............
// ...............
// ..........T....
// ...............
// .............T.
// T..T..T..T..T..
// Sample Output 3
// Copy
// 12
// 1 1
// 1 15
// 2 4
// 3 8
// 5 2
// 7 11
// 9 14
// 10 1
// 10 4
// 10 7
// 10 10
// 10 13

#include <bits/stdc++.h>
using namespace std;

int main() {
    //H rows and W cols
    int H, W;
    cin >> H >> W;
    string s;
    vector<pair<int,int>> st;
    for(int i = 1; i<=H;i++){
        cin >> s;
        for(int j = 1; j<=W; j++){
            if(s[j] == 'T'){
                st.push_back({i,j});
            }
        }
    }
    cout << st.size();
    cout << endl;

    for(auto star:st){
        cout << star.first << " " << star.second;
        cout << endl;
    }
    return 0;
}