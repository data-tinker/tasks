class Solution {
    private int numSubarraysWithSumHash(int[] nums, int goal) {
        int currentSum = 0;
        int result = 0;
        Map<Integer, Integer> prefixSumToCount = new HashMap<Integer, Integer>();
        prefixSumToCount.put(0, 1);

        for (int i = 0; i < nums.length; ++i) {
            currentSum += nums[i];

            result += prefixSumToCount.getOrDefault(currentSum - goal, 0);

            prefixSumToCount.put(currentSum, prefixSumToCount.getOrDefault(currentSum, 0) + 1);
        }

        return result;
    }

    private int numSubarraysWithSumWindow(int[] nums, int goal) {
        int lLow = 0;
        int lHigh = 0;

        int sumLow = 0;
        int sumHigh = 0;

        int result = 0;

        for (int r = 0; r < nums.length; ++r) {
            sumLow += nums[r];
            while (lLow < r && sumLow > goal) {
                sumLow -= nums[lLow++];
            }

            sumHigh += nums[r];
            while (lHigh < r && (sumHigh > goal || sumHigh == goal && nums[lHigh] == 0)) {
                sumHigh -= nums[lHigh++];
            }

            if (sumLow == goal) {
                result += lHigh - lLow + 1;
            }
        }

        return result;
    }

    public int numSubarraysWithSum(int[] nums, int goal) {
        return numSubarraysWithSumWindow(nums, goal);
    }
}
