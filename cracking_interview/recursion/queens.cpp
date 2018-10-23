#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool check(int row, vector<int> columnToRow) {
    for (int i = 0; i < row; ++i) {
        if (columnToRow[i] == columnToRow[row] || abs(columnToRow[i] - columnToRow[row]) == abs(i - row)) {
            return false;
        }
    }

    return true;
}

void solveNQueensDfs(vector<int> columnToRow, vector<vector<string>>& result, int currentRow, int n) {
    if (currentRow == n) {
        result.emplace_back(n, string(n, '.'));

        for (size_t i = 0; i < columnToRow.size(); ++i) {
            result.back()[i][columnToRow[i]] = 'Q';
        }

        return;
    }

    for (size_t i = 0; i < n; ++i) {
        columnToRow[currentRow] = i;
        if (check(currentRow, columnToRow)) {
            solveNQueensDfs(columnToRow, result, currentRow + 1, n);
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<int> columnToRow(n);
    vector<vector<string>> result;

    solveNQueensDfs(columnToRow, result, 0, n);

    return result;
}

int main() {
    auto placement = solveNQueens(4);

    for (const auto& matrix: placement) {
        for (const auto& row: matrix) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
