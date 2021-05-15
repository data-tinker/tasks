class Solution {
private:
    int countDistinctWays(int steps, int target, vector<int>& memo) {
        if (steps > target) {
            return 0;
        }

        if (steps == target) {
            return 1;
        }

        if (memo[steps] > 0) {
            return memo[steps];
        }

        memo[steps] = countDistinctWays(steps + 1, target, memo) + countDistinctWays(steps + 2, target, memo);

        return memo[steps];
    }

public:
    int climbStairs(int n) {
        vector<int> memo(n + 1);

        return countDistinctWays(0, n, memo);
    }
};
