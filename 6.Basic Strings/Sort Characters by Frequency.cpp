// You are given a string s. Return the array of unique characters, sorted by highest to lowest occurring characters.



// If two or more characters have same frequency then arrange them in alphabetic order.


// Example 1

// Input : s = "tree"

// Output : ['e', 'r', 't' ]

// Explanation :

// The occurrences of each character are as shown below :

// e --> 2

// r --> 1

// t --> 1.

// The r and t have same occurrences , so we arrange them by alphabetic order.

// Example 2

// Input : s = "raaaajj"

// Output : ['a' , 'j', 'r' ]

// Explanation :

// The occurrences of each character are as shown below :

// a --> 4

// j --> 2

// r --> 1
// Constraints

// 1 <= s.length <= 105
// s consist of only lowercase English characters.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Comparator to sort by frequency (descending) and alphabetically (ascending)
    static bool comparator(pair<int, char> p1, pair<int, char> p2) {
        if(p1.first > p2.first) return true;
        if(p1.first < p2.first) return false;
        return p1.second < p2.second;
    }
public:
    vector<char> frequencySort(string& s) {
        // Initialize frequency array
        pair<int, char> freq[26];
        for(int i = 0; i < 26; i++) {
            freq[i] = {0, i + 'a'};
        }

        // Count frequency of each character
        for(char ch : s) {
            freq[ch - 'a'].first++;
        }

        // Sort based on custom comparator
        sort(freq, freq + 26, comparator);

        // Collect characters with non-zero frequency
        vector<char> ans;
        for(int i = 0; i < 26; i++) {
            if(freq[i].first > 0) ans.push_back(freq[i].second);
        }
        return ans;
    }
};

// Main method to test the function
int main() {
    Solution sol;
    string s = "tree";
    vector<char> result = sol.frequencySort(s);
    for(char c : result) {
        cout << c << " ";
    }
    return 0;
}
