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


int carFleet(int target, const vector<int>& position, const vector<int>& speed) {
    size_t n = position.size();
    vector<pair<int, int>> cars;

    for (size_t i = 0; i < n; ++i) {
        cars.emplace_back(position[i], speed[i]);
    }

    sort(begin(cars), end(cars), greater<pair<int, int>>());

    deque<double> times;

    int ans = 0;

    for (size_t i = 0; i < n; ++i) {
        times.push_back((double)(target - cars[i].first) / cars[i].second);
    }

    while (times.size() > 1) {
        double f = times.front();
        times.pop_front();

        if (times.front() > f) {
            ++ans;
        } else {
            times.pop_front();
            times.push_front(f);
        }
    }

    return ans + times.size();
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    cout << carFleet(10, {6,8}, {3,2}) << endl;

    return 0;
}
