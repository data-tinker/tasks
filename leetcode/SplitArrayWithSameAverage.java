class Solution {
    class MapKey {
        public int idx;
        public int count;
        public int sum;

        public MapKey(int idx, int count, int sum) {
            this.idx = idx;
            this.count = count;
            this.sum = sum;
        }

        @Override
        public int hashCode() {
            return Objects.hash(idx, count, sum);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            } else if (!(obj instanceof MapKey)) {
                return false;
            } else {
                MapKey other = (MapKey) obj;
                return Objects.equals(idx, other.idx)
                    && Objects.equals(count, other.count)
                    && Objects.equals(sum, other.sum);
            }
        }
    }

    public boolean splitArraySameAverage(int[] nums) {
        int sum = Arrays.stream(nums).sum();

        Map<MapKey, Boolean> map = new HashMap<>();

        for(int count = 1; count < nums.length - 1; ++count){
            if((sum * count) % nums.length == 0){
                if(isPossible(nums, 0, count, (sum * count) / nums.length, map)) {
                    return true;
                }
            }
        }

        return false;
    }

    private boolean isPossible(int[] nums, int idx, int count, int remainingSum,  Map<MapKey, Boolean> map) {
        if (remainingSum == 0 && count == 0) {
            return true;
        }

        if (idx == nums.length || count == 0) {
            return false;
        }

        MapKey key = new MapKey(idx, count, remainingSum);

        if(map.containsKey(key)) {
            return map.get(key);
        }

        boolean ignoreCurrent = isPossible(nums, idx + 1, count, remainingSum, map);
        if (remainingSum - nums[idx] >= 0) {
            boolean useCurrent = isPossible(nums, idx + 1, count - 1, remainingSum - nums[idx], map);
            map.put(key, useCurrent || ignoreCurrent);
        } else {
             map.put(key, ignoreCurrent);
        }

        return map.get(key);
    }
}
