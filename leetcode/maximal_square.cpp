class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        size_t n = matrix.size();
        size_t m = matrix[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        int result = 0;

        for (size_t i = 1; i <= n; ++i) {
            for (size_t j = 1; j <= m; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }

        return result * result;
    }
};
