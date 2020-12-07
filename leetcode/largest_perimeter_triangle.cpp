class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(begin(A), end(A));

        for (int i = A.size() - 1; i > 1; --i) {
            if (A[i] < A[i - 1] + A[i - 2]) {
                return A[i] + A[i - 1] + A[i - 2];
            }
        }

        return 0;
    }
};
