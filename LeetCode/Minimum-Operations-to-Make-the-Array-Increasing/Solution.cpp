1class Solution {
2public:
3    int minOperations(vector<int>& nums) {
4        int ops = 0;
5        
6        for (int i = 1; i < nums.size(); i++) {
7            if (nums[i] <= nums[i - 1]) {
8                int needed = nums[i - 1] + 1;
9                ops += needed - nums[i];
10                nums[i] = needed;
11            }
12        }
13        
14        return ops;
15    }
16};