#include <iostream>

size_t swapBits(size_t n) {
    auto evenBits = n & 0xAAAAAAAA;
    auto oddBits = n & 0x55555555;

    evenBits >>= 1;
    oddBits <<= 1;

    return evenBits | oddBits;
}

int main() {
    size_t n = 23;

    std::cout << swapBits(n) << std::endl;

    return 0;
}
