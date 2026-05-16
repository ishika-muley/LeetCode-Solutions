1class Solution {
2public:
3    int findMin(vector<int>& nums) {
4        int low = 0, high = nums.size() - 1;
5
6        while (low < high) {
7            int mid = low + (high - low) / 2;
8
9            if (nums[mid] > nums[high]) {
10                // Minimum is in right half
11                low = mid + 1;
12            }
13            else if (nums[mid] < nums[high]) {
14                // Minimum is in left half including mid
15                high = mid;
16            }
17            else {
18                // Duplicate case
19                high--;
20            }
21        }
22
23        return nums[low];
24    }
25};