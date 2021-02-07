class Solution {
private:
    bool checkDiagonal(vector<vector<int>>& matrix, int i, int j, int m, int n) {
        int value = matrix[i][j];
        while (i < m && j < n) {
            if (matrix[i][j] != value) {
                return false;
            }
            ++i;
            ++j;
        }

        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool result = true;

        for (int i = 0; i < m; ++i) {
            result &= checkDiagonal(matrix, i, 0, m, n);
        }

        for (int i = 0; i < n; ++i) {
            result &= checkDiagonal(matrix, 0, i, m, n);
        }

        return result;
    }
};
