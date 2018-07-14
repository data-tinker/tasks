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

    int n, v;
    cin >> n;
    unordered_set<int> s;

    for (size_t i = 0; i < n; ++i) {
        cin >> v;
        if (v != 0) {
            s.insert(v);
        }
    }

    cout << s.size() << endl;

    return 0;
}
