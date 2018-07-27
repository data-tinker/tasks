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

    int n, m, result = 0;
    cin >> n >> m;
    vector<int> c(n);
    vector<int> a(m);

    for (size_t i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (size_t i = 0; i < m; ++i) {
        cin >> a[i];
    }

    reverse(a.begin(), a.end());

    for (const auto &v: c) {
        if (!a.empty() && a.back() >= v) {
            a.pop_back();
            ++result;
        }
    }

    cout << result << endl;

    return 0;
}
