class Solution {
private:
    int dfs(vector<int>& balances, int idx) {
        if (idx == balances.size()) {
            return 0;
        }

        if (balances[idx] == 0) {
            return dfs(balances, idx + 1);
        }

        int minTransactions = numeric_limits<int>::max();
        for (size_t i = idx + 1; i < balances.size(); ++i) {
            if (balances[idx] * balances[i] < 0) {
                balances[i] += balances[idx];
                minTransactions = min(minTransactions, 1 + dfs(balances, idx + 1));
                balances[i] -= balances[idx];
            }
        }

        return minTransactions;
    }

    int minTransfersDFS(vector<vector<int>>& transactions) {
        unordered_map<int, int> personToBalance;

        for (const auto& tr : transactions) {
            personToBalance[tr[0]] -= tr[2];
            personToBalance[tr[1]] += tr[2];
        }

        vector<int> balances;

        for (const auto& pair : personToBalance) {
            if (pair.second != 0) {
                balances.push_back(pair.second);
            }
        }

        return dfs(balances, 0);
    }

    int minTransfersDP(vector<vector<int>>& transactions) {
        unordered_map<int, int> personToBalance;

        for (const auto& tr : transactions) {
            personToBalance[tr[0]] -= tr[2];
            personToBalance[tr[1]] += tr[2];
        }

        vector<int> balances;

        for (const auto& pair : personToBalance) {
            if (pair.second != 0) {
                balances.push_back(pair.second);
            }
        }

        int n = balances.size();
        vector<int> dp(pow(2, n));
        vector<int> sums(pow(2, n));

        for (int mask = 0; mask < pow(2, n); ++mask) {
            int setBit = 1;

            for (int b = 0; b < n; ++b) {
                if ((mask & setBit) == 0) {
                    int next = mask | setBit;
                    sums[next] = sums[mask] + balances[b];
                    if (sums[next] == 0) {
                        dp[next] = max(dp[next], dp[mask] + 1);
                    } else {
                        dp[next] = max(dp[next], dp[mask]);
                    }
                }

                setBit <<= 1;
            }
        }

        return n - dp.back();
    }
public:
    int minTransfers(vector<vector<int>>& transactions) {
        return minTransfersDP(transactions);
    }
};
