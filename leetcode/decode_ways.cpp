class Solution {
private:
    int numDecodingsRecursive(const string &s, unordered_map<size_t, int>& memorization, size_t idx) {
        if (idx < s.length() && s[idx] == '0') {
            return 0;
        }

        if (idx >= s.length() - 1) {
            return 1;
        }

        auto found = memorization.find(idx);
        if (found != memorization.end()) {
            return found->second;
        }

        int numDecodings = numDecodingsRecursive(s, memorization, idx + 1);
        if ((s[idx] - '0') * 10 + (s[idx + 1] - '0') <= 26) {
            numDecodings += numDecodingsRecursive(s, memorization, idx + 2);
        }

        memorization[idx] = numDecodings;

        return numDecodings;
    }

    int numDecodingsDP(const string &s) {
        vector<int> dp(s.length() + 1);

        if (s[0] == '0') {
            return 0;
        }

        dp[0] = 1;
        dp[1] = 1;

        for (size_t i = 2; i < dp.size(); ++i) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }

            int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');

            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[s.length()];

    }
public:
    int numDecodings(string s) {
        return numDecodingsDP(s);
    }
};
