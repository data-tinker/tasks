class Solution {
    public int[] shortestToChar(String s, char c) {
        int[] result = new int[s.length()];

        Arrays.fill(result, Integer.MAX_VALUE);

        int distance = Integer.MAX_VALUE;
        for (int i = 0; i < s.length(); ++i) {
            distance = updateResult(i, result, s.charAt(i), c, distance);
        }

        distance = Integer.MAX_VALUE;
        for (int i = s.length() - 1; i >= 0; --i) {
            distance = updateResult(i, result, s.charAt(i), c, distance);
        }

        return result;
    }

    private int updateResult(int idx, int[] result, char currentChar, char c, int distance) {
        if (currentChar == c) {
            distance = 0;
        } else if (distance != Integer.MAX_VALUE) {
            ++distance;
        }

        result[idx] = Math.min(result[idx], distance);

        return distance;
    }
}
