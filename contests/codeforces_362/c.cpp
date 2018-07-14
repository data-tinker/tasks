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

long long lca(unordered_map<long long, long long> &weights,long long v, long long u, long long w) {
    long long result = 0;

    while (v != u) {
        if (v > u) {
            result += weights[v];
            weights[v] += w;
            v /= 2;
        } else {
            result += weights[u];
            weights[u] += w;
            u /= 2;
        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int q, t;
    long long v, u, w;
    unordered_map<long long, long long> weights;

    cin >> q;

    for (size_t i = 0; i < q; ++i) {
        cin >> t >> v >> u;

        if (t == 1) {
            cin >> w;
            lca(weights, v, u, w);
        } else {
            cout << lca(weights, v, u, 0) << endl;
        }
    }

    return 0;
}
