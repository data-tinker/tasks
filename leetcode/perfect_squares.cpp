class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        int base = 2;
        int square;

        while (true) {
            square = base * base;
            if (square > n) {
                break;
            }
            squares.push_back(square);
            ++base;
        }

        vector<int> dp(n);
        dp[0] = 1;

        for (size_t i = 1; i < n; ++i) {
            int bestScore = dp[i - 1] + 1;

            for (size_t j = 0; j < squares.size(); ++j) {
                if (squares[j] > i + 1) {
                    break;
                } else if (squares[j] == i + 1) {
                    bestScore = 1;
                    break;
                }

                bestScore = min(bestScore, dp[i - squares[j]] + 1);
            }

            dp[i] = bestScore;
        }

        return dp[n - 1];
    }
};
