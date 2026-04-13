/*
OIE Excursion
time limit per test1 second
memory limit per test256 megabytes
Hector is on an excursion with the Spanish Olympiad in Informatics, visiting A Coruña, but he is desperate to sneak away to meet his friends Gustavo, Esomer, and Dani. To do so, he must cross a path guarded by n
 volunteers standing in a row, numbered from 1
 to n
; the i
-th volunteer watches over position i
.

Each volunteer has an internal timer. Initially (at second 0
), the i
-th volunteer's timer has a value ai
. Every second, all timers increase by 1
. Once a timer reaches m
, it wraps around to 0
. Specifically, at second x
, the i
-th volunteer's timer shows the value (ai+x)(modm)
.

The i
-th volunteer is only watching over position i
 when their timer is exactly 0
. At any other time, they are distracted and will not notice Hector.

Hector starts at position 0
, to the left of all volunteers. To escape, he must reach position n+1
. In the end of each second, Hector can choose to stay in his current position, move one position to the left, or move one position to the right. Note that Hector can't go to the left of position 0
.

Hector is caught if and only if, at the beginning of a second, he is at position i
 (1≤i≤n
) and the i
-th volunteer's timer is 0
.

Determine whether there exists a strategy for Hector to pass all volunteers and escape without being caught.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤104
). The description of the test cases follows.

Each test case consists of two lines:

The first line contains two integers n
 and m
 (2≤n≤2⋅105
, 2≤m≤109
) — the number of volunteers and the cycle length of the timers.
The second line contains n
 integers a1,a2,…,an
 (0≤ai<m
), where ai
 represents the initial value of the i
-th volunteer's timer at t=0
.
It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print a line containing either "YES" or "NO", representing whether Hector can escape. You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
Input
6
8 5
0 4 0 2 1 0 0 3
6 2
1 0 1 0 1 0
6 2
1 1 1 1 0 1
2 10
6 9
2 2
0 1
5 1000000000
1 2 3 4 999999999
Output
YES
YES
NO
YES
YES
YES
Note
Case 1: Hector can move right every second without waiting or moving left and escape, because there is no i
 such that (ai+i)(modm)=0
.

Case 2: One possible strategy is to wait for one second at the starting position and then move right every second without further waiting or moving left.
*/