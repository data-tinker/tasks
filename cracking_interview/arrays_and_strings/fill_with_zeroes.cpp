#include <iostream>
#include <vector>

int main() {
    size_t n, m;
    int data;

    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    std::vector<bool> rows(n, false);
    std::vector<bool> columns(m, false);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> data;

            if (data == 0) {
                rows[i] = true;
                columns[j] = true;
            }

            matrix[i][j] = data;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (rows[i] || columns[j]) {
                matrix[i][j] = 0;
            }
        }
    }
    
    for (const auto& row: matrix) {
        for (const auto& value: row) {
            std::cout << value << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
