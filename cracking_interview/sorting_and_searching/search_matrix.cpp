#include <iostream>
#include <vector>

using namespace std;

bool searchMatrixRecursive(vector<vector<int>>& matrix, int target, pair<int, int> upperPoint, pair<int, int> lowerPoint) {
    if (upperPoint.first < lowerPoint.first && upperPoint.second < lowerPoint.second) {
        auto medPoint = make_pair((upperPoint.first + lowerPoint.first) / 2, (upperPoint.second + lowerPoint.second) / 2);
        auto medValue = matrix[medPoint.first][medPoint.second];

        auto medLeftPoint = make_pair(medPoint.first, upperPoint.second);
        auto medBottomPoint = make_pair(lowerPoint.first, medPoint.second);
        auto medRightPoint = make_pair(medPoint.first, lowerPoint.second);
        auto medUpperPoint = make_pair(upperPoint.first, medPoint.second);

        if (medValue == target) {
            cout << 1 << endl;
            return true;
        } else if (medValue < target) {
            cout << 2 << endl;
            return searchMatrixRecursive(matrix, target, medUpperPoint, medRightPoint);
        } else {
            cout << 3 << endl;
            return searchMatrixRecursive(matrix, target, upperPoint, medPoint) |
                searchMatrixRecursive(matrix, target, medUpperPoint, medLeftPoint) |
                searchMatrixRecursive(matrix, target, medLeftPoint, medBottomPoint);
        }
    }

    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
        return false;
    }

    int n = matrix.size();
    int m = matrix.front().size();

    int row = 0;
    int col = m - 1;

    while (row < n && col >= 0) {
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] < target) {
            ++row;
        } else {
            --col;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix{
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    cout << searchMatrix(matrix, 1) << endl;

    return 0;
}
