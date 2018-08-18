#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int> >;

int main() {
    size_t n;
    std::cin >> n;
    Matrix matrix(n, std::vector<int>(n));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    for (size_t i = 0; i < n / 2; ++i) {
        for (size_t j = i; j < n - 1 - i; ++j) {
            std::swap(matrix[i][j], matrix[j][n - i - 1]);
            std::swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
            std::swap(matrix[i][j], matrix[n - j - 1][i]);
        }
    }

    for (const auto &row: matrix) {
        for (const auto &cell: row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
