#!/usr/bin/env python

class Solution(object):
    def uniquePaths(self, m, n):
        dp = [[0] * m for x in range(n)]
        dp[0][0] = 1

        for i in range(n):
            for j in range(m):
                if (i + 1 < n):
                    dp[i + 1][j] += dp[i][j]

                if (j + 1 < m):
                    dp[i][j + 1] += dp[i][j]

        return dp[n - 1][m - 1]

print Solution().uniquePaths(38, 6)
