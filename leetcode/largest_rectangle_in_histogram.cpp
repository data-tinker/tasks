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

int largestRectangleArea(const vector<int>& heights) {
    if (heights.empty()) {
        return 0;
    }

    stack<int> s;
    int result = numeric_limits<int>::min();

    for (size_t i = 0; i < heights.size(); ++i) {
        if (s.empty()) {
            s.push(i);
        } else {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                auto t = s.top();
                s.pop();

                result = max(result, heights[t] * (int)(s.empty() ? i : i - s.top() - 1));
            }
            s.push(i);
        }
    }

    while (!s.empty()) {
        auto t = s.top();
        s.pop();

        result = max(result, heights[t] * (int)(s.empty() ? heights.size() : heights.size() - s.top() - 1));
    }

    return result;
}


int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    cout << largestRectangleArea({2, 1, 5, 6, 2, 3}) << endl;

    return 0;
}
