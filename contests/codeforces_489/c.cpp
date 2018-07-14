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

const unsigned long long Floor = 1e9 + 7;


unsigned long long binpow(unsigned long long n, unsigned long long p) {
    unsigned long long result = 1;

    while (p) {
        if (p % 2 == 1) {
            result *= n;
            result %= Floor;
        }
        n *= n;
        n %= Floor;
        p /= 2;
    }

    return result;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    unsigned long long x, k;
    cin >> x >> k;

    if (x > Floor) {
        x %= Floor;
    }

    if (x == 0) {
        cout << 0 << endl;
        return 0;
    }

    auto powerOf2 = binpow(2, k);

    cout << (x * powerOf2 * 2 - powerOf2 + 1) % Floor << endl;

    return 0;
}
