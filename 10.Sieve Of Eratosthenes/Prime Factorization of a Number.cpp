// rime factorisation of a Number
// Hard

// Hints
// Company
// You are given an integer array queries of length n.

// Return the prime factorization of each number in array queries in sorted order.


// Example 1

// Input : queries = [2, 3, 4, 5, 6]

// Output : [ [2], [3], [2, 2], [5], [2, 3] ]

// Explanation : The values 2, 3, 5 are itself prime numbers.

// The prime factorization of 4 will be --> 2 * 2.

// The prime factorization of 6 will be --> 2 * 3.

// Example 2

// Input : queries = [7, 12, 18]

// Output : [ [7], [2, 2, 3], [2, 3, 3] ]

// Explanation : The value 7 itself is a prime number.

// The prime factorization of 12 will be --> 2 * 2 * 3.

// The prime factorization of 18 will be --> 2 * 3 * 3.

// Now your turn!

// Input : queries = [15, 20]

// Output:

// Pick your answer


// [ [2, 3, 5], [2, 2, 5] ]

// [ [3, 5], [2, 2, 5] ]

// [ [3, 5], [2, 3, 5] ]

// [ [2, 5], [3, 5] ]
// Constraints

// 1 <= n <= 105
// 2 <= queries[i] <= 2*105

// Hints


// Hint 1
// A brute-force approach iterates through each number in queries and finds prime factors by checking divisibility from 2 to sqrt(num). This runs in O(n√m) (where m is the largest number in queries), which is inefficient for large numbers.

// Hint 2
// "A better approach is the Modified Sieve of Eratosthenes, which: Precomputes the smallest prime factor (SPF) for all numbers up to the max(queries). Uses SPF to quickly factorize numbers in O(log m) time per number instead of checking divisibility repeatedly."

// Frequently Occurring Doubts


// Why use SPF instead of brute-force division?
// The Smallest Prime Factor (SPF) array allows factorization in O(log m) per number by iteratively dividing by precomputed smallest primes. Brute-force checking requires O(√m) per number, which is slower.

// Can we use the Sieve of Eratosthenes directly for factorization?
// Standard Sieve finds primes, but Modified Sieve precomputes SPF, allowing faster factorization.

// nterview Follow-ups


// How does this compare to Pollard’s Rho algorithm for factorization?
// Pollard’s Rho is used for extremely large numbers (e.g., 10¹⁸+), whereas SPF is best for numbers ≤ 10⁶.

// How would you modify this approach to return factors with their exponents (e.g., {2:3, 5:1} for 40)?
// Instead of storing factors in a list, use a dictionary to count occurrences.


#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000

vector<int> SPF(MAX_N + 1); // Smallest Prime Factor for every number

void sieve(){
    for (int i = 2; i <= MAX_N; i++){
        if(SPF[i] == 0){ // i is prime
            for (int j = i; j <= MAX_N; j += i){
                if (SPF[j] == 0)
                    SPF[j] = i; // Mark the smallest prime factor
            }
        }
    }
    return;
}

vector<int> primeFact(int n){
    vector<int> ans;
    while(n!= 1){
        ans.push_back(SPF[n]);
        n = n / SPF[n];
    }
    return ans;
}

vector<vector<int>> primeFactors(vector<int> &queries){
    sieve(); // Precompute SPF for all numbers up to MAX_N
    vector<vector<int>> ans;
    for(int i = 0; i < queries.size(); i++){
        ans.push_back(primeFact(queries[i]));
    }
    return ans;
}

int main(){
    cout << "Enter the number of queries: ";
    int n;
    cin >> n;
    vector<int> queries(n);
    cout << "Enter the queries: ";
    for(int i = 0; i < n; i++){
        cin >> queries[i];
    }
    vector<vector<int>> ans = primeFactors(queries);
    for(int i = 0; i < ans.size(); i++){
        cout << "[ ";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "]" << endl;
    }
}