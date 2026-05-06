/*
D - Card Taking Game / 
Time Limit: 2 sec / Memory Limit: 1024 MiB

Score : 
400 pts

Problem Statement
Takahashi and Aoki play a game using cards.

N cards are arranged in a row on the table, and the 
i-th card from the left has an integer 
V 
i
​
  written on it. Note that 
V 
i
​
  may be negative.

The two players take cards according to the following rules:

Takahashi goes first, Aoki goes second, and they take turns alternately.
On their turn, a player chooses exactly one card from either the left end or the right end of the row of cards remaining on the table, takes it, and places it in their hand. The taken card is removed from the table, and the order of the remaining cards does not change.
The game ends when all cards have been taken.
Both players know all information including each other's strategies, and each plays optimally to maximize the sum of the integers written on the cards they have taken.

When both players play optimally, find the value obtained by subtracting the sum of the integers written on the cards Aoki took from the sum of the integers written on the cards Takahashi took.

Constraints
1≤N≤3000
−10 
9
 ≤V 
i
​
 ≤10 
9
 
All inputs are integers.
Input
Copy
N
V 
1
​
  
V 
2
​
  
… 
V 
N
​
 
The first line contains an integer 
N representing the number of cards.
The second line contains the integers 
V 
1
​
 ,V 
2
​
 ,…,V 
N
​
  written on each card, separated by spaces. Here, 
V 
i
​
  is the integer written on the 
i-th card from the left.
Output
Print in one line the value obtained by subtracting the sum of the integers written on the cards Aoki took from the sum of the integers written on the cards Takahashi took, when both players play optimally.

Sample Input 1
Copy
4
3 1 2 5
Sample Output 1
Copy
3
Sample Input 2
Copy
4
-1 5 -3 2
Sample Output 2
Copy
11
Sample Input 3
Copy
10
8 -3 5 12 -7 2 9 -1 6 4
Sample Output 3
Copy
15
Sample Input 4
Copy
20
15 -8 23 4 -12 7 19 -3 11 6 -5 14 2 -9 18 1 -6 10 8 -2
Sample Output 4
Copy
53
Sample Input 5
Copy
1
-1000000000
Sample Output 5
Copy
-1000000000
*/