class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int[][] memo = new int[matrix.length][matrix.length];

        for (int[] row: memo) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        int result = Integer.MAX_VALUE;
        for (int i = 0; i < matrix.length; ++i) {
            result = Math.min(result,helper(matrix, memo, 0, i));
        }

        for (int[] arr : memo) {
            System.out.println(Arrays.toString(arr));
        }

        return result;
    }

    private int helper(int[][] matrix, int[][] memo, int y, int x) {
        if (memo[y][x] != Integer.MAX_VALUE) {
            return memo[y][x];
        }

        int result = matrix[y][x];
        int bestPath = 0;

        if (y + 1 < matrix.length) {
            bestPath = helper(matrix, memo, y + 1, x);

            if (x + 1 < matrix.length) {
                bestPath = Math.min(bestPath, helper(matrix, memo, y + 1, x + 1));
            }

            if (x - 1 >= 0) {
                bestPath = Math.min(bestPath, helper(matrix, memo, y + 1, x - 1));
            }
        }

        memo[y][x] = result + bestPath;

        return memo[y][x];
    }
}
