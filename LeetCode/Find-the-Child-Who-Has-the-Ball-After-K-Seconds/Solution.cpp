1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    int numberOfChild(int n, int k) {
7        int cycle = 2 * (n - 1);
8        k = k % cycle;
9
10        if (k < n) return k;
11        else return cycle - k;
12    }
13};