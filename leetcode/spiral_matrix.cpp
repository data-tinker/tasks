class Solution {
    void fillLayer(const vector<vector<int>>& matrix, vector<int>& order, pair<int, int>& startPoint, pair<int, int>& endPoint) {
        for (size_t i = startPoint.second; i <= endPoint.second; ++i) {
            order.push_back(matrix[startPoint.first][i]);
        }

        for (size_t i = startPoint.first + 1; i <= endPoint.first; ++i) {
            order.push_back(matrix[i][endPoint.second]);
        }

        if (startPoint.first < endPoint.first && startPoint.second < endPoint.second) {
            for (size_t i = endPoint.second - 1; i > startPoint.second; --i) {
                order.push_back(matrix[endPoint.first][i]);
            }

            for (size_t i = endPoint.first; i > startPoint.first; --i) {
                order.push_back(matrix[i][startPoint.second]);
            }
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        auto startPoint = make_pair(0, 0);
        auto endPoint = make_pair(m - 1, n - 1);

        vector<int> order;

        int mLimit = m;
        int nLimit = n;

        while (startPoint.first <= endPoint.first && startPoint.second <= endPoint.second) {
            fillLayer(matrix, order, startPoint, endPoint);
            ++startPoint.first;
            ++startPoint.second;
            --endPoint.first;
            --endPoint.second;
        }

        return order;
    }
};
