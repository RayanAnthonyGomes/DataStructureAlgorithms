// Print all primes till N
// Hard

// Hints
// Company
// You are given an integer n.

// Print all the prime numbers till n (including n).

// A prime number is a number that has only two divisor's 1 and the number itself.


// Example 1

// Input : n = 7

// Output : [2, 3, 5, 7]

// Explanation : The number 2 has only two divisors 1 and 2.

// The number 3 has only two divisors 1 and 3.

// The number 5 has only two divisors 1 and 5.

// The number 7 has only two divisors 1 and 7.

// Example 2

// Input : n = 2

// Output : [2]

// Explanation : There is only one number 2 that is a prime till 2.

// Now your turn!

// Input : n = 10

// Output:

// Pick your answer


// [1, 2, 3, 5, 7]

// [2, 4, 5, 7]

// [2, 3, 6, 7]

// [2, 3, 5, 7]
// Constraints

// 2 <= n <= 5*105


// Hint 1
// A brute-force approach would check each number from 2 to n and determine if it is prime by checking divisibility from 2 to sqrt(n). However, this results in O(n√n) complexity, which is inefficient for large n.

// Hint 2
// "A more efficient approach is the Sieve of Eratosthenes, which: Assumes all numbers are prime initially. Iteratively marks multiples of known primes as non-prime. Outputs the remaining numbers as prime."

// Frequently Occurring Doubts


// Why is Sieve of Eratosthenes more efficient than brute force?
// Instead of checking divisibility for each number, it eliminates non-primes in bulk by marking multiples. It avoids redundant computations, making it significantly faster for large numbers.

// Can we generate primes more efficiently for very large numbers (n > 10^9)?
// Segmented Sieve: Breaks n into smaller chunks, reducing memory usage. Miller-Rabin Test: Probabilistic prime-checking used for huge numbers.

// How can we efficiently check if a single number is prime?
// Use the Miller-Rabin Primality Test for fast probabilistic prime checking.

// What if we needed only the k-th prime number instead of all primes?
// Use the prime-counting function with binary search on the sieve output.

#include <bits/stdc++.h>
using namespace std;

vector<int> primetilln(int n) {
    vector<int> isPrime(n+1,1);
    vector<int> ans;
    for(long long i = 2; i<= n; i++){
        if(isPrime[i]){
            ans.push_back(i);
            for(long long val = i*i; val <= n; val += i){
                isPrime[val] = 0;
            }
        }
    }
    return ans;
}

int main(){
    cout << "Enter the value of n: ";
    int n;
    cin >> n;
    vector<int> ans = primetilln(n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
        cout << endl;
}
} 
