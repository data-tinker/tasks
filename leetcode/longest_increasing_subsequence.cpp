class Solution {
private:
    int lengthOfLisDp(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(begin(dp), end(dp));
    }

    int lengthOfLisDpBinary(vector<int>& nums) {
        vector<int> dp;

        for (size_t i = 0; i < nums.size(); ++i) {
            auto it = lower_bound(begin(dp), end(dp), nums[i]);
            if (it == dp.end()) {
                dp.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }

        return dp.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return lengthOfLisDpBinary(nums);
    }
};
