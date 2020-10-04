import java.util.*;

class MoveZeroes {
    public static void moveZeroes(int[] nums) {
        int idx = 0;

        for (int n : nums) {
            if (n != 0) {
                nums[idx] = n;
                ++idx;
            }
        }

        for (int i = idx; i < nums.length; ++i) {
            nums[i] = 0;
        }
    }

    public static void main(String[] args) {
        int[] nums = new int[]{1, 0, 1};
        moveZeroes(nums);
        System.out.println(Arrays.toString(nums));
    }
}
