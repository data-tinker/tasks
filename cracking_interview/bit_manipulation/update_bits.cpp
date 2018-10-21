#include <iostream>

void updateBits(int& n, const int m, const int i, const int j) {
    int mask = ((1 << (j - i + 1)) - 1) << i;
    n &= ~mask;
    n |= ((m << i) & mask);
}

int main() {
    int n, m, i, j;
    std::cin >> n >> m >> i >> j;

    updateBits(n, m, i, j);

    std::cout << n << std::endl;

    return 0;
}
