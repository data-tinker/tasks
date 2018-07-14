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

    int n, m, l, r;
    cin >> n >> m;

    for (size_t i = 0; i < m; ++i) {
        cin >> l >> r;
    }

    for (size_t i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            cout << '1';
        } else {
            cout << '0';
        }
    }

    cout << endl;

    return 0;
}
