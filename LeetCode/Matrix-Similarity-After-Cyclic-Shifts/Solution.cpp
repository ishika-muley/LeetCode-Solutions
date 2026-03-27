1class Solution {
2public:
3    bool areSimilar(vector<vector<int>>& mat, int k) {
4        int m = mat.size(), n = mat[0].size();
5
6        for (int i = 0; i < m; i++) {
7            for (int j = 0; j < n; j++) {
8                int newIndex;
9
10                if (i % 2 == 0) {
11                    // left shift
12                    newIndex = (j + k) % n;
13                } else {
14                    // right shift
15                    newIndex = (j - k % n + n) % n;
16                }
17
18                if (mat[i][j] != mat[i][newIndex]) {
19                    return false;
20                }
21            }
22        }
23
24        return true;
25    }
26};