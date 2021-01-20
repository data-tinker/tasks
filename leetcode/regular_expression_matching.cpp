class Solution {
private:
    bool isMatchHelperTopDown(const string& s, const string& p, vector<vector<int>>& memo, size_t sP, size_t pP) {
        if (memo[sP][pP] != -1) {
            return memo[sP][pP];
        }

        bool ans;
        if (pP == p.length()) {
            ans = (sP == s.length());
            memo[sP][pP] = ans;
            return ans;
        }

        bool match;

        if (sP < s.length() && (s[sP] == p[pP] || p[pP] == '.')) {
            match = true;
        } else {
            match = false;
        }

        if (pP < p.length() - 1 && p[pP + 1] == '*') {
            ans = isMatchHelperTopDown(s, p, memo, sP, pP + 2) || (match && isMatchHelperTopDown(s, p, memo, sP + 1, pP));
        } else {
            ans = match && isMatchHelperTopDown(s, p, memo, sP + 1, pP + 1);
        }

        memo[sP][pP] = ans;
        return ans;
    }

    bool isMatchTopDown(const string& s, const string& p) {
        vector<vector<int>> memo(s.length() + 1, vector<int>(p.length() + 1, -1));
        return isMatchHelperTopDown(s, p, memo, 0, 0);
    }

    bool isMathBottomUp(const string& s, const string& p) {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1));
        dp[s.length()][p.length()] = true;

        for (int i = s.length(); i >= 0; --i) {
            for (int j = p.length() - 1; j >= 0; --j) {
                bool match;

                if (i < s.length() && (s[i] == p[j] || p[j] == '.')) {
                    match = true;
                } else {
                    match = false;
                }

                if (j < p.length() - 1 && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || match && dp[i + 1][j];
                } else {
                    dp[i][j] = match && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];
    }
public:
    bool isMatch(string s, string p) {
        return isMathBottomUp(s, p);
    }
};
