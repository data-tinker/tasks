class Solution {
private:
    int changeHelper(int amount, const vector<int>& coins, vector<vector<int>>& memo, size_t idx) {
        if (amount < 0) {
            return 0;
        } else if (amount  == 0) {
            return 1;
        }

        if (idx > coins.size() - 1) {
            return 0;
        }

        if (memo[idx][amount] == -1) {
            memo[idx][amount] = changeHelper(amount, coins, memo, idx + 1) + changeHelper(amount - coins[idx], coins, memo, idx);
        }

        return memo[idx][amount];
    }

    int changeRecursionWithMemo(int amount, vector<int>& coins) {
        if (coins.empty()) {
            if (amount == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        vector<vector<int>> memo(coins.size(), vector<int>(amount +  1, -1));
        return changeHelper(amount, coins, memo, 0);
    }

    int changeDP(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (const auto coin : coins) {
            for (size_t j = coin; j < amount + 1; ++j) {
                dp[j] += dp[j - coin];
            }
        }

        return dp[amount];
    }
public:
    int change(int amount, vector<int>& coins) {
        return changeDP(amount, coins);
    }
};
