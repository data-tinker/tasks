class Solution {
    public int rob(int[] nums) {
        return robRecursive(nums);
    }

    private int robDP(int[] nums) {
        int housesLength = nums.length;
        int[] dp = new int[housesLength + 1];

        dp[housesLength] = 0;
        dp[housesLength - 1] = nums[housesLength - 1];

        for (int i = housesLength - 2; i >= 0; --i) {
            dp[i] = Math.max(dp[i + 1], nums[i] + dp[i + 2]);
        }

        return dp[0];
    }

    private int robRecursive(int[] nums) {
        int[] memo = new int[nums.length];
        Arrays.fill(memo, -1);

        return robRecursive(nums, nums.length - 1, memo);
    }

    private int robRecursive(int[] nums, int idx, int[] memo) {
        if (idx < 0) {
            return 0;
        } else if (idx == 0) {
            return nums[0];
        } else if (idx == 1) {
            return Math.max(nums[0], nums[1]);
        }

        if (memo[idx] == -1) {
            memo[idx] = Math.max(
              nums[idx] + robRecursive(nums, idx - 2, memo),
                robRecursive(nums, idx - 1, memo)
            );
        }

        return  memo[idx];
    }
}
