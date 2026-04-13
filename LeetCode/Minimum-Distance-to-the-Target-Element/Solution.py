class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        for (int step = 0; step < nums.length; step++){
            if (start+step < nums.length && nums[start+step] == target) return step;
            if (start-step >= 0 && nums[start-step] == target) return step;
        }
        return 0;
    }
}