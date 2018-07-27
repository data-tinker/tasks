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

int gcd(int n, int k) {
    while (k) {
        n %= k;
        swap(n, k);
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n, m;
    cin >> n >> m;

    if (m < n - 1) {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<pair<int, int> > edges;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            if (edges.size() == m) {
                break;
            }

            if (gcd(i + 1, j + 1) == 1) {
                edges.emplace_back(i + 1, j + 1);
            }
        }
    }

    if (edges.size() != m) {
        cout << "Impossible" << endl;
        return 0;
    }

    cout << "Possible" << endl;
    for (const auto &edge: edges) {
        cout << edge.first << ' ' << edge.second << endl;
    }

    return 0;
}
