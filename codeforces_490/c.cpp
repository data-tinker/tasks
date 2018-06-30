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

    int n, k;
    cin >> n >> k;
    char c;
    vector<char> s(n);
    vector<int> p(26, 0);

    for (size_t i = 0; i < n; ++i) {
        cin >> c;
        s[i] = c;
        auto idx = c - 'a';

        for (size_t j = idx; j < 26; ++j) {
            ++p[j];
        }
    }

    size_t maxIdx = 25;

    for (size_t i = 0; i < 26; ++i) {
        if (p[i] >= k) {
            maxIdx = i;
            if (i > 0) {
                k -= p[i - 1];
            }
            break;
        }
    }

    for (const auto &v: s) {
        auto idx = v - 'a';

        if (idx > maxIdx) {
            cout << v;
        } else if (idx == maxIdx) {
            if (k > 0) {
                --k;
            } else {
                cout << v;
            }
        }
    }

    cout << endl;

    return 0;
}
