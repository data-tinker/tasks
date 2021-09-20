class Solution {
    public int[] sumZero(int n) {
        int[] result = new int[n];
        for (int i = 0; i < n / 2; ++i) {
            result[i] = - n / 2 + i;
            result[n - i - 1] = n / 2 - i;
        }

        return result;
    }
}
