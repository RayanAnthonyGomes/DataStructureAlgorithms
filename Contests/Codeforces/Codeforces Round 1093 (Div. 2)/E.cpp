/*
Unique Values (Hard version)
time limit per test2 seconds
memory limit per test256 megabytes
The difference between the easy version and hard version is the maximum number of queries allowed. In this version, it is 33.

There is a secret array a
 of length 2n+1
, whose elements are integers from 1
 to n
. Each value appears exactly twice, except for one value, which appears exactly three times.

Your goal is to find the three positions of the value that appears three times.

To do this, you may ask the following query at most 33 times:

Choose an integer k
 and an array s
 of k
 distinct indices between 1
 and 2n+1
.
You will receive the number of different values among as1,as2,…,ask
 that appear exactly once, or, in other words, the count of values that are not repeated.
For example, if the values as1,…,ask
 are {2,1,2,3,2,3,6,7}
, the answer to the query will be 3, as 1, 6, 7 are the only values that appear exactly once. 3 appears 2 times and 2 appears 3 times, which is more than once, so they are not counted.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤500
). The description of the test cases follows.

The first line of each test case contains a single integer n
 (2≤n≤1000
).

The array a
 is fixed for the test case and does not change during the interaction. In other words, the interactor is not adaptive.

It is guaranteed that the sum of n
 over all test cases does not exceed 2⋅104
.

Interaction
For each test case, first read a single integer n
.

You may ask up to 33
 queries in each test case.

To ask a query, print a line in the format:

? k
 s1
 s2
 …
 sk
 (si≠sj
 for i≠j
, 1≤si≤2⋅n+1
)
As a response to the query, you will receive the number of different values among as1,as2,…,ask
 that appear exactly once, or in other words, the count of values that are not repeated.

If your program makes more than 33
 queries for one test case, or makes an invalid query, then the response to the query will be −1
. After receiving such a response, your program should immediately terminate to receive the verdict Wrong Answer. Otherwise, it may receive any other verdict.

When you determine the answer for the current test case, print


! x
 y
 z
where x,y,z
 are the distinct three indices of the value that appears three times in a
. You can print indices in any order.

Note that this output does not count towards the query limit of 33
.

After that, proceed to the next test case or terminate your program if there are no more test cases.

After printing each query, do not forget to output the end of line and flush* the output. Otherwise, you will get the Idleness limit exceeded verdict.

If, at any interaction step, you read −1
 instead of valid data, your solution must exit immediately. This means that your solution will receive Wrong Answer because of an invalid query or any other mistake. Failing to exit can result in an arbitrary verdict because your solution will continue to read from a closed stream.

Note that the interactor is not adaptive, which means that a
 is unchanged throughout the interaction.

Hacks

To make a hack, use the following format.

The first line should contain a single integer t
 (1≤t≤500)
, the number of test cases.

The first line of each test case should contain n
 (2≤n≤2000)
.

The second line of each test case should contain an array of length 2⋅n+1
, the array a
, which should fulfill the constraints of the problem.

The sum of n
 over all test cases should not exceed 2⋅104
.

Example
Input
1
2

0

2

2

0

1
Output


? 2 1 2

? 2 1 4

? 2 1 5

? 5 1 2 3 4 5

? 4 1 2 3 4

! 1 2 3
Note
The secret array is a=[1,1,1,2,2]
.

In the first query, we ask for the number of values that appear exactly once in [a1,a2]=[1,1]
, since value 1 is repeated, the answer is 0.

In the second query, we ask for the number of values that appear exactly once in [a1,a4]=[1,2]
, since values 1 and 2 appear exactly once, the answer is 2.

In the fourth query, we ask for the number of values that appear exactly once in [a1,a2,a3,a4,a5]=[1,1,1,2,2]
, since values 1 and 2 are repeated, the answer is 0.

At the end, we print that the indices of the value repeated three times are 1, 2 and 3.

*/