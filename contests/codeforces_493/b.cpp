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

    int n, b, prefixEvenNumbers = 0, prefixOddNumbers = 0, result = 0;
    cin >> n >> b;
    vector<int> a(n);
    vector<int> costs;

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (size_t i = 0; i < n; ++i) {
        if (i > 0 && prefixOddNumbers == prefixEvenNumbers) {
            costs.push_back(abs(a[i] - a[i - 1]));
        }

        if (a[i] % 2 == 0) {
            ++prefixEvenNumbers;
        } else {
            ++prefixOddNumbers;
        }
    }

    sort(costs.begin(), costs.end());

    for (size_t i = 0; i < costs.size(); ++i) {
        if (b - costs[i] >= 0) {
            b -= costs[i];
            ++result;
        } else {
            break;
        }
    }

    cout << result << endl;

    return 0;
}
