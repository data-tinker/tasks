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

    int n;
    cin >> n;
    vector<int> a(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int minElement = numeric_limits<int>::max();
    size_t minElementIdx = 0;

    int maxElement = numeric_limits<int>::min();
    size_t maxElementIdx = 0;

    for (size_t i = 0; i < n; ++i) {
        if (a[i] < minElement) {
            minElement = a[i];
            minElementIdx = i;
        }  else if (a[i] > maxElementIdx) {
            maxElement = a[i];
            maxElementIdx = i;
        }
    }

    if (n < 2) {
        cout << -1 << endl;
    } else if (n == 2) {
        if (minElement == maxElement) {
            cout << -1 << endl;
        } else {
            cout << 1 << endl;
            cout << minElementIdx + 1 << endl;
        }
    } else {
        cout << 1 << endl;
        cout << minElementIdx + 1 << endl;
    }

    return 0;
}
