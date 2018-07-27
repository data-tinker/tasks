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

long long arithmeticProgressionSum(long long n) {
    return n * (n + 1) / 2;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long n, m, x, d, result = 0;
    cin >> n >> m;

    for (size_t i = 0; i < m; ++i) {
        cin >> x >> d;

        result += x * n;
        if (d > 0) {
            result += d * arithmeticProgressionSum(n - 1);
        } else {
            result += d * (arithmeticProgressionSum((n - 1) / 2) + arithmeticProgressionSum((n - 1) - (n - 1) / 2));
        }
    }

    cout << static_cast<double>(result) / n << endl;

    return 0;
}
