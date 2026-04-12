1#include <bits/stdc++.h>
2using namespace std;
3
4class Solution {
5public:
6    int countPairs(vector<int>& nums, int target) {
7        sort(nums.begin(), nums.end());
8        
9        int left = 0, right = nums.size() - 1;
10        int count = 0;
11
12        while (left < right) {
13            if (nums[left] + nums[right] < target) {
14                count += (right - left); // all pairs valid
15                left++;
16            } else {
17                right--;
18            }
19        }
20
21        return count;
22    }
23};