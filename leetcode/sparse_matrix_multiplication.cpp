class Solution {
private:
    vector<vector<int>> multiplySlow(vector<vector<int>>& A, vector<vector<int>>& B) {
        size_t m = A.size();
        size_t n = A[0].size();
        size_t p = B[0].size();

        vector<vector<int>> AB(m, vector<int>(p));

        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < p; ++j) {
                for (size_t k = 0; k < n; ++k) {
                    AB[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return AB;
    }

    vector<vector<int>> multiplyFast(vector<vector<int>>& A, vector<vector<int>>& B) {
        size_t m = A.size();
        size_t n = A[0].size();
        size_t p = B[0].size();

        vector<vector<int>> AB(m, vector<int>(p));

        for (size_t i = 0; i < m; ++i) {
            for (size_t k = 0; k < n; ++k) {
                if (A[i][k] != 0) {
                    for (size_t j = 0; j < p; ++j) {
                        AB[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }

        return AB;
    }

public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        return multiplyFast(A, B);
    }
};
