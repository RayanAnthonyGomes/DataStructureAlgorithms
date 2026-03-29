// Print Q1, Q2, Q3, Q4 according to the quarter in which the point belongs to.
// Print "Origem" If the point is at the origin.
// Print "Eixo X" If the point is over X axis.
// Print "Eixo Y" if the point is over Y axis.

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    double x,y;
    cin >> x >> y;
    if(x>0 && y > 0) {
        cout <<"Q1";
    }else if(x<0 && y > 0){
        cout << "Q2";
    }else if(x<0 && y <0 ){
        cout << "Q3";
    }else if(x>0 && y < 0){
        cout << "Q4";
    }else if( x == 0 && y == 0){
        cout << "Origem";
    }else if(y==0){
        cout << "Eixo X";
    }else if(x==0){
        cout << "Eixo Y";
    }

    return 0;
}