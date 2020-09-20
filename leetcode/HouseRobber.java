public class HouseRobber {
    public int rob(int[] nums) {
        int result = 0;
        int[] dp = new int [nums.length + 3];

        for (int i = 0; i < nums.length; ++i) {
            dp[i + 3] = Math.max(dp[i + 1] + nums[i], dp[i] + nums[i]);
            result = Math.max(dp[i + 3], result);
        }

        return result;
    }

    public static void main(String[] args) {
        HouseRobber hr = new HouseRobber();
        System.out.println(hr.rob(new int[] {1, 2, 3, 1}));
    }
}
