#include <iostream>
#include <bitset>

int hammingDistance(int x, int y) {
    return std::bitset<32>(x ^ y).count();
}

int main() {
    std::cout << hammingDistance(31, 14) << std::endl;

    return 0;
}
