class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (nums.size() == 0) {
            return 0;
        }

        multiset<int> window;
        int max_window = numeric_limits<int>::min();
        int l = 0;

        for (size_t r = 0; r < nums.size(); ++r) {
            window.insert(nums[r]);
            while (*window.rbegin() - *window.begin() > limit) {
                window.erase(window.find(nums[l++]));
            }
            max_window = max(max_window, static_cast<int>(window.size()));
        }

        return max_window;
    }
};
