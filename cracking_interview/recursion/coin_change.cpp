#include <iostream>
#include <vector>

using namespace std;

int changeDfsHelper(int amount, vector<int>::const_iterator coin, const vector<int>& coins) {
    if (coin == coins.end()) {
        if (amount == 0) {
            return 1;
        }

        return 0;
    }

    int result = 0;

    for (size_t i = 0; i * *coin <= amount; ++i) {
        result += changeDfsHelper(amount - i * *coin, coin + 1, coins);
    }

    return result;
}

int changeDfs(int amount, const vector<int>& coins) {
    return changeDfsHelper(amount, coins.cbegin(), coins);
}

int changeDP(int amount, const vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (auto coin: coins) {
        for (size_t j = 1; j <= amount; ++j) {
            if (j >= coin) {
                dp[j] += dp[j - coin];
            }
        }
    }

    return dp[amount];
}

int main() {
    vector<int> coins{1,2,3};

    cout << changeDP(50, coins) << endl;

    return 0;
}
