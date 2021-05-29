class Solution {
    public int hammingDistance(int x, int y) {
        int dist = 0;
        int n = x ^ y;

        while (n > 0) {
            ++dist;
            n &= n - 1;
        }

        return dist;
    }
}
