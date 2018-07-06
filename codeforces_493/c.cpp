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


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    long long n, x, y;
    string pattern;
    cin >> n >> x >> y;

    bool zeroSubPattern = false;
    size_t zeroSubPatternCount = 0;

    getline(cin, pattern);
    getline(cin, pattern);

    for (size_t i = 0; i < n; ++i) {
        if (pattern[i] == '0' && !zeroSubPattern) {
            zeroSubPattern = true;
            ++zeroSubPatternCount;
        } else if (pattern[i] == '1' && zeroSubPattern) {
            zeroSubPattern = false;
        }
    }

    if (zeroSubPatternCount == 0) {
        cout << 0 << endl;
    } else {
        cout << (zeroSubPatternCount - 1) * min(x, y) + y << endl;
    }

    return 0;
}
