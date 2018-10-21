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

int dfs(std::vector<std::vector<int>>& obstacleGdrid, size_t x, size_t y) {
    size_t n = obstacleGdrid.size();
    size_t m = obstacleGdrid.front().size();

    if (x > m - 1 || x < 0 || y > n - 1 || y < 0 || obstacleGdrid[y][x] == 1) {
        return 0;
    }

    if (x == m - 1 && y == n - 1) {
        return 1;
    }

    return dfs(obstacleGdrid, x + 1, y) + dfs(obstacleGdrid, x, y + 1);
}

int uniquePathsWithObstaclesDFS(std::vector<std::vector<int>>& obstacleGdrid) {
    if (obstacleGdrid.empty()) {
        return 0;
    }

    return dfs(obstacleGdrid, 0, 0);
}

int uniquePathsWithObstaclesDP(std::vector<std::vector<int>>& obstacleGdrid) {
    if (obstacleGdrid.empty()) {
        return 0;
    }

    int n = obstacleGdrid.size(), m = obstacleGdrid.front().size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

    dp[0][0] = obstacleGdrid[0][0] ? 0 : 1;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (i + 1 < n && obstacleGdrid[i + 1][j] == 0) {
                dp[i + 1][j] += dp[i][j];
            }

            if (j + 1 < m && obstacleGdrid[i][j + 1] == 0) {
                dp[i][j + 1] +=  dp[i][j];
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    std::vector<std::vector<int>> obstacleGdrid = {
        {{0,0,0},{0,1,0},{0,0,0}},
    };

    std::cout << uniquePathsWithObstaclesDP(obstacleGdrid) << std::endl;

    return 0;
}
