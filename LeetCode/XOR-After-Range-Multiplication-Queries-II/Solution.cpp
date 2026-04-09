1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    const int MOD = 1e9 + 7;
7
8    long long power(long long a, long long b) {
9        long long res = 1;
10        while (b) {
11            if (b & 1) res = (res * a) % MOD;
12            a = (a * a) % MOD;
13            b >>= 1;
14        }
15        return res;
16    }
17
18    long long inv(long long x) {
19        return power(x, MOD - 2);
20    }
21
22    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
23        int n = nums.size();
24        int B = sqrt(n) + 1;
25
26        vector<long long> mul(n, 1);
27
28        // group by k
29        unordered_map<int, vector<vector<int>>> mp;
30        for (auto &q : queries) {
31            mp[q[2]].push_back(q);
32        }
33
34        for (auto &[k, qs] : mp) {
35            if (k >= B) {
36                // large k → direct
37                for (auto &q : qs) {
38                    int l = q[0], r = q[1], v = q[3];
39                    for (int i = l; i <= r; i += k) {
40                        mul[i] = (mul[i] * v) % MOD;
41                    }
42                }
43            } else {
44                // small k → optimize
45                vector<vector<long long>> pref(k);
46
47                for (int r = 0; r < k; r++) {
48                    int size = (n - r + k - 1) / k;
49                    pref[r].assign(size + 1, 1);
50                }
51
52                for (auto &q : qs) {
53                    int l = q[0], r = q[1], v = q[3];
54                    int rem = l % k;
55
56                    int start = (l - rem) / k;
57                    int end = (r - rem) / k;
58
59                    pref[rem][start] = (pref[rem][start] * v) % MOD;
60                    if (end + 1 < pref[rem].size()) {
61                        pref[rem][end + 1] = (pref[rem][end + 1] * inv(v)) % MOD;
62                    }
63                }
64
65                // apply prefix
66                for (int rem = 0; rem < k; rem++) {
67                    long long cur = 1;
68                    for (int j = 0; j < pref[rem].size(); j++) {
69                        cur = (cur * pref[rem][j]) % MOD;
70                        int idx = rem + j * k;
71                        if (idx < n) {
72                            mul[idx] = (mul[idx] * cur) % MOD;
73                        }
74                    }
75                }
76            }
77        }
78
79        int ans = 0;
80        for (int i = 0; i < n; i++) {
81            long long val = (nums[i] * mul[i]) % MOD;
82            ans ^= (int)val;
83        }
84
85        return ans;
86    }
87};