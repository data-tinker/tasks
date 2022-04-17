class Solution {
    public int countSquares(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] dp = new int[matrix.length][matrix[0].length];

        int answer = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j] = matrix[i][j] == 0 ? 0 : computeForCell(dp, i, j) + 1;
                answer += dp[i][j];
            }
        }

        return answer;
    }

    private int computeForCell(int[][] dp, int i, int j) {
        List<Integer> nbValues = new ArrayList<>();

        if (i == 0 || j == 0) {
            return 0;
        }

        if (i > 0) {
            nbValues.add(dp[i - 1][j]);
        }
        if (j > 0) {
            nbValues.add(dp[i][j - 1]);
        }
        if (i > 0 && j > 0) {
            nbValues.add(dp[i - 1][j - 1]);
        }

        if (nbValues.size() == 0) {
            return 0;
        }

        return Collections.min(nbValues);
    }
}
