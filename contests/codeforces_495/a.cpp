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

    int n, d;
    cin >> n >> d;
    vector<int> x(n);
    unordered_set<int> coordinates;

    for (size_t i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (size_t i = 0; i < n; ++i) {
        int left = x[i] - d;
        int right = x[i] + d;

        bool addLeft = true;
        bool addRight = true;

        for (size_t j = 0; j < n; ++j) {
            if (abs(x[j] - left) < d) {
                addLeft = false;
            }

            if (abs(x[j] - right) < d) {
                addRight = false;
            }
        }

        if (addLeft) {
            coordinates.insert(left);
        }

        if (addRight) {
            coordinates.insert(right);
        }
    }

    cout << coordinates.size() << endl;

    return 0;
}
