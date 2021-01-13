class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();

        for (size_t i = 0; i < k; ++i) {
            sum += cardPoints[i];
        }

        int bestSum = sum;

        for (size_t i = 0; i < k; ++i) {
            sum -= cardPoints[k - i - 1];
            sum += cardPoints[n - i - 1];

            bestSum = max(bestSum, sum);
        }

        return bestSum;
    }
};
