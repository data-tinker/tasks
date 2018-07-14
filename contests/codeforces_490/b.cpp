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

vector<int> computeDivisors(int number) {
    vector<int> divisors;

    for (size_t i = 1; i <= std::sqrt(number); ++i) {
        if (number % i == 0) {
            if (number / i == i) {
                divisors.push_back(i);
            } else {
                divisors.push_back(i);
                divisors.push_back(number / i);
            }
        }
    }

    return divisors;
}

void shiftString(vector<char> &String, int d) {
    int l = 0;
    int r = d - 1;

    while (l < r) {
        swap(String[l++], String[r--]);
    }
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int n;
    cin >> n;

    vector<char> t(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> t[i];
    }

    auto divisors = computeDivisors(n);
    sort(begin(divisors), end(divisors));

    for (const auto &d: divisors) {
        shiftString(t, d);
    }

    for (const auto &v: t) {
        cout << v;
    }

    cout << endl;

    return 0;
}
