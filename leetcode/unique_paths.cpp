#include <iostream>
#include <vector>

int uniquePathsDP(int m, int n) {
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
    dp[0][0] = 1;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (i + 1 < n) {
                dp[i + 1][j] += dp[i][j];
            }

            if (j + 1 < m) {
                dp[i][j + 1] +=  dp[i][j];
            }
        }
    }

    return dp[n - 1][m - 1];
}

int uniquePathsMath(int m, int n) {
    int stepsSum = n + m - 2;
    int stepsDown = m - 1;

    int paths = 1;

    for (size_t i = 1; i <= stepsDown; ++i) {
        paths = paths * (stepsSum - stepsDown + i) / i;
    }

    return paths;
}

int dfs(std::vector<std::vector<int>>& obstacleGrid, size_t x, size_t y) {
    size_t n = obstacleGrid.size();
    size_t m = obstacleGrid.front().size();

    if (x > m - 1 || x < 0 || y > n - 1 || y < 0 || obstacleGrid[y][x] == 1) {
        return 0;
    }

    if (x == m - 1 && y == n - 1) {
        return 1;
    }

    return dfs(obstacleGrid, x + 1, y) + dfs(obstacleGrid, x, y + 1);
}

int uniquePathsWithObstaclesDFS(std::vector<std::vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty()) {
        return 0;
    }

    return dfs(obstacleGrid, 0, 0);
}

int uniquePathsWithObstaclesDP(std::vector<std::vector<int>>& obstacleGrid) {
    if (obstacleGrid.empty()) {
        return 0;
    }

    int n = obstacleGrid.size(), m = obstacleGrid.front().size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

    dp[0][0] = obstacleGrid[0][0] ? 0 : 1;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (i + 1 < n && obstacleGrid[i + 1][j] == 0) {
                dp[i + 1][j] += dp[i][j];
            }

            if (j + 1 < m && obstacleGrid[i][j + 1] == 0) {
                dp[i][j + 1] +=  dp[i][j];
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    std::vector<std::vector<int>> obstacleGrid = {
        {{0,0,0},{0,1,0},{0,0,0}},
    };

    std::cout << uniquePathsWithObstaclesDP(obstacleGrid) << std::endl;

    std::cout << uniquePathsMath(38, 6) << std::endl;

    return 0;
}
