#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (auto coin: coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[amount] == amount + 1) {
        return -1;
    }

    return dp[amount];
}

int main() {
    vector<int> coins{1};
    cout << coinChange(coins, 0) << endl;

    return 0;
}
