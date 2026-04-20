1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    int maxDistance(vector<int>& colors) {
7        int n = colors.size();
8        int ans = 0;
9
10        // compare with first element
11        for (int i = n - 1; i >= 0; i--) {
12            if (colors[i] != colors[0]) {
13                ans = max(ans, i - 0);
14                break;
15            }
16        }
17
18        // compare with last element
19        for (int i = 0; i < n; i++) {
20            if (colors[i] != colors[n - 1]) {
21                ans = max(ans, (n - 1) - i);
22                break;
23            }
24        }
25
26        return ans;
27    }
28};