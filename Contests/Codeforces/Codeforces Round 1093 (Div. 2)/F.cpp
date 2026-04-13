/*
Coloring a Red Black Tree
time limit per test2 seconds
memory limit per test256 megabytes

You are given a tree of n
 nodes numbered from 1 to n
 and a binary string s
 of length n
 where si=1
 means that the i
-th node is colored red and si=0
 means that the i
-th node is colored black. You are allowed to perform the following operation:

Select a node a
 (1≤a≤n
).
A neighbor b
 of a
 is selected uniformly at random.
Recolor node a
 with the color of b
. Note that this changes the color of the vertex you selected, not the one that was uniformly chosen.
You want to color all the nodes in the tree red by performing the operation any number of times (possibly zero). Please compute the minimum expected number of operations needed to do so if you perform them optimally. There will be at least one red node initially.

Input
Each test contains multiple test cases. The first line contains the number of test cases t
 (1≤t≤1000
). The description of the test cases follows.

The first line of each test case contains an integer n
 (1≤n≤2⋅105
).

The second line contains a binary string s
 of size n
.

The following n−1
 lines each contain two integers, the i
-th of them contains ui
 and vi
 (1≤ui,vi≤n
), which means that there is an edge between nodes ui
 and vi
.

It is guaranteed that the given graph is a tree, there is at least one red node, and the sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single real number representing the minimum expected number of operations.

Your answer is considered correct if its absolute or relative error does not exceed 10−6
.

Formally, let your answer be x
, and the jury's answer be y
. Your answer is accepted if and only if |x−y|max(1,|y|)≤10−6
.

Example
Input
3
3
101
1 2
2 3
5
10010
1 2
2 3
3 4
2 5
3
010
1 2
2 3
Output
1.00000000000000000000
4.50000000000000000000
2.00000000000000000000
Note
In the first test case, there is only one node colored in black, which has only two red colored neighbors, thus, if we first apply the operation to the second node, we will have a red colored tree in just one operation.
*/