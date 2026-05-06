/*
C - Maximizing Investment /
Time Limit: 2 sec / Memory Limit: 1024 MiB

Score :
366 pts

Problem Statement
Takahashi is investing in
N stocks. The current asset value of stock
i (
1≤i≤N) is
S
i
​
 .

Takahashi will now perform the following operation exactly
K times.

Choose one of the
N stocks and double its current asset value.
He may freely choose which stock to select for each operation, and the same stock may be chosen multiple times. If the same stock is chosen multiple times, the doubling operation is applied cumulatively each time. For example, if a stock with asset value
S is chosen
3 times, its asset value becomes
2
3
 ×S=8S.

Takahashi wants to maximize the total asset value of all
N stocks after performing all
K operations.

When the choice of stocks for the operations is made optimally, find the maximum possible total asset value of the
N stocks after
K operations. Since the answer can be very large, output the maximum total modulo
10
9
 +7.

Constraints
1≤N≤2×10
5

1≤K≤10
18

1≤S
i
​
 ≤10
9
  (
1≤i≤N)
All input values are integers.
Input
Copy
N
K
S
1
​

S
2
​

…
S
N
​

The first line contains an integer
N representing the number of stocks and an integer
K representing the number of operations, separated by a space.
The second line contains integers
S
1
​
 ,S
2
​
 ,…,S
N
​
  representing the asset values of each stock before the operations, separated by spaces.
Output
Output in one line the maximum total asset value of the
N stocks when the
K operations are performed optimally, modulo
10
9
 +7.

Sample Input 1
Copy
3 2
1 3 2
Sample Output 1
Copy
15
Sample Input 2
Copy
4 3
5 5 1 2
Sample Output 2
Copy
48
Sample Input 3
Copy
10 20
12 7 25 3 18 30 1 9 14 22
Sample Output 3
Copy
31457391
Sample Input 4
Copy
40 123456789012345678
100000000 250000000 333333333 123456789 987654321 456789123 789123456 111111111 222222222 444444444 555555555 666666666 777777777 888888888 999999937 314159265 271828182 161803398 141421356 173205080 999999999 1 2 3 999999998 500000000 600000000 700000000 800000000 900000000 135791357 246802468 102030405 908070605 112233445 556677889 424242424 123123123 321321321 999000999
Sample Output 4
Copy
448506850
Sample Input 5
Copy
1 1000000000000000000
1000000000
Sample Output 5
Copy
963666222
*/