class Solution {
private:
    int dfs(int y, int x, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
        if (memo[y][x] > 0) {
            return memo[y][x];
        }

        memo[y][x] = 1;

        if (y < matrix.size() - 1 && matrix[y][x] < matrix[y + 1][x]) {
            memo[y][x] = max(memo[y][x], 1 + dfs(y + 1, x, matrix, memo));
        }

        if (y > 0 && matrix[y][x] < matrix[y - 1][x]) {
            memo[y][x] = max(memo[y][x], 1 + dfs(y - 1, x, matrix, memo));
        }

        if (x < matrix[0].size() - 1 && matrix[y][x] < matrix[y][x + 1]) {
            memo[y][x] = max(memo[y][x], 1 + dfs(y, x + 1, matrix, memo));
        }

        if (x > 0 && matrix[y][x] < matrix[y][x - 1]) {
            memo[y][x] = max(memo[y][x], 1 + dfs(y, x - 1, matrix, memo));
        }

        return memo[y][x];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> memo(matrix.size(), vector<int>(matrix[0].size()));
        int result = 0;

        for (size_t y = 0; y < matrix.size(); ++y) {
            for (size_t x = 0; x < matrix[0].size(); ++x) {
                result = max(result, dfs(y, x, matrix, memo));
            }
        }

        return result;
    }
};
