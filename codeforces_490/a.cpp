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

    int n, k, result = 0;
    cin >> n >> k;
    vector<int> a(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    size_t l = 0, r = n - 1;

    while (a[l] <= k && l < n) {
        ++result;
        ++l;
    }

    while (a[r] <= k && r >= l) {
        ++result;
        --r;
    }

    cout << result << endl;

    return 0;
}
