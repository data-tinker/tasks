class Solution {
    public boolean isMonotonic(int[] nums) {
        boolean monotoneIncreasing = true;
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                monotoneIncreasing = false;
            }
        }

        boolean monotoneDecreasing = true;
        for (int i = nums.length - 1; i > 0; --i) {
            if (nums[i] > nums[i - 1]) {
                monotoneDecreasing = false;
            }
        }

        return monotoneIncreasing || monotoneDecreasing;
    }
}
