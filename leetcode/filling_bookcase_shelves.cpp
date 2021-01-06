class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp(books.size() + 1);
        dp[0] = 0;

        for (size_t i = 0; i < books.size(); ++i) {
            int width = books[i][0];
            int height = books[i][1];

            dp[i + 1] = dp[i] + height;

            for (int j = i - 1; j >= 0 && width + books[j][0] <= shelf_width; --j) {
                height = max(height, books[j][1]);
                width += books[j][0];

                dp[i + 1] = min(dp[i + 1], dp[j] + height);
            }
        }

        for (size_t i = 0; i < dp.size(); ++i) {
            cout << dp[i] << endl;
        }

        return dp[books.size()];
    }
};
