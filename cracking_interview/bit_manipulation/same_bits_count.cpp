#include <iostream>

bool getBit(const size_t n, const size_t idx) {
    return n & (1ull << idx);
}

void setBit(size_t& number, const size_t idx) {
    number |= (1ull << idx);
}

void unsetBit(size_t& number, const size_t idx) {
    number &= ~(1ull << idx);
}

size_t getLowestNext(size_t number) {
    size_t idx = 0;

    while (idx < 63 && (!getBit(number, idx) || getBit(number, idx + 1))) {
        ++idx;
    }

    if (idx == 63) {
        return number;
    }

    setBit(number, idx + 1);
    unsetBit(number, idx);

    int onesCount = 0;

    for (size_t i = 0; i < idx; ++i) {
        if (getBit(number, i)) {
            ++onesCount;
        }
    }

    for (size_t i = 0; i < idx; ++i) {
        if (onesCount-- > 0) {
            setBit(number, i);
        } else {
            unsetBit(number, i);
        }
    }

    return number;
}

size_t getGreatestPrev(size_t number) {
    return ~getLowestNext(~number);
}

int main() {
    size_t number = 23;

    std::cout << getGreatestPrev(number) << ' ' <<getLowestNext(number) << std::endl;

    return 0;
}
