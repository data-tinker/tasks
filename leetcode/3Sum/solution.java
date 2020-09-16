import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums = {-1, 0, 1, 2, -1, -4};

        for (List<Integer> row: solution.threeSum(nums)){
            for (int val: row){
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();

        Arrays.sort(nums);

        for (int firstIdx = 0; firstIdx < nums.length - 2; ++firstIdx) {
            if (firstIdx > 0 && nums[firstIdx] == nums[firstIdx - 1]) {
                continue;
            }

            int secondIdx = firstIdx + 1;
            int thirdIdx = nums.length - 1;

            int requiredSum = 0 - nums[firstIdx];

            while (secondIdx < thirdIdx) {
                int currentSum = nums[secondIdx] + nums[thirdIdx];

                if (currentSum < requiredSum) {
                    ++secondIdx;
                } else if (currentSum > requiredSum) {
                    --thirdIdx;
                } else {
                    result.add(List.of(nums[firstIdx], nums[secondIdx], nums[thirdIdx]));
                    ++secondIdx;
                    while (secondIdx < thirdIdx && nums[secondIdx] == nums[secondIdx - 1]) {
                        ++secondIdx;
                    }
                }
            }
        }

        return result;
    }
}
