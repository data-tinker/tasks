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

bool canFinish(int numCourses, vector<pair<int, int>> prerequisites) {
    vector<vector<int>> graph(numCourses);

    for (const auto & [end, start]: prerequisites) {
        graph[start].push_back(end);
    }

    vector<bool> visited(numCourses, false);

    vector<int> enterTime(numCourses, 0);
    vector<int> exitTime(numCourses, 0);

    stack<pair<int, bool>> processing;
    int timer = 0;

//    for (size_t i = 0; i < numCourses; ++i) {
//        cout << i << ' ';
//        for (auto el: graph[i]) {
//            cout << el << ' ';
//        }
//        cout << endl;
//    }

    for (size_t i = 0; i < numCourses; ++i) {
        if (!visited[i]) {
            processing.emplace(i, true);

            while (!processing.empty()) {
                auto [v, enter] = processing.top();
                processing.pop();

                if (visited[v]) {
                    if (!enter) {
                        exitTime[v] = ++timer;
                    }
                    continue;
                }

                visited[v] = true;
                enterTime[v] = ++timer;

                processing.emplace(v, false);

                for (auto nb: graph[v]) {
                    if (!visited[nb]) {
                        processing.emplace(nb, true);
                    }
                }
            }
        }
    }

//    for (size_t i = 0; i < numCourses; ++i) {
//        cout << i << ' ' << enterTime[i] << ' ' << exitTime[i] << endl;
//    }

    for (const auto & [end, start]: prerequisites) {
        if (exitTime[start] < exitTime[end]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);

    int numCourses, n, a, b;
    cin >> numCourses >> n;
    vector<pair<int, int>> prerequisites;

    for (size_t i = 0; i < n; ++i) {
        cin >> a >> b;
        prerequisites.emplace_back(a, b);
    }

    cout << canFinish(numCourses, prerequisites) << endl;

    return 0;
}
