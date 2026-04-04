1class Solution {
2public:
3    vector<int> getRow(int rowIndex) {
4        vector<int> row(rowIndex + 1, 0);
5        row[0] = 1;
6
7        for (int i = 1; i <= rowIndex; i++) {
8            for (int j = i; j >= 1; j--) {
9                row[j] = row[j] + row[j - 1];
10            }
11        }
12
13        return row;
14    }
15};