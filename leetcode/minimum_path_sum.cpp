class Solution {
public:
    int computeNeighboursSum(const vector<vector<int>>& dp, int i, int j) {
        if (i > 0 && j > 0) {
            return min(dp[i - 1][j], dp[i][j - 1]);
        } else if (i > 0) {
            return dp[i - 1][j];
        } else if (j > 0) {
            return dp[i][j - 1];
        }

        return 0;
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        pair<int, int> neigbourValues;

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                dp[i][j] = grid[i][j] + computeNeighboursSum(dp, i, j);
            }
        }

        return dp[m - 1][n - 1];
    }
};
