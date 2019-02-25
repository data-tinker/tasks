#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(const vector<int>& T) {
    vector<int> result(T.size());
    stack<pair<int, int>> lowerTemps;

    for (size_t i = 0; i < T.size(); ++i) {
        if (lowerTemps.empty()) {
            lowerTemps.emplace(i, T[i]);
        } else {
            while (!lowerTemps.empty() && lowerTemps.top().second < T[i]) {
                result[lowerTemps.top().first] = i - lowerTemps.top().first;
                lowerTemps.pop();
            }

            lowerTemps.emplace(i, T[i]);
        }
    }

    return result;
}

int main() {
    auto v = dailyTemperatures({73, 74, 75, 71, 69, 72, 76, 73});

    for (auto i : v) {
        cout << i << endl;
    }

    return 0;
}
