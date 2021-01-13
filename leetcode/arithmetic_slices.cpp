class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        int currentCount = 1;
        int currentStep = numeric_limits<int>::max();

        int numberOfSlices = 0;

        for (size_t i = 0; i < A.size() - 1; ++i) {
            if (A[i + 1] - A[i] != currentStep) {
                currentCount = 2;
                currentStep = A[i + 1] - A[i];
            } else {
                ++currentCount;

                if (currentCount >= 3) {
                    numberOfSlices += currentCount - 2;
                }
            }
        }

        return numberOfSlices;
    }
};
