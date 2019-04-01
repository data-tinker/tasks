#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
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

vector<pair<int, int>> getSkyline(vector<vector<int>>&& buildings) {
    vector<pair<int, int>> landscape;
    multiset<int, greater<int>> heights;

    for (const auto& b: buildings) {
        landscape.emplace_back(b[0], b[2]);
        landscape.emplace_back(b[1], -b[2]);
    }

    sort(begin(landscape), end(landscape));
    vector<pair<int, int>> result;

    for (const auto& [pos, height]: landscape) {
        if (height > 0) {
            heights.insert(height);
        } else {
            heights.erase(-height);
        }

        int value = 0;

        if (heights.size() > 0) {
            value = *heights.begin();
        }

//        if (result.size() > 0 && result.back().second == value) {
//            continue;
//        }

        result.emplace_back(pos, value);
    }

    int prevPos = 0;

    for (const auto& [pos, height]: landscape) {
        if (pos == prevPos) {

        }
    }

    return result;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    auto skyline = getSkyline({{0,2,3},{2,5,3}});

    for (const auto& [pos, height]: skyline) {
        cout << pos << ' ' << height << endl;
    }

    return 0;
}
