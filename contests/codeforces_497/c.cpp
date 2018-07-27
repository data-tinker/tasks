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

    int n, result = 0;
    cin >> n;

    vector<int> a(n);
    queue<int> q;

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (const auto &v: a) {
        if (q.size() > 0 && q.front() < v) {
            q.pop();
            q.push(v);
            ++result;
        } else {
            q.push(v);
        }
    }

    cout << result << endl;

    return 0;
}
