class Solution {
private:
    int longestValidParenthesesStack(string s) {
        int maxLength = 0;
        stack<int> parenthesesIdx;
        parenthesesIdx.push(-1);

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                parenthesesIdx.push(i);
            } else {
                parenthesesIdx.pop();
                if (parenthesesIdx.empty()) {
                    parenthesesIdx.push(i);
                } else {
                    maxLength = max(maxLength, i - parenthesesIdx.top());
                }
            }
        }

        return maxLength;
    }

    int longestValidParenthesesDP(string s) {
        int maxLength = 0;
        vector<int> dp(s.length());
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    if (i >= 2) {
                        dp[i] = dp[i - 2] + 2;
                    } else {
                        dp[i] = 2;
                    }
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    if (i - dp[i - 1] >= 2) {
                        dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                    } else {
                        dp[i] = dp[i - 1] + 2;
                    }
                }
                maxLength = max(maxLength, dp[i]);
            }
        }

        return maxLength;
    }
public:
    int longestValidParentheses(string s) {
        return longestValidParenthesesDP(s);
    }
};
