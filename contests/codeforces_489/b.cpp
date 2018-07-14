#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <cassert>
#include <fstream>
#include <array>

using namespace std;

#define endl '\n'

vector<long long> findAllDivisors(long long number) {
    vector<long long> result;
    auto currentNumber = number;

    for (size_t i = 2; i <= number; ++i) {
        long long currentDivisor = 1;

        while (currentNumber % i == 0) {
            currentDivisor *= i;
            currentNumber /= i;
        }

        if (currentDivisor > 1) {
            result.push_back(currentDivisor);
        }

        if (currentNumber == 1) {
            break;
        }
    }

    return result;
}

void computeSubsets(set<long long> usedDivisors, long long currentDivisor, long long a, long long b, vector<long long> &divisors, long long l, long long r, set<long long> &result) {
    auto ai = a * currentDivisor;
    auto bi = b / currentDivisor;

    if (ai >= l && ai <= r && bi >= l && bi <= r) {
        result.insert(ai);
    }

    for (const auto &v: divisors) {
        if (usedDivisors.find(v) == usedDivisors.end()) {
            usedDivisors.insert(v);
            computeSubsets(usedDivisors, currentDivisor * v, a, b, divisors, l, r, result);
            usedDivisors.erase(v);
        }
    }
}


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long l, r, x, y;

    cin >> l >> r >> x >> y;

    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }

    auto divisors = findAllDivisors(y / x);

    set<long long> usedDivisors;
    set<long long> result;

    computeSubsets(usedDivisors, 1, x, y, divisors, l, r, result);

    cout << result.size() << endl;

    return 0;
}
