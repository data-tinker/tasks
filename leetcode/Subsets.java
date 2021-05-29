class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList();

        for (int i = 0; i < 1 << nums.length; ++i) {
            List<Integer> subset = new ArrayList();
            int mask = 1;
            for (int j = 0; j < nums.length; ++j) {
                if ((i & mask) != 0) {
                    subset.add(nums[j]);
                }

                mask <<= 1;
            }

            result.add(subset);
        }

        return result;
    }
}
