1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
7        const int MOD = 1e9 + 7;
8
9        for (auto &q : queries) {
10            int l = q[0], r = q[1], k = q[2], v = q[3];
11
12            for (int i = l; i <= r; i += k) {
13                nums[i] = (1LL * nums[i] * v) % MOD;
14            }
15        }
16
17        int ans = 0;
18        for (int x : nums) {
19            ans ^= x;
20        }
21
22        return ans;
23    }
24};