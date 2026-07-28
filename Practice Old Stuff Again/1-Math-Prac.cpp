
#include<bits/stdc++.h>
using namespace std;

//1. Count Digits of a number given
        //Loops
int cntDigits(int x){
    if(x == 0) return  1;
    int cnt = 0;
    while(x>0){
        x = x/10;
        cnt++;
    }
    return cnt;
} //TC: O(digits)
    ///Maths
int cntDigitsMathWay(int x){
   if(x==0) return 1; 
   int cnt = log10(x) + 1;
   return cnt;
} //TC = O(log10(n))


//2. Count Odd Digits of a Number

int  cntOdd(int x){
    int cnt = 0;
    while(x>0){
        int lastD = x % 10;
        if(lastD % 2 == 1) cnt++;
        x = x/10;
    }
    return cnt;
}

//3. Reverse a number 
int  ReverseNumber(int  x){
    int revn = 0;
    while(x>0){
        int  ld= x %10;
        revn = (revn * 10) + ld;
        x = x/10;
    }
    return revn;
}

//Palindrome
bool isPalindrome(int x){
    if (x < 0) return false; // Negative numbers are never palindromes (e.g., -121 != 121-)
    int cpy = x; 
    int reverse = ReverseNumber(cpy); 
    return (x == reverse);
} 


// Largest Digit of a number

int largestDigit(int x){
    int l = 0;
    if(x==0) return 0;
    while(x>0){
        int ld = x%10;
        if(ld>l) l = ld;
        x = x/10;
    }
    return l;
} //TC: 0(log10(num))

//Factorial

long long factorial(int x){
    int ans = 1;
    for(int i = 1; i <= x; i++){
        ans = ans * i; 
    }
    return ans;
}
//TC: O(n)

//Armstrong Numbers

bool armstr(int x){
    int dup = x;
    int cnt = log10(x) + 1;
    int sum = 0;

    while(x > 0 ){
        int ld = x %10;
        sum += pow(ld,cnt);
        x=x/10;
    }
    return (dup == sum);
}


// Perfect Number

bool perfectNum(int x){
    int sum = 0;
    int dup = x;
    for(int i = 1; i <  x; i++){
        if(x % i == 0){
            sum += i;
        }
    }
    return (sum == dup);
}
//optimize
bool perfectNumopt(int x) {
    if (x <= 1) return false; // 1 and negative numbers are not perfect numbers
    
    int sum = 1; // 1 is always a proper divisor
    
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) {
            sum += i;
            if(i != (x / i)) { 
                sum += (x / i); // Add the companion divisor safely
            }
        }
    }
    return sum == x;
}


//Prime Numbers

bool isPrime(int x) {
    if(x==1) return false;
    for(int i = 2; i < x; i++){
        if(x%i ==0) return false;

    }
    return true;
}

bool isPrimeOpt(int x){ //sqrt method
     if(x==1) return false;
    for(int i = 2; i < sqrt(x); i++){
        if(x%i ==0) return false;
    }
    return true;
}
int primeTillN(int x){
    int cnt =0;
    for(int i = 2; i <= x; i++){
        if(isPrimeOpt(i)) cnt++;
    }
    return cnt;
}


//GCD of Two Numbers
int gcd(int n1,int n2){
    
    while(n1>0 && n2>0){
        if(n1>n2) n1 = n1 % n2;
        else n2 = n2 % n1;
    }
    if(n1 == 0) return n2;
    else return n1;

}


//LCM of two Numbers

int lcm(int n1,int n2){
    int G  = gcd(n1,n2);
    int l = (n1*n2)/G;
    return l;
}

//proper divisors

vector<int> brute(int n){
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(n%i==0) ans.push_back(i);
    }
    return ans;
}

vector <int> better(int n){
    vector<int> ans;
    int sqrtn = sqrt(n);
    for(int i = 1; i <= sqrtn; i++){
        if(n%i ==  0) ans.push_back(i);
        if(i != n/i) ans.push_back(n/i);
    }
    sort(ans.begin(), ans.end());
    return ans;

}

vector<int> best(int n){
    vector<int> small;
    vector<int> large;

    for(int i = 1; i*i <=n; i++){
        if(n%i==0) small.push_back(i);
        if(i!=n/i) large.push_back(n/i);
    }

    for(int i = large.size() - 1; i >= 0; i--){
        small.push_back (large[i]);
    }
    return small;
}

int  main(){
    int x;
    cin >> x;
    vector<int> ans = best(x);
    for(auto it:ans){
        cout << it << " ";
    }
    
}